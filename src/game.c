#include "game.h"
#include "window.h"
#include "render.h"
#include "input.h"

static bool running = false;

bool GameInitSuccess(void){

    if (!WindowInitSuccess()) return false;

    if (!RenderInitSuccess()) return false;

    running = true;
    return true;
}

bool GameIsRunning(void){
    return running;
}

void GameRequestQuit(void){
    running = false;
}

void GameUpdate(void){
    InputUpdate();
}

void GameRender(void){
    RenderBegin();
    RenderEnd();
}

void GameQuit(void){
    RenderClose();
    WindowClose();
}