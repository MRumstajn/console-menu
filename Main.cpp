#include <iostream>
#include <windows.h>
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
}

int main() {
	
	registerMenuItem("home", onHomeItemSelected);
	registerMenuItem("settings", onSettingsItemSelected);
	registerMenuItem("exit", onExitItemSelected);
	showMenu();

	return 0;
}
