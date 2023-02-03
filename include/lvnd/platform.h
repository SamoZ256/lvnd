#ifndef LVND_PLATFORM_H
#define LVND_PLATFORM_H

#ifdef __APPLE__

#include <TargetConditionals.h>

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE || TARGET_OS_MACCATALYST

#define __IOS__
#define LVND_PLATFORM_UIKIT

#elif TARGET_OS_MAC

#define __MACOS__
#define LVND_PLATFORM_COCOA

#endif //__APPLE__

#elif defined(WIN32) || defined(_WIN32) || defined(__NT__)

#ifndef __WIN32__
#define __WIN32__
#endif
#define LVND_PLATFORM_WIN32

#elif __linux__

#define __LINUX__
#ifndef LVND_PLATFORM_WAYLAND
#define LVND_PLATFORM_X11
#endif

#endif

#endif
