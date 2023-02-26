/*
 * LVND 1.0
*/

#ifndef LVND_H
#define LVND_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! @file lvnd.h
 *  @brief The header of the LVND api
*/

#include "common.h"

#include "init.h"
#include "context.h"
#include "window.h"
#include "callbacks.h"

#ifdef LVND_BACKEND_VULKAN
#include "vulkan/vulkan.h"
#endif

#ifdef LVND_BACKEND_METAL
#include "metal/metal.h"
#endif

#ifdef LVND_BACKEND_OPENGL
#include "opengl/opengl.h"
#endif

/*************************************************************************
 * LVND api functions
*************************************************************************/

// ---------------- menu_bar.h ----------------

/*! @brief Creates a menu item object.
 *
 *  This functions creates a menu item object that can be added to a menu.
 * 
 *  @param[in] title The title of the menu item to be displayed.
 *  @param[in] action A pointer to a function to be called when the item is clicked on.
 *  @param[in] keyBinding A key equivalent of pressing the item.
 * 
 *  @return A newly created menu item object.
*/
static inline LvndMenuItem* lvndCreateMenuItem(const char* title, void (*action)(void), const char* keyBinding) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_POINTER(title);
    LVND_VALIDATE_POINTER(keyBinding);
#endif
    return _lvndCreateMenuItem(title, action, keyBinding);
}

/*! @brief Creates a menu object.
 *
 *  This function creates a menu object that can be added to a menu bar.
 * 
 *  @param[in] title The title of the menu to be displayed.
 * 
 *  @return A newly created menu object.
*/
static inline LvndMenu* lvndCreateMenu(const char* title) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_POINTER(title);
#endif
    return _lvndCreateMenu(title);
}

/*! @brief Creates a menu bar object.
 *
 *  This function creates a menu bar object. Each application can have only one menu bar object.
 * 
 *  @return A newly created menu bar object.
*/
static inline LvndMenuBar* lvndCreateMenuBar() {
#ifdef LVND_DEBUG
    assert(!g_lvndContext.hasMenuBar && "Menu bar has already been created");
#endif
    return _lvndCreateMenuBar();
}

/*! @brief Adds a menu item object to a menu object.
 *
 *  This function adds a menu item object to a menu object. Each menu item object can be added to an 
 *  unlimited number of menu objects.
 * 
 *  @param[in] menu The menu object the menu item object to be added to.
 *  @param[in] menuItem The menu item object to be added.
*/
static inline void lvndMenuAddMenuItem(LvndMenu* menu, LvndMenuItem* menuItem) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_POINTER(menu);
    LVND_VALIDATE_POINTER(menuItem);
#endif
    _lvndMenuAddMenuItem(menu, menuItem);
}

/*! @brief Adds a separator to a menu object.
 *
 *  This function adds a separator to a menu object.
 * 
 *  @param[in] menu The menu object the separator to be added to.
*/
static inline void lvndMenuAddSeparator(LvndMenu* menu) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_POINTER(menu);
#endif
    _lvndMenuAddSeparator(menu);
}

/*! @brief Adds a menu object to a menu object.
 *
 *  This function adds a menu object to a menu object. Each menu object can be added to an 
 *  unlimited number of menu objects.
 * 
 *  @param[in] menu The menu object the menu object to be added to.
 *  @param[in] menu2 The menu object to be added.
*/
static inline void lvndMenuAddMenu(LvndMenu* menu, LvndMenu* menu2) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_POINTER(menu);
    LVND_VALIDATE_POINTER(menu2);
#endif
    _lvndMenuAddMenu(menu, menu2);
}

/*! @brief Adds a menu object to a menu bar object.
 *
 *  This function adds a menu object to a menu bar object.
 * 
 *  @param[in] menuBar The menu bar object the menu object to be added to.
 *  @param[in] menu The menu object to be added.
*/
static inline void lvndMenuBarAddMenu(LvndMenuBar* menuBar, LvndMenu* menu) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_POINTER(menuBar);
    LVND_VALIDATE_POINTER(menu);
#endif
    _lvndMenuBarAddMenu(menuBar, menu);
}

/*! @brief Sets the global menu bar.
 *
 *  This function sets the @ref globalMenuBar handle of @ref g_lvndContext to be used when calling 
 *  @ref lvndInit.
*/
static inline void lvndSetGlobalMenuBar(LvndMenuBar* menuBar) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_POINTER(menuBar);
#endif
    _lvndSetGlobalMenuBar(menuBar);
}

// ---------------- init.h ----------------

/*! @brief Initializes the LVND library.
 *
 *  This function initializes some of the basic functionality of the LVND library as well as some 
 *  platform specific initializations, like the NSApplication on MacOS. Call the @ref 
 *  lvndSetGlobalMenuBar before a call to this function to create a custom menu bar.
*/
static inline void lvndInit() {
#ifdef LVND_DEBUG
#endif
    _lvndInit();
}

// ---------------- input.h ----------------

