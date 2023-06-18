#ifndef KEY_DETECDTOR_INCLUDE
#define KEY_DETECTOR_INCLUDE

typedef void (*CallbackFunction)();

void registerKeyCallback(int keyCode, CallbackFunction callback);

void startKeyListener();

#endif