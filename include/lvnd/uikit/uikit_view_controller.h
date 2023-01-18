#ifndef LVND_UIKIT_VIEW_CONTROLLER_H
#define LVND_UIKIT_VIEW_CONTROLLER_H

#import <UIKit/UIKit.h>

//View controller
@interface UIKit_LvndViewController : UIViewController {
    @public CAMetalLayer* metalLayer;
    CADisplayLink* timer;
}

- (void)updateFrame;

@end

#endif
