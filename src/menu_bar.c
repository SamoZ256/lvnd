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
    menu->menuItemTypes = lvndCreateVector(LVND_DEFAULT_VECTOR_CAPACITY);

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
    lvndVectorPushBack(menu->menuItemTypes, (void*)LVND_MENU_ITEM_TYPE_ITEM);
}

void _lvndMenuAddSeparator(LvndMenu* menu) {
    lvndVectorPushBack(menu->menuItems, NULL);
    lvndVectorPushBack(menu->menuItemTypes, (void*)LVND_MENU_ITEM_TYPE_SEPARATOR);
}

void _lvndMenuAddMenu(LvndMenu* menu, LvndMenu* menu2) {
    lvndVectorPushBack(menu->menuItems, menu2);
    lvndVectorPushBack(menu->menuItemTypes, (void*)LVND_MENU_ITEM_TYPE_MENU);
}

void _lvndMenuBarAddMenu(LvndMenuBar* menuBar, LvndMenu* menu) {
    lvndVectorPushBack(menuBar->menus, menu);
}

void _lvndSetGlobalMenuBar(LvndMenuBar* menuBar) {
    g_lvndContext.globalMenuBar = menuBar;
}
