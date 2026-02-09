#include "input.h"
#include "game.h"

static InputState inputKey;

void InputUpdate(void){
    SDL_Event event;
    while (SDL_PollEvent(&event)) { 
        if (event.type == SDL_EVENT_QUIT) {
            GameRequestQuit();
        }
    }

    const bool *keys = SDL_GetKeyboardState(NULL);

    inputKey.forwardPressed   = keys[SDL_SCANCODE_W];
    inputKey.backwardPressed  = keys[SDL_SCANCODE_S];
    inputKey.leftPressed      = keys[SDL_SCANCODE_A];
    inputKey.rightPressed     = keys[SDL_SCANCODE_D];
}

InputState InputKeyGet(void){
    return inputKey;
}