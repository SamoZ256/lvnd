#include "lvnd/cocoa/cocoa_init.h"

#import <Cocoa/Cocoa.h>

#include "lvnd/context.h"

@interface NSLvndMenuItem : NSMenuItem {
    void (*pfnAction)(void);
}

- (id) initWithTitle:(NSString *)aString action:(SEL)aSelector keyEquivalent:(NSString *)charCode userAction:(void (*)(void))aPfnAction;

- (void) clickedAction: (id) sender;

@end

@implementation NSLvndMenuItem

- (id) initWithTitle:(NSString *)aString action:(SEL)aSelector keyEquivalent:(NSString *)charCode userAction:(void (*)(void))aPfnAction {
    self = [super initWithTitle:aString action:aSelector keyEquivalent:charCode];
    pfnAction = aPfnAction;

    return self;
}

- (void) clickedAction: (id) sender {
    if (pfnAction != NULL) {
        pfnAction();
    }
}

@end

//Helpers

void _cocoa_lvndCreateMenu(NSMenu* bar, LvndMenu* menu) {
    NSMenuItem* customMenuItem = [bar addItemWithTitle:@(menu->title) action:NULL keyEquivalent:@""];
    NSMenu* customMenu = [[NSMenu alloc] initWithTitle:@(menu->title)];
    [customMenuItem setSubmenu:customMenu];

    for (uint16_t j = 0; j < menu->menuItems->size; j++) {
        LvndMenuItemType itemType = (LvndMenuItemType)lvndVectorGet(menu->menuItemTypes, j);
        if (itemType == LVND_MENU_ITEM_TYPE_ITEM) {
            LvndMenuItem* menuItem = lvndVectorGet(menu->menuItems, j);
            NSLvndMenuItem* crntItem = [[NSLvndMenuItem alloc] initWithTitle:@(menuItem->title)
                                                            action:@selector(menuItemClicked:)
                                                            keyEquivalent:@(menuItem->keyBinding)
                                                            userAction:menuItem->action];
            [customMenu addItem:crntItem];
        } else if (itemType == LVND_MENU_ITEM_TYPE_SEPARATOR) {
            [customMenu addItem:[NSMenuItem separatorItem]];
        } else if (itemType == LVND_MENU_ITEM_TYPE_MENU) {
            LvndMenu* newMenu = lvndVectorGet(menu->menuItems, j);
            _cocoa_lvndCreateMenu(customMenu, newMenu);
        }
    }
}

