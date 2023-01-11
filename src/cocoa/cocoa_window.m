#include "lvnd/cocoa/cocoa_window.h"

#include <mach/mach_time.h>

#import <Cocoa/Cocoa.h>

#include "lvnd/common.h"

#include "lvnd/cocoa/cocoa_key_bindings.h"

#define PROCESS_MODIFIERS(modifiers, flags) \
modifiers = 0; \
if (flags & NSEventModifierFlagShift) \
    modifiers |= LVND_MODIFIER_SHIFT; \
if (flags & NSEventModifierFlagControl) \
    modifiers |= LVND_MODIFIER_CONTROL; \
if (flags & NSEventModifierFlagOption) \
    modifiers |= LVND_MODIFIER_ALT; \
if (flags & NSEventModifierFlagCommand) \
    modifiers |= LVND_MODIFIER_SUPER; \
if (flags & NSEventModifierFlagCapsLock) \
    modifiers |= LVND_MODIFIER_CAPS_LOCK;

static const NSRange nsEmptyRange = { NSNotFound, 0 };

//Helpers
LvndKey translateKeyNSToLvnd(uint16_t nsKey) {
    LvndKey key = KeyNSToLvndBindings[nsKey];
    //NSLog(@"Key code %u : %hu", key, nsKey);

    return key;
}

//Window Delegate

@interface LvndWindowDelegate : NSObject {
    LvndWindow* window;
    bool initFocusFinished;
}

- (instancetype)initWithWindow:(LvndWindow*)initWindow;

@end

@implementation LvndWindowDelegate

- (instancetype)initWithWindow:(LvndWindow*)initWindow {
    self = [super init];
    if (self != nil) {
        window = initWindow;
        initFocusFinished = false;
    }

    return self;
}

- (BOOL)windowShouldClose:(id)sender {
    window->isOpen = false;

    return NO;
}

- (void)windowDidResize:(NSNotification *)notification {
    const NSRect contentRect = [(id)window->handle->view frame];
    const NSRect fbRect = [(id)window->handle->view convertRectToBacking:contentRect];

    if (window->width != contentRect.size.width || window->height != contentRect.size.height) {
        window->width = contentRect.size.width;
        window->height = contentRect.size.height;

        window->framebufferWidth = fbRect.size.width;
        window->framebufferHeight = fbRect.size.height;

        if (window->callbacks.windowResizeCallback != NULL) {
            //NSLog(@"Window resize 1");
            window->callbacks.windowResizeCallback(window, window->width, window->height);
            //NSLog(@"Window resize 2");
        }

        //NSLog(@"Resized: %d, %d", window->width, window->height);
    }

    bool isMaximized = [(id)window->handle->window isZoomed];
    if (window->isMaximized != isMaximized) {
        window->isMaximized = isMaximized;
        //TODO: implement maximize callback
    }

    //if (window->framebufferWidth != fbRect.size.width || window->framebufferHeight != fbRect.size.height) {
    //}

    //NSLog(@"Resize event");
}

- (void)windowDidMove:(NSNotification*)notification {
    
}

- (void)windowDidMiniaturize:(NSNotification*)notification {
    
}

- (void)windowDidDeminiaturize:(NSNotification*)notification {
    
}

- (void)windowDidBecomeKey:(NSNotification*)notification {
    if (window->callbacks.windowFocusCallback != NULL) {
        //NSLog(@"Window focus 1");
        if (initFocusFinished)
            window->callbacks.windowFocusCallback(window, true);
        initFocusFinished = true;
        //NSLog(@"Window focus 2");
    }
}

- (void)windowDidResignKey:(NSNotification*)notification {
    if (window->callbacks.windowFocusCallback != NULL) {
        //NSLog(@"Window focus 1");
        window->callbacks.windowFocusCallback(window, false);
        //NSLog(@"Window focus 2");
    }
}

- (void)windowDidChangeOcclusionState:(NSNotification*)notification {
    if ([(id)window->handle->window occlusionState] & NSWindowOcclusionStateVisible)
        window->handle->isOccluded = true;
    else
        window->handle->isOccluded = false;
}

@end

//View

@interface LvndContentView : NSView <NSTextInputClient> {
    LvndWindow* window;
    NSTrackingArea* trackingArea;
    NSMutableAttributedString* markedText;
}

- (instancetype)initWithWindow:(LvndWindow*)initWindow;

@end

