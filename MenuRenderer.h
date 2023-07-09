

#ifndef MENU_RENDERER_INCLUDE
#define MENU_RENDERER_INCLUDE

#include <iostream>
#include <vector>

struct MenuItemSelectionConfig {
    std::string defaultSymbolLeft;
    std::string defaultSymbolRight;
    std::string selectedSymbolLeft;
    std::string selectedSymbolRight;
};

enum MenuAlignment {
    SIDE,
    CENTER
};

class MenuRenderer {
private:
    struct MenuItemSelectionConfig *selectionConfig;
public:
    MenuRenderer();
    ~MenuRenderer();
    void renderMenu(std::vector<std::string> items, 
                    int selectedItemIndex, 
                    int maxItemWitdh, 
                    MenuAlignment alignment);
    void clearScreen();
    void setSelectionConfig(MenuItemSelectionConfig *config);
};

#endif