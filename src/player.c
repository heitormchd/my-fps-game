#include "player.h"
#include "input.h"
#include "map.h"

#include <math.h>

static Player player = {0};
static const float MOVE_SPEED = 3.0f;
static const float ROT_SPEED  = 2.0f;

void PlayerInit(float x, float y){
    player.pos      = (Vec2){x, y};
    player.dir      = (Vec2){0.0f, -1.0f};
    player.plane    = (Vec2){0.66f, 0.0f};
}

void PlayerUpdate(float dt){
    InputState key = InputKeyGet();

    float moveStep = MOVE_SPEED * dt;
    float rotStep = ROT_SPEED * dt;

    if (key.forwardPressed || key.backwardPressed){

        float moveX = key.forwardPressed ? player.dir.x * moveStep : - player.dir.x * moveStep;
        float moveY = key.forwardPressed ? player.dir.y * moveStep : - player.dir.y * moveStep;

        float newPosX = player.pos.x + moveX; 
        float newPosY = player.pos.y + moveY;

        if (!MapTileIsWall((int)newPosX, (int)player.pos.y)) player.pos.x = newPosX;
        if (!MapTileIsWall((int)player.pos.x, (int)newPosY)) player.pos.y = newPosY;
    } 

    if (key.leftPressed || key.rightPressed){
        float rot = key.leftPressed ? - rotStep : rotStep;

        float oldDirX = player.dir.x;
        player.dir.x = player.dir.x * cosf(rot) - player.dir.y * sinf(rot);
        player.dir.y = oldDirX * sinf(rot) + player.dir.y * cosf(rot);

        float oldPlaneX = player.plane.x;
        player.plane.x = player.plane.x * cosf(rot) - player.plane.y * sinf(rot);
        player.plane.y = oldPlaneX * sinf(rot) + player.plane.y * cosf(rot);
    } 

}

Player PlayerGet(void){
    return player;
}