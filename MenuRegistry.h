#ifndef MENU_REGISTRY_INCLUDE
#define MENU_REGISTRY_INCLUDE

#include <iostream>

using namespace std;

enum Direction {
    NEXT,
    PREVIOUS
};

void registerMenuItem(std::string name);

string getMenuItemAt(int index);

string getMenuItem(Direction dir);

#endif