#include <iostream>
#include <vector>
#include <map>
#include "KeyDetector.h"
#include <string>

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

void debugTest(){
    for (auto key : callbacks) {
        for (auto callback : key.second) {
            (*callback)();
        }
    }
}