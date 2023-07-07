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
    std::map<std::string, std::vector<CallbackFunction>> itemCallbacks;

public:
    void registerMenuItem(std::string, CallbackFunction callbackFunction);
    void showMenu();
    void moveToNextItem();
    void moveToPreviousItem();
    void callCallbacksForSelectedItem();
    std::string getSelectedItem();
};

#endif