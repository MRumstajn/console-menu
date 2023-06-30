#ifndef KEY_DETECTOR_INCLUDE
#define KEY_DETECTOR_INCLUDE

#include <iostream>
#include <map>
#include <vector>

typedef void (*CallbackFunction)();

class KeyDetector {
private:
    std::map<char, std::vector<CallbackFunction>> callbacks;
    int running;
public:
    void registerKeyCallback(int keyCode, CallbackFunction callback);
    void startKeyListener();
    void stopKeyListener();
};

#endif