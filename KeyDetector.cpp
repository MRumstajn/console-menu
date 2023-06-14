#include <iostream>
#include <vector>
#include <map>
#include <windows.h>
#include <conio.h>
#include "KeyDetector.h"

using namespace std;

map<char, vector<CallbackFunction>> callbacks;

void registerKeyCallback(char key, CallbackFunction callbackFunc) {
    if (callbacks.count(key)) {
        auto pos = callbacks.find(key);
        if (pos != callbacks.end()) {
            vector<CallbackFunction> &functions = pos ->second;
            functions.push_back(callbackFunc);
        }
    } else {
        vector<CallbackFunction> newCallbackVector;
        newCallbackVector.push_back(callbackFunc);

        callbacks.insert(pair<char, vector<CallbackFunction>>(key, newCallbackVector));
    }
}

void startKeyListener() {
    for (;;) {
        if (kbhit()) {
            char pressedKey = getch();
            auto pos = callbacks.find(pressedKey);
            if (pos != callbacks.end()) {
                for (CallbackFunction callback : pos -> second) {
                    (*callback)();
                }
            }
        }
    }
}