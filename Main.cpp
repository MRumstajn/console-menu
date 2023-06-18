#include <iostream>
#include <windows.h>
#include "KeyDetector.h"
#include "MenuRegistry.h"
#include "MenuRenderer.h"

using namespace std;

/*
	Program structure:

	Controls
		- detecting keys
		- registering callback
		- calling callback when key is pressed

	GUI
		- draws to the screen

	Main
		- controller
*/

void wKeyCallback() {
	moveToMenuItem(Direction::PREVIOUS);
	renderMenu(getAllMenuItems(), getSelectedMenuItemIndex(), 8);
}

void sKeyCallback() {
	moveToMenuItem(Direction::NEXT);
	renderMenu(getAllMenuItems(), getSelectedMenuItemIndex(), 8);
}

void enterKeyCallback() {
	cout << "chosen option: " << getMenuItemAt(getSelectedMenuItemIndex()) << endl;
}

int main() {
	registerMenuItem("home");
	registerMenuItem("settings");
	registerMenuItem("exit");
	
	registerKeyCallback('w', wKeyCallback);
	registerKeyCallback('s', sKeyCallback);
	registerKeyCallback(VK_RETURN, enterKeyCallback);

	renderMenu(getAllMenuItems(), getSelectedMenuItemIndex(), 8);

	startKeyListener();
	
	return 0;
}
