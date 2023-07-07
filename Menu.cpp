#include "Menu.h"
#include "MenuRegistry.h"
#include "MenuRenderer.h"
#include "KeyDetector.h"
#include <map>
#include <iostream>
#include <windows.h>

using namespace std;

void Menu::moveToNextItem() {
    menuRegistry.moveToMenuItem(Direction::NEXT);
	renderer.renderMenu(menuRegistry.getAllMenuItems(), menuRegistry.getSelectedMenuItemIndex(), 8);
}

void Menu::moveToPreviousItem() {
    menuRegistry.moveToMenuItem(Direction::PREVIOUS);
	renderer.renderMenu(menuRegistry.getAllMenuItems(), menuRegistry.getSelectedMenuItemIndex(), 8); 
}

string Menu::getSelectedItem() {
    return menuRegistry.getAllMenuItems().at(menuRegistry.getSelectedMenuItemIndex());    
}

void Menu::registerMenuItem(string item, CallbackFunction callbackFunction) {
    menuRegistry.registerMenuItem(item);

    if (itemCallbacks.count(item)) {
        auto pos = itemCallbacks.find(item);
        if (pos != itemCallbacks.end()) {
            vector<CallbackFunction> &functions = pos ->second;
            functions.push_back(callbackFunction);
        }
    } else {
        vector<CallbackFunction> newCallbackVector;
        newCallbackVector.push_back(callbackFunction);

        itemCallbacks.insert(pair<string, vector<CallbackFunction>>(item, newCallbackVector));
    }
}

void Menu::showMenu() {
	renderer.renderMenu(menuRegistry.getAllMenuItems(), menuRegistry.getSelectedMenuItemIndex(), 8);
}

void Menu::callCallbacksForSelectedItem() {
    auto pos = itemCallbacks.find(getSelectedItem());
    if (pos != itemCallbacks.end()) {
        vector<CallbackFunction> functions = pos -> second;
        for (CallbackFunction func : functions) {
            (*func)();
        }
    }
}