/*! @brief Gets the time elapsed.
 *
 *  This functions gets the time elapsed since the call to @ref lvndInit.
 * 
 *  @return The time elapsed.
*/
static inline double lvndGetTime() {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
#endif
    return _lvndGetTime();
}

// ---------------- context.h ----------------

static inline void lvndSetWindowParamValue(LvndWindowParam param, unsigned int value) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
#endif
    _lvndSetWindowParamValue(param, value);
}

// ---------------- window.h ----------------

/*! @brief Creates a window.
 *
 *  This function creates a @ref LvndWindow with a platform specific window handle. In case of OpenGL 
 *  backend, this function also creates an OpenGL context.
 * 
 *  @param[in] width The width of the window.
 *  @param[in] height The height of the window.
 *  @param[in] title The title of the window.
 * 
 *  @return The newly created window object.
*/
static inline LvndWindow* lvndCreateWindow(uint16_t width, uint16_t height, const char* title) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_POINTER(title);
#endif
    LvndWindow* window = _lvndCreateWindow(width, height, title);
//#ifdef LVND_BACKEND_OPENGL
/*
#ifdef LVND_DEBUG
    assert(g_lvndContext.windowParamValues[LVND_WINDOW_PARAM_OPENGL_VERSION_MAJOR] != 0 && "LVND_WINDOW_PARAM_OPENGL_VERSION_MAJOR not set");
    assert(g_lvndContext.windowParamValues[LVND_WINDOW_PARAM_OPENGL_VERSION_MINOR] != 0 && "LVND_WINDOW_PARAM_OPENGL_VERSION_MINOR not set");
#endif
*/
//    _lvndOpenGLCreateContext(window);
//#endif

    return window;
}

/*! @brief Destroys a window.
 *
 *  This function destroys a window.
 * 
 *  @param[in] window The window to be destroyed.
*/
static inline void lvndDestroyWindow(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
/*
#ifdef LVND_BACKEND_VULKAN
    _lvndVulkanDestroyLayer(window);
#elif defined LVND_BACKEND_METAL
    _lvndMetalDestroyLayer(window);
#elif defined LVND_BACKEND_OPENGL
    _lvndOpenGLDestroyContext(window);
#endif
*/
    _lvndDestroyWindow(window);
}

/*! @brief Polls events for the given window.
 *
 *  This function polls events for a window. It should be called at the beginning of each frame.
 * 
 *  @param[in] window The window the events should be processed for. It isn't required on all 
 *  platforms.
*/
static inline void lvndPollEvents(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    _lvndPollEvents(window);
}

/*! @brief Check whether a window is open.
 *
 *  This function checks whether a window is open or not. Should be called every frame in a while 
 *  statement.
 * 
 *  @param[in] window The window to check for.
 * 
 *  @return A boolean value representing whether the window is open or not.
*/
static inline bool lvndWindowIsOpen(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndWindowIsOpen(window);
}

/*! @brief Sets the title of a window.
 *
 *  This function sets the title of a window.
 * 
 *  @param[in] window The window of which the title should be set.
 *  @param[in] title The new title.
*/
static inline void lvndSetWindowTitle(LvndWindow* window, const char* title) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(title);
#endif
    _lvndSetWindowTitle(window, title);
}

/*! @brief Gets the size of a window.
 *
 *  This function gets the size of a window in screen coordinates.
 * 
 *  @param[in] window The window of which to get the size.
 *  @param[out] width The output width.
 *  @param[out] height The output height.
*/
static inline void lvndGetWindowSize(LvndWindow* window, uint16_t* width, uint16_t* height) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(width);
    LVND_VALIDATE_POINTER(height);
#endif
    _lvndGetWindowSize(window, width, height);
}

/*! @brief Gets the size of a window framebuffer.
 *
 *  This function gets the size of a window framebuffer in pixel coordinates. It's the same as 
 *  calling @ref lvndGetWindowSize with some exceptions, like Apple's retina displays, where it's 
 *  usually 2x bigger.
 * 
 *  @param[in] window The window of whose framebuffer to get the size.
 *  @param[out] width The output width.
 *  @param[out] height The output height.
*/
static inline void lvndWindowGetFramebufferSize(LvndWindow* window, uint16_t* width, uint16_t* height) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(width);
    LVND_VALIDATE_POINTER(height);
#endif
    _lvndWindowGetFramebufferSize(window, width, height);
}

static inline void lvndWindowGetFramebufferScale(LvndWindow* window, float* xscale, float* yscale) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(xscale);
    LVND_VALIDATE_POINTER(yscale);
#endif
    _lvndWindowGetFramebufferScale(window, xscale, yscale);
}

static inline LvndState lvndGetKeyState(LvndWindow* window, LvndKey key) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    
    assert(key < LVND_TOTAL_KEY_COUNT && "Unknown key");
#endif
    return _lvndGetKeyState(window, key);
}

static inline LvndState lvndGetMouseButtonState(LvndWindow* window, LvndMouseButton mouseButton) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    
    assert(mouseButton < LVND_TOTAL_MOUSE_BUTTON_COUNT && "Unknown mouse button");
