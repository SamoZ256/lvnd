#include <stdio.h>

#define LVND_DEBUG
#include "lvnd/lvnd.h"

int main() {
    LvndMenuBar* menuBar = lvndCreateMenuBar();

    LvndMenu* fileMenu = lvndCreateMenu("File");
    lvndMenuBarAddMenu(menuBar, fileMenu);
    LvndMenuItem* saveMenuItem = lvndCreateMenuItem("Save", NULL, "s");
    lvndMenuAddMenuItem(fileMenu, saveMenuItem);

    lvndSetGlobalMenuBar(menuBar);

    lvndInit();

    LvndWindow* window = lvndCreateWindow(400, 300, "My Super Window");
    
    while (lvndWindowIsOpen(window)) {
        lvndPollEvents(window);
    }

    lvndDestroyWindow(window);

    return 0;
}
