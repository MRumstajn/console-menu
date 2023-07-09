#ifndef MENU_INCLUDE
#define MENU_INCLUDE

#include "MenuRegistry.h"
#include "MenuRenderer.h"
#include "KeyDetector.h"
#include <iostream>

class Menu {
private:
    MenuRegistry menuRegistry;
    MenuRenderer renderer;
    MenuAlignment alignment;
    std::map<std::string, std::vector<CallbackFunction>> itemCallbacks;

public:
    Menu(MenuAlignment alignment);
    void registerMenuItem(std::string, CallbackFunction callbackFunction);
    void showMenu();
    void moveToNextItem();
    void moveToPreviousItem();
    void callCallbacksForSelectedItem();
    void setAlignment(MenuAlignment alignment);
    void setSelectionConfig(MenuItemSelectionConfig *config);
    std::string getSelectedItem();
};

#endif