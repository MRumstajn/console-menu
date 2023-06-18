#include <iostream>
#include <vector>
#include "MenuRegistry.h"

using namespace std;

vector<string> menuItems;
int currentItemIndex = 0;

void registerMenuItem(string name) {
    menuItems.push_back(name);
}

string moveToMenuItem(Direction dir) {
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

string getMenuItemAt(int index) {
    if (index < 0 || index >= menuItems.size() || menuItems.size() == 0) {
        return string();
    }

    return menuItems[index];
}

vector<string> getAllMenuItems() {
    return menuItems;
}

int getSelectedMenuItemIndex() {
    return currentItemIndex;
}