@implementation LvndContentView

- (instancetype)initWithWindow:(LvndWindow*)initWindow {
    self = [super init];
    if (self != nil) {
        window = initWindow;
        trackingArea = nil;
        markedText = [[NSMutableAttributedString alloc] init];

        [self updateTrackingAreas];
        [self registerForDraggedTypes:@[NSPasteboardTypeURL]];
    }

    return self;
}

- (void)dealloc {
    [trackingArea release];
    [markedText release];
    [super dealloc];
}

- (BOOL)isOpaque {
    return YES;
}

- (BOOL)canBecomeKeyView {
    return YES;
}

- (BOOL)acceptsFirstResponder {
    return YES;
}

- (BOOL)wantsUpdateLayer {
    return YES;
}

- (void)updateLayer {
    
}

- (void)cursorUpdate:(NSEvent*)event {
    
}

- (BOOL)acceptsFirstMouse:(NSEvent*)event {
    return YES;
}

- (void)mouseDown:(NSEvent*)event {
    window->mouseButtons[LVND_MOUSE_BUTTON_LEFT] = LVND_STATE_PRESSED;

    if (window->callbacks.mouseButtonPressedCallback != NULL) {
        //NSLog(@"Mouse button pressed 1");
        window->callbacks.mouseButtonPressedCallback(window, LVND_MOUSE_BUTTON_LEFT, LVND_STATE_PRESSED);
        //NSLog(@"Mouse button pressed 2");
    }
}

- (void)mouseDragged:(NSEvent*)event {
    [self mouseMoved:event];
}

- (void)mouseUp:(NSEvent*)event {
    window->mouseButtons[LVND_MOUSE_BUTTON_LEFT] = LVND_STATE_RELEASED;

    if (window->callbacks.mouseButtonPressedCallback != NULL) {
        //NSLog(@"Mouse button pressed 1");
        window->callbacks.mouseButtonPressedCallback(window, LVND_MOUSE_BUTTON_LEFT, LVND_STATE_RELEASED);
        //NSLog(@"Mouse button pressed 2");
    }
}

- (void)mouseMoved:(NSEvent*)event {
    const NSPoint pos = [event locationInWindow];
    window->mouseX = pos.x;
    window->mouseY = pos.y;

    if (window->callbacks.cursorMovedCallback != NULL) {
        //NSLog(@"Cursor moved 1");
        window->callbacks.cursorMovedCallback(window, window->mouseX, window->mouseY);
        //NSLog(@"Cursor moved 2");
    }
}

- (void)rightMouseDown:(NSEvent*)event {
    window->mouseButtons[LVND_MOUSE_BUTTON_RIGHT] = LVND_STATE_PRESSED;

    if (window->callbacks.mouseButtonPressedCallback != NULL) {
        //NSLog(@"Mouse button pressed 1");
        window->callbacks.mouseButtonPressedCallback(window, LVND_MOUSE_BUTTON_RIGHT, LVND_STATE_PRESSED);
        //NSLog(@"Mouse button pressed 2");
    }
}

- (void)rightMouseDragged:(NSEvent*)event {
    [self mouseMoved:event];
}

- (void)rightMouseUp:(NSEvent*)event {
    window->mouseButtons[LVND_MOUSE_BUTTON_RIGHT] = LVND_STATE_RELEASED;

    if (window->callbacks.mouseButtonPressedCallback != NULL) {
        //NSLog(@"Mouse button pressed 1");
        window->callbacks.mouseButtonPressedCallback(window, LVND_MOUSE_BUTTON_RIGHT, LVND_STATE_RELEASED);
        //NSLog(@"Mouse button pressed 2");
    }
}

- (void)otherMouseDown:(NSEvent*)event {
    
}

- (void)otherMouseDragged:(NSEvent*)event
{
    [self mouseMoved:event];
}

- (void)otherMouseUp:(NSEvent*)event {
    
}

- (void)mouseExited:(NSEvent*)event {
    if (window->callbacks.cursorEnteredCallback != NULL) {
        //NSLog(@"Cursor entered 1");
        window->callbacks.cursorEnteredCallback(window, false);
        //NSLog(@"Cursor entered 2");
    }
}

- (void)mouseEntered:(NSEvent*)event {
    if (window->callbacks.cursorEnteredCallback != NULL) {
        //NSLog(@"Cursor entered 1");
        window->callbacks.cursorEnteredCallback(window, true);
        //NSLog(@"Cursor entered 2");
    }
}

