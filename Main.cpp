#include <iostream>
#include "KeyDetector.h"
#include "MenuRegistry.h"

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
	cout << "current item: " << getMenuItem(Direction::NEXT) << endl;;
}

void sKeyCallback() {
	cout << "current item: " << getMenuItem(Direction::PREVIOUS) << endl;
}

int main() {
	cout << "current item: " + getMenuItemAt(0) << endl;
	
	registerMenuItem("home");
	registerMenuItem("settings");
	registerMenuItem("exit");
	
	registerKeyCallback('w', wKeyCallback);
	registerKeyCallback('s', sKeyCallback);
	startKeyListener();
	
	return 0;
}
