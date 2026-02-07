#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

bool GameInitSuccess(void);
bool GameIsRunning(void);
void GameUpdate(void);
void GameRender(void);
void GameQuit(void);
void GameRequestQuit(void);

#endif