#include <iostream>
#include <windows.h>
#include "MenuBootstrap.h"
#include "Menu.h"

using namespace std;

/*
	Program structure:

	KeyDetector
		- detecting keys
		- registering callback
		- calling callback when key is pressed

	MenuRegistry
		-	used to register and switch between items

	Menu
		- wrapper that sets up menu registry and renderer

	MenuRenderer
		- draws to the screen

	MenuBootstrap
		- wraps menu and provides basic controls using w and s keys
		
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
	struct MenuItemSelectionConfig *config = new MenuItemSelectionConfig{
		"( ",
		" )",
		"-> ( ",
		" ) <-"
	};

	registerMenuItem("Home", onHomeItemSelected);
	registerMenuItem("Settings", onSettingsItemSelected);
	registerMenuItem("Exit", onExitItemSelected);
	setAlignment(MenuAlignment::CENTER);
	setSelectionConfig(config);
	showSimpleMenu();
	
	return 0;
}
