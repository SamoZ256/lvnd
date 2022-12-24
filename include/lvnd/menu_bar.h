#ifndef LVND_MENU_BAR_H
#define LVND_MENU_BAR_H

#include <stdint.h>

#include "vector.h"

typedef struct LvndMenuItem {
    const char* title;
    void (*action)(void);
    const char* keyBinding;
} LvndMenuItem;

typedef struct LvndMenu {
    const char* title;

    LvndVector* menuItems;
} LvndMenu;

typedef struct LvndMenuBar {
    LvndVector* menus;
} LvndMenuBar;

LvndMenuItem* _lvndCreateMenuItem(const char* title, void (*action)(void), const char* keyBinding);

LvndMenu* _lvndCreateMenu(const char* title);

LvndMenuBar* _lvndCreateMenuBar();

void _lvndMenuAddMenuItem(LvndMenu* menu, LvndMenuItem* menuItem);

void _lvndMenuBarAddMenu(LvndMenuBar* menuBar, LvndMenu* menu);

void _lvndSetGlobalMenuBar(LvndMenuBar* menuBar);

#endif
