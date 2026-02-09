#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>

#define TILE_SIZE 32

bool RenderInitSuccess(void);
void RenderBegin(void);
void RenderEnd(void);
void RenderClose(void);
void RenderMap2D(void);
void RenderPlayer2D(void);

SDL_Renderer *GetRender();

#endif