- (void)viewDidChangeBackingProperties {
    const NSRect contentRect = [(id)window->handle->view frame];
    const NSRect fbRect = [(id)window->handle->view convertRectToBacking:contentRect];
    window->framebufferScaleX = fbRect.size.width / contentRect.size.width;
    window->framebufferScaleY = fbRect.size.height / contentRect.size.height;
}

- (void)drawRect:(NSRect)rect {
    
}

- (void)updateTrackingAreas {
    if (trackingArea != nil) {
        [self removeTrackingArea:trackingArea];
        [trackingArea release];
    }

    const NSTrackingAreaOptions options = NSTrackingMouseEnteredAndExited |
                                          NSTrackingActiveInKeyWindow |
                                          NSTrackingEnabledDuringMouseDrag |
                                          NSTrackingCursorUpdate |
                                          NSTrackingInVisibleRect |
                                          NSTrackingAssumeInside;

    trackingArea = [[NSTrackingArea alloc] initWithRect:[self bounds]
                                                options:options
                                                  owner:self
                                               userInfo:nil];

    [self addTrackingArea:trackingArea];
    [super updateTrackingAreas];
}

- (void)keyDown:(NSEvent *)event {
    LvndKey key = translateKeyNSToLvnd([event keyCode]);
    window->keys[key] = LVND_STATE_PRESSED;
    /*
    NSUInteger flags = [event modifierFlags];
    if (flags & NSEventModifierFlagShift)
        NSLog(@"Shift pressed in obj-c");

    PROCESS_MODIFIERS(flags, LVND_STATE_PRESSED)
    */

    if (window->callbacks.keyPressedCallback != NULL) {
        //NSLog(@"Key pressed 1");
        window->callbacks.keyPressedCallback(window, key, LVND_STATE_PRESSED);
        //NSLog(@"Key pressed 2");
    }

    [self interpretKeyEvents:@[event]];
}

- (void)flagsChanged:(NSEvent *)event {
    //const NSUInteger flags = [event modifierFlags];
    const uint16_t nsKey = [event keyCode];
    //if (flags & NSEventModifierFlagShift)
    //    NSLog(@"Shift pressed in obj-c");
    //NSLog(@"Flags changed %hu", key);

    //if (flags & key) {
    //NSLog(@"Mod key pressed: %u", translateKeyNSToLvnd(key));
    LvndKey key = translateKeyNSToLvnd(nsKey);
    if (window->keys[key] == LVND_STATE_PRESSED)
        window->keys[key] = LVND_STATE_RELEASED;
    else
        window->keys[key] = LVND_STATE_PRESSED;
    //}

    PROCESS_MODIFIERS(window->modifiers, [event modifierFlags]);
}

- (void)keyUp:(NSEvent*)event {
    LvndKey key = translateKeyNSToLvnd([event keyCode]);
    window->keys[key] = LVND_STATE_RELEASED;
    /*
    NSUInteger flags = [event modifierFlags];

    PROCESS_MODIFIERS(flags, LVND_STATE_RELEASED)
    */

    if (window->callbacks.keyPressedCallback != NULL) {
        //NSLog(@"Key pressed 1");
        window->callbacks.keyPressedCallback(window, key, LVND_STATE_RELEASED);
        //NSLog(@"Key pressed 2");
    }
}

- (void)scrollWheel:(NSEvent*)event {
    if (window->callbacks.scrollCallback != NULL) {
        //NSLog(@"Key pressed 1");
        window->callbacks.scrollCallback(window, [event scrollingDeltaX], [event scrollingDeltaY]);
        //NSLog(@"Key pressed 2");
    }
}

- (NSDragOperation)draggingEntered:(id <NSDraggingInfo>)sender {
    return NSDragOperationGeneric;
}

- (BOOL)performDragOperation:(id <NSDraggingInfo>)sender {
    return YES;
}

- (BOOL)hasMarkedText {
    return [markedText length] > 0;
}

- (NSRange)markedRange {
    if ([markedText length] > 0)
        return NSMakeRange(0, [markedText length] - 1);
    else
        return nsEmptyRange;
}

- (NSRange)selectedRange {
    return nsEmptyRange;
}

