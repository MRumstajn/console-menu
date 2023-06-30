#include <iostream>
#include <vector>
#include <map>
#include <windows.h>
#include <conio.h>
#include "KeyDetector.h"

using namespace std;

void KeyDetector::registerKeyCallback(int keyCode, CallbackFunction callbackFunc) {
    if (callbacks.count(keyCode)) {
        auto pos = callbacks.find(keyCode);
        if (pos != callbacks.end()) {
            vector<CallbackFunction> &functions = pos ->second;
            functions.push_back(callbackFunc);
        }
    } else {
        vector<CallbackFunction> newCallbackVector;
        newCallbackVector.push_back(callbackFunc);

        callbacks.insert(pair<char, vector<CallbackFunction>>(keyCode, newCallbackVector));
    }
}

void KeyDetector::startKeyListener() {
    running = 1;
    while (running == 1) {
        if (kbhit()) {
            char pressedKey = getch();
            auto pos = callbacks.find((int) pressedKey);
            if (pos != callbacks.end()) {
                for (CallbackFunction callback : pos -> second) {
                    (*callback)();
                }
            }
        }
    }
}

void KeyDetector::stopKeyListener() {
    running = 0;
}