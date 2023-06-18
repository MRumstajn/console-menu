#ifndef MENU_INCLUDE
#define MENU_INCLUDE

#include "KeyDetector.h"
#include <iostream>

void registerMenuItem(std::string, CallbackFunction callbackFunction);

void showMenu();

#endif