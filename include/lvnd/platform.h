#ifndef LVND_PLATFORM_H
#define LVND_PLATFORM_H

#ifdef __APPLE__

#include <TargetConditionals.h>

#if TARGET_IPHONE_SIMULATOR
#define __IOS__
#elif TARGET_OS_IPHONE
#define __IOS__
#elif TARGET_OS_MAC
#define __MACOS__
#elif TARGET_OS_MACCATALYST
#define __MACOS__
#endif

#elif defined(WIN32) || defined(_WIN32) || defined(__NT__)

#ifndef __WIN32__
#define __WIN32__
#endif

#elif __linux__

#define __LINUX__

#endif

#endif
