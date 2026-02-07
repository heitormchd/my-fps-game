#include "window.h"

static SDL_Window *window = NULL;

bool WindowInitSuccess(void){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Erro ao inicializar SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Teste", 640, 480, SDL_WINDOW_RESIZABLE);

    if (!window){
        SDL_Log("Erro ao criar janela: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    return true;
}

void WindowClose(void){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Window *WindowGet(void){
    return window;
}