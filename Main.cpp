#include <iostream>
#include <windows.h>
#include "MenuBootstrap.h"
#include "Menu.h"

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

void onHomeItemSelected() {
	cout << "Home item selected" << endl;
}

void onSettingsItemSelected() {
	cout << "Settings item selected" << endl;
}

void onExitItemSelected() {
	cout << "Exit item selected" << endl;
	hideSimpleMenu();
}

int main() {
	registerMenuItem("Home", onHomeItemSelected);
	registerMenuItem("Settings", onSettingsItemSelected);
	registerMenuItem("Exit", onExitItemSelected);
	setAlignment(MenuAlignment::CENTER);
	showSimpleMenu();

	return 0;
}
