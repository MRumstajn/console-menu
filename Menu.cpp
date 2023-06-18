#include "Menu.h"
#include "MenuRegistry.h"
#include "MenuRenderer.h"
#include <map>
#include <iostream>
#include <windows.h>

using namespace std;

map<string, vector<CallbackFunction>> itemCallbacks;

void wKeyCallback() {
    moveToMenuItem(Direction::PREVIOUS);
	renderMenu(getAllMenuItems(), getSelectedMenuItemIndex(), 8);
}

void sKeyCallback() {
    moveToMenuItem(Direction::NEXT);
	renderMenu(getAllMenuItems(), getSelectedMenuItemIndex(), 8);
}

void enterKeyCallback() {
    string selectedItem = getMenuItemAt(getSelectedMenuItemIndex());

    auto pos = itemCallbacks.find(selectedItem);
    if (pos != itemCallbacks.end()) {
        vector<CallbackFunction> functions = pos -> second;
        for (CallbackFunction func : functions) {
            (*func)();
        }
    }
}

void registerMenuItem(string item, CallbackFunction callbackFunction) {
    registerMenuItem(item);

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

void showMenu() {
    KeyDetector keyDetector;
    keyDetector.registerKeyCallback('w', wKeyCallback);
	keyDetector.registerKeyCallback('s', sKeyCallback);
	keyDetector.registerKeyCallback(VK_RETURN, enterKeyCallback);

	renderMenu(getAllMenuItems(), getSelectedMenuItemIndex(), 8);

	keyDetector.startKeyListener();
}