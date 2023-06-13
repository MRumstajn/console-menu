#include <iostream>
#include "KeyDetector.h"

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

void aKeyCallback() {
	cout << "a is pressed! " << endl;
}

int main() {
	registerKeyCallback('a', aKeyCallback);
	debugTest();

	return 0;
}