#endif
    return _lvndGetMouseButtonState(window, mouseButton);
}

static inline void lvndGetCursorPosition(LvndWindow* window, int32_t* mouseX, int32_t* mouseY) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(mouseX);
    LVND_VALIDATE_POINTER(mouseY);
#endif
    _lvndGetCursorPosition(window, mouseX, mouseY);
}

static inline void lvndSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    _lvndSetCursorPosition(window, mouseX, mouseY);
}

static inline void lvndSetCursorState(LvndWindow* window, LvndCursorState state) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    _lvndSetCursorState(window, state);
}

static inline void lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    _lvndSetWindowFullscreenMode(window, fullscreen);
}

static inline bool lvndGetModifier(LvndWindow* window, LvndModifier modifier) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndGetModifier(window, modifier);
}

static inline int lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void)) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(updateFrame);
#endif
    return _lvndMainLoop(window, start, updateFrame);
}

static inline void lvndSetWindowUserPointer(LvndWindow* window, void* userPtr) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(userPtr);
#endif
    _lvndSetWindowUserPointer(window, userPtr);
}

static inline void* lvndGetWindowUserPointer(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndGetWindowUserPointer(window);
}

// ---------------- callbacks.h ----------------
static inline LvndWindowResizeCallbackFun lvndSetWindowResizeCallback(LvndWindow* window, LvndWindowResizeCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetWindowResizeCallback(window, callback);
}

static inline LvndWindowFocusCallbackFun lvndSetWindowFocusCallback(LvndWindow* window, LvndWindowFocusCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetWindowFocusCallback(window, callback);
}

static inline LvndCursorEnteredCallbackFun lvndSetCursorEnteredCallback(LvndWindow* window, LvndCursorEnteredCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetCursorEnteredCallback(window, callback);
}

static inline LvndCursorMovedCallbackFun lvndSetCursorMovedCallback(LvndWindow* window, LvndCursorMovedCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetCursorMovedCallback(window, callback);
}

static inline LvndMouseButtonPressedCallbackFun lvndSetMouseButtonPressedCallback(LvndWindow* window, LvndMouseButtonPressedCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetMouseButtonPressedCallback(window, callback);
}

static inline LvndScrollCallbackFun lvndSetScrollCallback(LvndWindow* window, LvndScrollCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetScrollCallback(window, callback);
}

static inline LvndKeyPressedCallbackFun lvndSetKeyPressedCallback(LvndWindow* window, LvndKeyPressedCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetKeyPressedCallback(window, callback);
}

static inline LvndCharCallbackFun lvndSetCharCallback(LvndWindow* window, LvndCharCallbackFun callback) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndSetCharCallback(window, callback);
}

#ifdef LVND_BACKEND_VULKAN

// ---------------- vulkan/vulkan.h ----------------
static inline VkResult lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(surface);
#endif
    return _lvndVulkanCreateWindowSurface(window, instance, surface);
}

static inline void lvndVulkanDestroyLayer(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    _lvndVulkanDestroyLayer(window);
}

static inline const char** lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_POINTER(extensionCount);
#endif
    return _lvndVulkanGetRequiredInstanceExtensions(extensionCount);
}

#endif

#ifdef LVND_BACKEND_METAL

// ---------------- metal/metal.h ----------------
static inline void lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_POINTER(device);
#endif
    _lvndMetalCreateLayer(window, width, height, device);
}

static inline void lvndMetalDestroyLayer(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    _lvndMetalDestroyLayer(window);
}

static inline void* lvndMetalNextDrawable(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    return _lvndMetalNextDrawable(window);
}

#endif

#ifdef LVND_BACKEND_OPENGL

// ---------------- opengl/opengl.h ----------------
static inline void lvndOpenGLCreateContext(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
#endif
    _lvndOpenGLCreateContext(window);
}

static inline void lvndOpenGLDestroyContext(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_OPENGL_CONTEXT(window);
#endif
    _lvndOpenGLDestroyContext(window);
}

static inline void lvndOpenGLResize(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_OPENGL_CONTEXT(window);
#endif
    _lvndOpenGLResize(window);
}

static inline void lvndOpenGLSwapBuffers(LvndWindow* window) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_OPENGL_CONTEXT(window);
#endif
    _lvndOpenGLSwapBuffers(window);
}

static inline void lvndOpenGLSetSwapInterval(LvndWindow* window, int interval) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
    LVND_VALIDATE_WINDOW(window);
    LVND_VALIDATE_OPENGL_CONTEXT(window);
#endif
    _lvndOpenGLSetSwapInterval(window, interval);
}

static inline LvndOpenGLProc lvndOpenGLGetLoadProc(const char* procname) {
#ifdef LVND_DEBUG
    LVND_VALIDATE_INIT;
#endif

    return _lvndOpenGLGetLoadProc(procname);
}

#endif

#ifdef __cplusplus
}
#endif

#endif
