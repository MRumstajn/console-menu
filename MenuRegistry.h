#ifndef MENU_REGISTRY_INCLUDE
#define MENU_REGISTRY_INCLUDE

#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum Direction {
    NEXT,
    PREVIOUS
};

class MenuRegistry {
private:
    std::vector<string> menuItems;
    int currentItemIndex;
public:
    void registerMenuItem(std::string name);
    string getMenuItemAt(int index);
    string moveToMenuItem(Direction dir);
    vector<string> getAllMenuItems();
    int getSelectedMenuItemIndex();
};

#endif