#include "MenuBootstrap.h"
#include "Menu.h"
#include "windows.h"

Menu menu(MenuAlignment::SIDE);
KeyDetector keyDetector;

void wKeyCallback () {
    menu.moveToPreviousItem();
}

void sKeyCallback () {
    menu.moveToNextItem();
}

void enterKeyCallback () {
    menu.callCallbacksForSelectedItem();
}

void showSimpleMenu() {
    menu.showMenu();
    
    keyDetector.registerKeyCallback('w', wKeyCallback);
	keyDetector.registerKeyCallback('s', sKeyCallback);
	keyDetector.registerKeyCallback(VK_RETURN, enterKeyCallback);
    keyDetector.startKeyListener();
}

void redrawSimpleMenu() {
    menu.redrawMenu();
}

void hideSimpleMenu() {
    keyDetector.stopKeyListener();
}

void registerMenuItem(std::string item, CallbackFunction callback) {
    menu.registerMenuItem(item, callback);
}

void setAlignment(MenuAlignment alignment) {
    menu.setAlignment(alignment);
}

void setSelectionConfig(MenuItemSelectionConfig *config) {
    menu.setSelectionConfig(config);
}