#ifndef MENU_BOOTSTRAP_INCLUDE
#define MENU_BOOTSTRAP_INCLUDE

#include <iostream>
#include "KeyDetector.h"
#include "MenuRenderer.h"

void showSimpleMenu();
void redrawSimpleMenu();
void hideSimpleMenu();
void registerMenuItem(std::string, CallbackFunction callbackFunction);
void setAlignment(MenuAlignment alignment);
void setSelectionConfig(MenuItemSelectionConfig *config);

#endif