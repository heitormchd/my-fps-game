#include "render.h"
#include "window.h"

static SDL_Renderer *renderer = NULL;

bool RenderInitSuccess(void){
    renderer = SDL_CreateRenderer(WindowGet(), NULL);

    if (!renderer) {
        SDL_Log("Erro ao criar renderer: %s", SDL_GetError());
        WindowClose();
        return false;
    }

    return true;
}

void RenderBegin(void){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void RenderEnd(void){
    SDL_RenderPresent(renderer);
}

void RenderClose(void){
    SDL_DestroyRenderer(renderer);
}

SDL_Renderer *GetRender(void){
    return renderer;
}