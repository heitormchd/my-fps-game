#include "game.h"
#include "window.h"
#include "render.h"
#include "input.h"
#include "player.h"

static bool running = false;
static float deltaTime = 0.0f;
static Uint64 lastTick = 0;

bool GameInitSuccess(void){
    if (!WindowInitSuccess()) return false;
    if (!RenderInitSuccess()) return false;

    PlayerInit(9.5f, 7.5f);

    running = true;

    // inicializa o timer
    lastTick = SDL_GetTicks();

    return true;
}

bool GameIsRunning(void){
    return running;
}

void GameRequestQuit(void){
    running = false;
}

void GameUpdate(void){
    Uint64 currentTick = SDL_GetTicks();
    deltaTime = (currentTick - lastTick) / 1000.0f;
    lastTick = currentTick;

    InputUpdate();
    PlayerUpdate(deltaTime);
}

void GameRender(void){
    RenderBegin();
    RenderMap2D();
    RenderPlayer2D();
    RenderEnd();
}

void GameQuit(void){
    RenderClose();
    WindowClose();
}