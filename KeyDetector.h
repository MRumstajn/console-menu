#ifndef KEY_DETECDTOR_INCLUDE
#define KEY_DETECTOR_INCLUDE

#include <iostream>
#include <map>
#include <vector>

typedef void (*CallbackFunction)();

class KeyDetector {
private:
    std::map<char, std::vector<CallbackFunction>> callbacks;
public:
    void registerKeyCallback(int keyCode, CallbackFunction callback);
    void startKeyListener();
};

#endif