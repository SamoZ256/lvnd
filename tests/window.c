#include <stdio.h>

#define LVND_DEBUG
#include "lvnd/lvnd.h"

int main() {
    lvndInit();

    LvndWindow* window = lvndCreateWindow(400, 300, "My Super Window");
    
    while (lvndWindowIsOpen(window)) {
        lvndPollEvents(window);
    }

    lvndDestroyWindow(window);

    return 0;
}
