#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>

typedef struct{
    bool forwardPressed;
    bool backwardPressed;
    bool leftPressed;
    bool rightPressed;
} InputState;

void InputUpdate(void);
InputState InputKeyGet(void);

#endif