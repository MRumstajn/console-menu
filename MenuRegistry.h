#ifndef MENU_REGISTRY_INCLUDE
#define MENU_REGISTRY_INCLUDE

#include <iostream>
#include <vector>

using namespace std;

enum Direction {
    NEXT,
    PREVIOUS
};

void registerMenuItem(std::string name);

string getMenuItemAt(int index);

string moveToMenuItem(Direction dir);

vector<string> getAllMenuItems();

int getSelectedMenuItemIndex();

#endif