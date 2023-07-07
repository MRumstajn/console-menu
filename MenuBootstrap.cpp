#include "MenuBootstrap.h"
#include "Menu.h"
#include "windows.h"

Menu menu;
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

void hideSimpleMenu() {
    keyDetector.stopKeyListener();
}

void registerMenuItem(std::string item, CallbackFunction callback) {
    menu.registerMenuItem(item, callback);
}