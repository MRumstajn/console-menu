#ifndef KEY_DETECDTOR_INCLUDE
#define KEY_DETECTOR_INCLUDE

typedef void (*CallbackFunction)();

void registerKeyCallback(char key, CallbackFunction callback);

void debugTest();

#endif