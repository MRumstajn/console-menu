#ifndef MENU_BOOTSTRAP_INCLUDE
#define MENU_BOOTSTRAP_INCLUDE

#include <iostream>
#include "KeyDetector.h"

void showSimpleMenu();
void hideSimpleMenu();
void registerMenuItem(std::string, CallbackFunction callbackFunction);

#endif