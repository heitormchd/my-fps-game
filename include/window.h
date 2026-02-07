#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>

bool WindowInitSuccess(void);
void WindowClose(void);

SDL_Window *WindowGet(void);

#endif