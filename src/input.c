#include "input.h"
#include "game.h"

#include <SDL3/SDL.h>

void InputUpdate(void){
    SDL_Event event;
    while (SDL_PollEvent(&event)) { 
        if (event.type == SDL_EVENT_QUIT) {
            GameRequestQuit();
        }
    }
}