#ifndef MENU_RENDERER_INCLUDE
#define MENU_RENDERER_INCLUDE

#include <iostream>
#include <vector>

class MenuRenderer {
public:
    MenuRenderer();
    ~MenuRenderer();
    void renderMenu(std::vector<std::string> items, int selectedItemIndex, int maxItemWitdh);
    void clearScreen();
};

#endif