#include <iostream>
#include <vector>
#include "MenuRegistry.h"

using namespace std;

void MenuRegistry::registerMenuItem(string name) {
    menuItems.push_back(name);
}

string MenuRegistry::moveToMenuItem(Direction dir) {
    if (dir == Direction::NEXT) {
        if (currentItemIndex < menuItems.size() - 1) {
            currentItemIndex += 1;
        } else {
            currentItemIndex = 0;
        }
    } else {
        if (currentItemIndex > 0) {
            currentItemIndex -= 1;
        } else {
            currentItemIndex = menuItems.size() - 1;
        }
    }

    string item = menuItems[currentItemIndex];
    return item;
}

string MenuRegistry::getMenuItemAt(int index) {
    if (index < 0 || index >= menuItems.size() || menuItems.size() == 0) {
        return string();
    }

    return menuItems[index];
}

vector<string> MenuRegistry::getAllMenuItems() {
    return menuItems;
}

int MenuRegistry::getSelectedMenuItemIndex() {
    return currentItemIndex;
}