#include "lvnd/uikit/uikit_window.h"

#import <UIKit/UIKit.h>

#include "lvnd/context.h"
#include "lvnd/uikit/uikit_platform_data.h"

#import "lvnd/uikit/uikit_view_controller.h"

//View
/*
@interface UIKit_LvndView : UIView {
    
}

@end

@implementation UIKit_LvndView

- (instancetype)init {
    self = [super init];
    //NSLog(@"Creating custom view");
    
    return self;
}

- (void)drawRect:(CGRect)rect {
    NSLog(@"Drawing");
}

@end
*/

//View controller
@implementation UIKit_LvndViewController

/*
- (void)loadView {
    self.view = [[UIView alloc] init];
}
 */

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    //window = g_lvndContext.platformData;
    timer = [CADisplayLink displayLinkWithTarget:self selector:@selector(updateFrame)];
    [timer addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
}

- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    UIKit_LvndPlatformData* platformData = (UIKit_LvndPlatformData*)(g_lvndContext.platformData);
    LvndWindow* window = platformData->window;
    
    if (window->width != size.width || window->height != size.height) {
        window->width = size.width;
        window->height = size.height;
        
        //TODO: set the framebuffer size
        
        if (window->callbacks.windowResizeCallback != NULL) {
            window->callbacks.windowResizeCallback(window, window->width, window->height);
            NSLog(@"New size: %u, %u", window->width, window->height);
        }
    }
}

/*
- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];

    if (window->handle->mainLoop != NULL) {
        window->handle->mainLoop();
    }
}
*/

- (void)updateFrame {
    UIKit_LvndPlatformData* platformData = (UIKit_LvndPlatformData*)(g_lvndContext.platformData);
    LvndWindow* window = platformData->window;
    if (window->handle->updateFrame != NULL)
        window->handle->updateFrame();
}

@end

/*
@interface UIKit_LvndWindow : UIWindow {

}

@end

@implementation UIKit_LvndWindow

@end
*/

//Scene delegate
@interface UIKit_LvndSceneDelegate : UIResponder <UIWindowSceneDelegate> {
    
}

@property (strong, nonatomic) UIWindow* uiWindow;

@end

@implementation UIKit_LvndSceneDelegate


- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    // Use this method to optionally configure and attach the UIWindow `window` to the provided UIWindowScene `scene`.
    // If using a storyboard, the `window` property will automatically be initialized and attached to the scene.
    // This delegate does not imply the connecting scene or session are new (see `application:configurationForConnectingSceneSession` instead).
    UIWindowScene* windowScene = (UIWindowScene*)scene;
    
    UIWindow* uiWindow = [[UIWindow alloc] initWithWindowScene:windowScene];
    uiWindow.rootViewController = [[UIKit_LvndViewController alloc] init];
    //[uiWindow setBackgroundColor:[UIColor redColor]];
    [uiWindow makeKeyAndVisible];
    
    self.uiWindow = uiWindow;
    //self.window = CFBridgingRelease((LvndWindow*)g_lvndContext.platformData);
    
    UIKit_LvndPlatformData* platformData = (UIKit_LvndPlatformData*)(g_lvndContext.platformData);
    LvndWindow* window = platformData->window;
    window->handle->viewController = (void*)CFBridgingRetain(uiWindow.rootViewController);
    
    //Call functions in the queue
    for (uint16_t i = 0; i < platformData->initCallCount; i++) {
        platformData->initCalls[i]();
    }
    
    platformData->initialized = true;
}


- (void)sceneDidDisconnect:(UIScene *)scene {
    // Called as the scene is being released by the system.
    // This occurs shortly after the scene enters the background, or when its session is discarded.
    // Release any resources associated with this scene that can be re-created the next time the scene connects.
    // The scene may re-connect later, as its session was not necessarily discarded (see `application:didDiscardSceneSessions` instead).
}


- (void)sceneDidBecomeActive:(UIScene *)scene {
    // Called when the scene has moved from an inactive state to an active state.
    // Use this method to restart any tasks that were paused (or not yet started) when the scene was inactive.
}


- (void)sceneWillResignActive:(UIScene *)scene {
    // Called when the scene will move from an active state to an inactive state.
    // This may occur due to temporary interruptions (ex. an incoming phone call).
}


- (void)sceneWillEnterForeground:(UIScene *)scene {
    // Called as the scene transitions from the background to the foreground.
    // Use this method to undo the changes made on entering the background.
}


- (void)sceneDidEnterBackground:(UIScene *)scene {
    // Called as the scene transitions from the foreground to the background.
    // Use this method to save data, release shared resources, and store enough scene-specific state information
    // to restore the scene back to its current state.
}

@end

//Appp delegate
@interface UIKit_LvndAppDelegate : UIResponder <UIApplicationDelegate> {
    
}

@end

@implementation UIKit_LvndAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    /*
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    window.rootViewController = [[ViewController alloc] init];
    [window makeKeyAndVisible];
    */
    
    return YES;
}

- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}

@end

//Public API
void uikit_lvndCreateWindow(LvndWindow* window) {
    window->handle = (UIKit_LvndWindowHandle*)malloc(sizeof(UIKit_LvndWindowHandle));

    g_lvndContext.platformData = malloc(sizeof(UIKit_LvndPlatformData));
    UIKit_LvndPlatformData* platformData = (UIKit_LvndPlatformData*)(g_lvndContext.platformData);
    platformData->initialized = false;
    platformData->initCallCount = 0;
}

void uikit_lvndDestroyWindow(LvndWindow* window) {
    //TODO: destroy objects
}

//Cross-platform main loop
int uikit_lvndMainLoop(LvndWindow* window, void (*updateFrame)(void)) {
    window->handle->updateFrame = updateFrame;
    UIKit_LvndPlatformData* platformData = (UIKit_LvndPlatformData*)(g_lvndContext.platformData);
    platformData->window = window;

    char* argv[0];
    return UIApplicationMain(0, argv, nil, NSStringFromClass([UIKit_LvndAppDelegate class]));
}