- (void)setMarkedText:(id)string
        selectedRange:(NSRange)selectedRange
     replacementRange:(NSRange)replacementRange {
    [markedText release];
    if ([string isKindOfClass:[NSAttributedString class]])
        markedText = [[NSMutableAttributedString alloc] initWithAttributedString:string];
    else
        markedText = [[NSMutableAttributedString alloc] initWithString:string];
}

- (void)unmarkText {
    [[markedText mutableString] setString:@""];
}

- (NSArray*)validAttributesForMarkedText {
    return [NSArray array];
}

- (NSAttributedString*)attributedSubstringForProposedRange:(NSRange)range
                                               actualRange:(NSRangePointer)actualRange {
    return nil;
}

- (NSUInteger)characterIndexForPoint:(NSPoint)point {
    return 0;
}

- (NSRect)firstRectForCharacterRange:(NSRange)range
                         actualRange:(NSRangePointer)actualRange {
    const NSRect frame = [(id)window->handle->view frame];
    return NSMakeRect(frame.origin.x, frame.origin.y, 0.0, 0.0);
}

- (void)insertText:(id)string replacementRange:(NSRange)replacementRange {
    NSString* characters;
    NSEvent* event = [NSApp currentEvent];
    uint16_t mods;
    PROCESS_MODIFIERS(mods, [event modifierFlags]);
    const int plain = !(mods & LVND_MODIFIER_SUPER);

    if ([string isKindOfClass:[NSAttributedString class]])
        characters = [string string];
    else
        characters = (NSString*) string;

    NSRange range = NSMakeRange(0, [characters length]);
    while (range.length) {
        uint32_t codepoint = 0;

        if ([characters getBytes:&codepoint
                       maxLength:sizeof(codepoint)
                      usedLength:NULL
                        encoding:NSUTF32StringEncoding
                         options:0
                           range:range
                  remainingRange:&range])
        {
            if (codepoint >= 0xf700 && codepoint <= 0xf7ff)
                continue;

            //_glfwInputChar(window, codepoint, mods, plain);
            if (window->callbacks.charCallback != NULL)
                window->callbacks.charCallback(window, codepoint);
        }
    }
}

- (void)doCommandBySelector:(SEL)selector {

}

@end

//Window Object

@interface LvndWindowObj : NSWindow {}
@end

@implementation LvndWindowObj

- (BOOL)canBecomeKeyWindow {
    //NSLog(@"Key");

    // Required for NSWindowStyleMaskBorderless windows
    return YES;
}

- (BOOL)canBecomeMainWindow {
    //NSLog(@"Main");

    return YES;
}

@end

//Definitions

void cocoa_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title) {
    window->handle = (Cocoa_LvndWindowHandle*)malloc(sizeof(Cocoa_LvndWindowHandle));

    //Occluded
    window->handle->isOccluded = false;

    //Frequency //TODO: move this to other APIs as well
    mach_timebase_info_data_t timeInfo;
    mach_timebase_info(&timeInfo);
    window->handle->frequency = (timeInfo.denom * 1e9) / timeInfo.numer;

    window->handle->appDelegate = [NSApp delegate];
    if (window->handle->appDelegate == NULL) {
        LVND_ERROR("Failed to create NS application delegate");
    }

    //Window
    window->handle->windowDelegate = [[LvndWindowDelegate alloc] initWithWindow:window];
    if (window->handle->windowDelegate == NULL) {
        LVND_ERROR("Failed to create NS window delegate");
    }

    NSRect contentRect;

    contentRect = NSMakeRect(0, 0, width, height);

    NSUInteger styleMask = NSWindowStyleMaskMiniaturizable;

    styleMask |= (NSWindowStyleMaskTitled | NSWindowStyleMaskClosable);

    styleMask |= NSWindowStyleMaskResizable;

    window->handle->window = [[LvndWindowObj alloc]
        initWithContentRect:contentRect
                  styleMask:styleMask
                    backing:NSBackingStoreBuffered
                      defer:NO];
    if (window->handle->window == NULL) {
        LVND_ERROR("Failed to create NS window");
    }
    
    [(NSWindow*)window->handle->window center];

    const NSWindowCollectionBehavior behavior =
        NSWindowCollectionBehaviorFullScreenPrimary |
        NSWindowCollectionBehaviorManaged;
    [(id)window->handle->window setCollectionBehavior:behavior];

    window->handle->view = [[LvndContentView alloc] initWithWindow:window];
    if (window->handle->view == NULL) {
        LVND_ERROR("Failed to create NS view");
    }

    [(id)window->handle->window setContentView:window->handle->view];
    [(id)window->handle->window makeFirstResponder:window->handle->view];
    [(id)window->handle->window setTitle:@(title)];
    [(id)window->handle->window setDelegate:window->handle->windowDelegate];
    [(id)window->handle->window setAcceptsMouseMovedEvents:YES];
    [(id)window->handle->window setRestorable:NO];

    [NSApp activateIgnoringOtherApps:YES];
    [(id)window->handle->window makeKeyAndOrderFront:window->handle->view];

    //Getting some properties
    const NSRect fbRect = [(id)window->handle->view convertRectToBacking:contentRect];
    window->framebufferWidth = fbRect.size.width;
    window->framebufferHeight = fbRect.size.height;

    //Retina
    if (window->width == window->framebufferWidth && window->height == window->framebufferHeight)
        window->handle->isRetina = false;
    else
        window->handle->isRetina = true;
    
    const NSPoint mousePos = [(id)window->handle->window mouseLocationOutsideOfEventStream];
    window->mouseX = mousePos.x;
    window->mouseY = mousePos.y;

    //[app setDelegate:handle->delegate];

    //[(id)window->handle->window orderFrontRegardless];
    [NSApp run];

    //_lvndCreateMenuBar();
}

