#include "render.h"
#include "window.h"
#include "map.h"
#include "player.h"

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

void RenderMap2D(void){
    for (int line = 0; line < MAP_HEIGHT; line++){
        for (int column = 0; column < MAP_WIDTH; column++){

            SDL_FRect rect = {
                column * TILE_SIZE,
                line * TILE_SIZE,
                TILE_SIZE,
                TILE_SIZE
            };

            if (!MapTileIsWall(column, line)){
                SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
                SDL_RenderRect(renderer, &rect);
            } else {
                SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

void RenderPlayer2D(void){
    Player player = PlayerGet();
    const int radius = 8;

    // player circle
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int y = - radius; y <= radius; y++){
        for (int x = - radius; x <= radius; x++){
            if(x * x + y * y <= radius * radius){
                SDL_RenderPoint(renderer, 
                    player.pos.x * TILE_SIZE + x, 
                    player.pos.y * TILE_SIZE + y);
            }
        }
    }

    // player direction
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderLine(
        renderer,
        player.pos.x * TILE_SIZE,
        player.pos.y * TILE_SIZE,
        (player.pos.x + player.dir.x) * TILE_SIZE,
        (player.pos.y + player.dir.y) * TILE_SIZE
    );

    // camera plane
    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    SDL_RenderLine(
        renderer,
        (player.pos.x + player.dir.x) * TILE_SIZE,
        (player.pos.y + player.dir.y) * TILE_SIZE,
        (player.pos.x + player.dir.x + player.plane.x) * TILE_SIZE,
        (player.pos.y + player.dir.y + player.plane.y) * TILE_SIZE
    );
    SDL_RenderLine(
        renderer,
        (player.pos.x + player.dir.x) * TILE_SIZE,
        (player.pos.y + player.dir.y) * TILE_SIZE,
        (player.pos.x + player.dir.x - player.plane.x) * TILE_SIZE,
        (player.pos.y + player.dir.y - player.plane.y) * TILE_SIZE
    );  
}