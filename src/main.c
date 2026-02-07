#include "game.h"

int main(void){

    if (!GameInitSuccess())
        return 1;
    
    while (GameIsRunning()){
        GameUpdate();
        GameRender();
    }

    GameQuit();
    return 0;
}