void _cocoa_lvndCreateMenuBar() {
    NSString* appName = @"My App";

    NSMenu* bar = [[NSMenu alloc] init];
    [NSApp setMainMenu:bar];

    NSMenuItem* appMenuItem =
        [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* appMenu = [[NSMenu alloc] init];
    [appMenuItem setSubmenu:appMenu];

    [appMenu addItemWithTitle:[NSString stringWithFormat:@"About %@", appName]
                       action:@selector(orderFrontStandardAboutPanel:)
                keyEquivalent:@""];
    [appMenu addItem:[NSMenuItem separatorItem]];
    NSMenu* servicesMenu = [[NSMenu alloc] init];
    [NSApp setServicesMenu:servicesMenu];
    [[appMenu addItemWithTitle:@"Services"
                       action:NULL
                keyEquivalent:@""] setSubmenu:servicesMenu];
    [servicesMenu release];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [appMenu addItemWithTitle:[NSString stringWithFormat:@"Hide %@", appName]
                       action:@selector(hide:)
                keyEquivalent:@"h"];
    [[appMenu addItemWithTitle:@"Hide Others"
                       action:@selector(hideOtherApplications:)
                keyEquivalent:@"h"]
        setKeyEquivalentModifierMask:NSEventModifierFlagOption | NSEventModifierFlagCommand];
    [appMenu addItemWithTitle:@"Show All"
                       action:@selector(unhideAllApplications:)
                keyEquivalent:@""];
    [appMenu addItem:[NSMenuItem separatorItem]];
    [appMenu addItemWithTitle:[NSString stringWithFormat:@"Quit %@", appName]
                       action:@selector(terminate:)
                keyEquivalent:@"q"];

    NSMenuItem* windowMenuItem =
        [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
    NSMenu* windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
    [NSApp setWindowsMenu:windowMenu];
    [windowMenuItem setSubmenu:windowMenu];

    [windowMenu addItemWithTitle:@"Minimize"
                          action:@selector(performMiniaturize:)
                   keyEquivalent:@"m"];
    [windowMenu addItemWithTitle:@"Zoom"
                          action:@selector(performZoom:)
                   keyEquivalent:@""];
    [windowMenu addItem:[NSMenuItem separatorItem]];
    [windowMenu addItemWithTitle:@"Bring All to Front"
                          action:@selector(arrangeInFront:)
                   keyEquivalent:@""];
    
    if (g_lvndContext.globalMenuBar != NULL) {
        //NSLog(@"Creating custom menu bar");

        for (uint16_t i = 0; i < g_lvndContext.globalMenuBar->menus->size; i++) {
            LvndMenu* menu = lvndVectorGet(g_lvndContext.globalMenuBar->menus, i);
            _cocoa_lvndCreateMenu(bar, menu);
        }
    }
    
    [bar release];

    // Prior to Snow Leopard, we need to use this oddly-named semi-private API
    // to get the application menu working properly.
    SEL setAppleMenuSelector = NSSelectorFromString(@"setAppleMenu:");
    [NSApp performSelector:setAppleMenuSelector withObject:appMenu];
}

//Application Delegate

@interface LvndApplicationDelegate : NSObject <NSApplicationDelegate> {
    
}

- (void) menuItemClicked:(id) sender;

@end

@implementation LvndApplicationDelegate

- (void) menuItemClicked:(id) sender {
    [(NSLvndMenuItem*)sender clickedAction:sender];
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender {
    NSLog(@"Closing");

    return NSTerminateCancel;
}

- (void)applicationDidChangeScreenParameters:(NSNotification *) notification {
    NSLog(@"Changed screen parameters");
}

- (void)applicationWillFinishLaunching:(NSNotification *)notification {
    //NSLog(@"Creating menu bar");
    _cocoa_lvndCreateMenuBar();
    //NSLog(@"Created menu bar");
}

- (void)applicationDidFinishLaunching:(NSNotification *)notification {
    //NSLog(@"Stopping");
    [NSApp stop:nil];
}

- (void)applicationDidHide:(NSNotification *)notification {
    NSLog(@"App is hidden");
}

@end

@interface LvndHelper : NSObject
@end

@implementation LvndHelper

- (void)selectedKeyboardInputSourceChanged:(NSObject* )object {
    NSLog(@"Blah blah");
}

- (void)doNothing:(id)object {
}

@end

void cocoa_lvndInit() {
    //Application
    LvndHelper* helper = [[LvndHelper alloc] init];
    
    [NSThread detachNewThreadSelector:@selector(doNothing:)
                             toTarget:helper
                           withObject:nil];

    [NSApplication sharedApplication];

    id appDelegate = [[LvndApplicationDelegate alloc] init];
    [NSApp setDelegate:appDelegate];

    NSEvent* (^block)(NSEvent*) = ^ NSEvent* (NSEvent* event)
    {
        if ([event modifierFlags] & NSEventModifierFlagCommand)
            [[NSApp keyWindow] sendEvent:event];

        return event;
    };

    [[NSNotificationCenter defaultCenter]
        addObserver:helper
           selector:@selector(selectedKeyboardInputSourceChanged:)
               name:NSTextInputContextKeyboardSelectionDidChangeNotification
             object:nil];
    
    CGEventSourceSetLocalEventsSuppressionInterval(CGEventSourceCreate(kCGEventSourceStateHIDSystemState), 0.0);

    //if (![[NSRunningApplication currentApplication] isFinishedLaunching])
    //    [NSApp run];
    
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
}
