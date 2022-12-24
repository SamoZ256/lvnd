#include "lvnd/menu_bar.h"

#include <stdlib.h>

#include "lvnd/context.h"

LvndMenuItem* _lvndCreateMenuItem(const char* title, void (*action)(void), const char* keyBinding) {
    LvndMenuItem* menuItem = (LvndMenuItem*)malloc(sizeof(LvndMenuItem));

    menuItem->title = title;
    menuItem->action = action;
    menuItem->keyBinding = keyBinding;

    return menuItem;
}

LvndMenu* _lvndCreateMenu(const char* title) {
    LvndMenu* menu = (LvndMenu*)malloc(sizeof(LvndMenu));

    menu->title = title;
    menu->menuItems = lvndCreateVector(LVND_DEFAULT_VECTOR_CAPACITY);

    return menu;
}

LvndMenuBar* _lvndCreateMenuBar() {
    LvndMenuBar* menuBar = (LvndMenuBar*)malloc(sizeof(LvndMenuBar));

    menuBar->menus = lvndCreateVector(LVND_DEFAULT_VECTOR_CAPACITY);

    g_lvndContext.hasMenuBar = true;

    return menuBar;
}

void _lvndMenuAddMenuItem(LvndMenu* menu, LvndMenuItem* menuItem) {
    lvndVectorPushBack(menu->menuItems, menuItem);
}

void _lvndMenuBarAddMenu(LvndMenuBar* menuBar, LvndMenu* menu) {
    lvndVectorPushBack(menuBar->menus, menu);
}

void _lvndSetGlobalMenuBar(LvndMenuBar* menuBar) {
    g_lvndContext.globalMenuBar = menuBar;
}
