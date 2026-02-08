#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

#define MAP_WIDTH  20
#define MAP_HEIGHT 15

typedef enum{
    TILE_EMPTY = 0,
    TILE_WALL  = 1
} TILE;

bool MapTileIsWall(int x, int y);

#endif