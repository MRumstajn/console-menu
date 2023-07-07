#ifndef MENU_RENDERER_INCLUDE
#define MENU_RENDERER_INCLUDE

#include <iostream>
#include <vector>

enum MenuAlignment {
    SIDE,
    CENTER
};

class MenuRenderer {
public:
    MenuRenderer();
    ~MenuRenderer();
    void renderMenu(std::vector<std::string> items, 
                    int selectedItemIndex, 
                    int maxItemWitdh, 
                    MenuAlignment alignment);
    void clearScreen();
};

#endif