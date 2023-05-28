#ifndef ZINTERN_MAP_H
#define ZINTERN_MAP_H

#include <stdbool.h>
#include "map.h"
#include "zapengine/internal/zintern_actor.h"

struct ZAP_MAP_TILE
{
    int type;
};

struct ZAP_MAP_ACTOR
{
    int type;
};

struct ZAP_MAP
{
    char name[32];
    int bgm;

    int w;
    int h;

    //Layers
    ZAP_MAP_TILE layer_bg[MAX_MAP_SIZE];
    ZAP_MAP_TILE layer_fg[MAX_MAP_SIZE];
    ZAP_MAP_TILE layer_clsn[MAX_MAP_SIZE];

    //Actors
    int actor_count;
    ZAP_MAP_ACTOR actors[MAX_ACTORS];
};

#endif