void cocoa_lvndDestroyWindow(LvndWindow* window) {
    [(id)window->handle->appDelegate release];
    [(id)window->handle->window release];
    [(id)window->handle->windowDelegate release];
    [(id)window->handle->view release];
}

void cocoa_lvndPollEvents() {
    @autoreleasepool {
    
    for (;;) {
        NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                            untilDate:[NSDate distantPast]
                                               inMode:NSDefaultRunLoopMode
                                              dequeue:YES];
        if (event == nil)
            break;

        [NSApp sendEvent:event];
    }

    } // autoreleasepool
}

void cocoa_lvndSetWindowTitle(LvndWindow* window, const char* title) {
    [(id)window->handle->window setTitle:@(title)];
}

void cocoa_lvndWindowSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY) {
    const NSRect contentRect = [(id)window->handle->view frame];
    const NSRect localRect = NSMakeRect(mouseX, contentRect.size.height - mouseY - 1, 0, 0);
    const NSRect globalRect = [(id)window->handle->window convertRectToScreen:localRect];

    //NSLog(@"Setting mouse to %f, %f", mouseX, mouseY);
    CGWarpMouseCursorPosition(CGPointMake(globalRect.origin.x, CGDisplayBounds(CGMainDisplayID()).size.height - globalRect.origin.y - 1));
    //NSLog(@"Device coords: %f, %f", globalRect.origin.x, CGDisplayBounds(CGMainDisplayID()).size.height - globalRect.origin.y - 1);
    CGAssociateMouseAndMouseCursorPosition(true);

    window->mouseX = mouseX;
    window->mouseY = mouseY;
}

void cocoa_lvndSetCursorState(LvndWindow* window, LvndCursorState state) {
    if (state == LVND_CURSOR_STATE_NORMAL) {
        if (window->cursorState != LVND_CURSOR_STATE_NORMAL) {
            //NSLog(@"Setting cursor state to normal");
            if (window->cursorState == LVND_CURSOR_STATE_HIDDEN) {
                [NSCursor unhide];
            }
            window->cursorState = LVND_CURSOR_STATE_NORMAL;
        }
    } else if (state == LVND_CURSOR_STATE_HIDDEN) {
        if (window->cursorState != LVND_CURSOR_STATE_HIDDEN) {
            //NSLog(@"Setting cursor state to hidden");
            if (window->cursorState == LVND_CURSOR_STATE_NORMAL) {
                [NSCursor hide];
            }
            window->cursorState = LVND_CURSOR_STATE_HIDDEN;
        }
    }
}

void cocoa_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen) {
    @autoreleasepool {
    
    //TODO: replace this with checking if app is already zoomed
    if (fullscreen)
        [(id)window->handle->window zoom:nil];//[(id)window->handle->window toggleFullScreen];
    else
        ; //TODO: implement this
    
    }
}

//Cross-platform main loop
int cocoa_lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void)) {
    if (start != NULL)
        start();

    while (window->isOpen) {
        cocoa_lvndPollEvents();

        if (updateFrame != NULL)
            updateFrame();
    }

    return 0;
}
