#include "lvnd/x11/x11_init.h"

/*
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Intrinsic.h>
#include <Xm/Xm.h>
#include <Xm/Label.h>
#include <Xm/Form.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>
#include <Xm/CascadeB.h>

#include "lvnd/context.h"

void menuCB(Widget w, char *client_data, XmAnyCallbackStruct *call_data) {
    printf("%s\n", client_data);
}

void _x11_lvndCreateMenuItem(Widget menu, LvndMenuItem* item) {
    int ac = 0;
    Arg al[10];

    XtSetArg(al[ac], XmNlabelString, XmStringCreateLtoR(item->title, XmSTRING_DEFAULT_CHARSET)); ac++;
    Widget b = XtCreateManagedWidget(item->title, xmPushButtonWidgetClass, menu, al, ac);
    XtAddCallback(b, XmNactivateCallback, menuCB, item->title); //TODO: figure out why they used "client_data"
    XtSetSensitive(b, True);

    printf("Creating menu item with title %s\n", item->title);
}

void _x11_lvndCreateMenu(Widget menuBar, LvndMenu* menu) {
    int ac;
    Arg al[10];
    Widget customMenu, cascade;

    ac = 0;
    customMenu = XmCreatePulldownMenu (menuBar, menu->title, al, ac);

    ac = 0;
    XtSetArg (al[ac], XmNsubMenuId, customMenu);  ac++;
    XtSetArg(al[ac], XmNlabelString, XmStringCreateLtoR(menu->title, XmSTRING_DEFAULT_CHARSET)); ac++;
    cascade = XmCreateCascadeButton(menuBar, menu->title, al, ac);
    XtManageChild(cascade);

    for (uint16_t j = 0; j < menu->menuItems->size; j++) {
        LvndMenuItemType itemType = (LvndMenuItemType)lvndVectorGet(menu->menuItemTypes, j);
        if (itemType == LVND_MENU_ITEM_TYPE_ITEM) {
            LvndMenuItem* menuItem = lvndVectorGet(menu->menuItems, j);
            _x11_lvndCreateMenuItem(customMenu, menuItem);
        } else if (itemType == LVND_MENU_ITEM_TYPE_SEPARATOR) {
            //TODO: add a separator
        } else if (itemType == LVND_MENU_ITEM_TYPE_MENU) {
            LvndMenu* newMenu = lvndVectorGet(menu->menuItems, j);
            _x11_lvndCreateMenu(customMenu, newMenu);
        }
    }
}

void _x11_createMenuBar() {
    Arg al[10];
    int ac = 0;

    int argc = 0;
    char *argv[argc];
    Widget toplevel = XtInitialize(argv[0], "", NULL, 0, &argc, argv);

    ac = 0;
    Widget form = XtCreateManagedWidget("form",xmFormWidgetClass, toplevel, al, ac);

    ac = 0;
    Widget menuBar = XmCreateMenuBar(form, "menuBar", al, ac);
    XtManageChild(menuBar);

    //Attach the menu bar to the form
    ac=0;
    XtSetArg(al[ac], XmNtopAttachment,    XmATTACH_FORM); ac++;
    XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
    XtSetArg(al[ac], XmNleftAttachment,   XmATTACH_FORM); ac++;
    XtSetValues(menuBar,al,ac);

    if (g_lvndContext.globalMenuBar != NULL) {
        for (uint16_t i = 0; i < g_lvndContext.globalMenuBar->menus->size; i++) {
            LvndMenu* menu = lvndVectorGet(g_lvndContext.globalMenuBar->menus, i);
            _x11_lvndCreateMenu(menuBar, menu);
        }
    }
}
*/

void x11_lvndInit() {
    //_x11_createMenuBar();
    //Empty for now
}
