#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
    float x;
    float y;
} Vec2;

typedef struct{
    Vec2 pos;
    Vec2 dir;
    Vec2 plane;
} Player;

void PlayerInit(float x, float y);
void PlayerUpdate(float dt);

Player PlayerGet(void);

#endif