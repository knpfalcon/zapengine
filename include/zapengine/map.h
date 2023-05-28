#ifndef MAP_H
#define MAP_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_MAP_SIZE 11520
#define MAX_TILES 512

    typedef struct ZAP_MAP_TILE ZAP_MAP_TILE;
    typedef struct ZAP_MAP_ACTOR ZAP_MAP_ACTOR;
    typedef struct ZAP_MAP ZAP_MAP;

    ZAP_FUNC(ZAP_MAP *, zap_create_empty_map, (void));
    ZAP_FUNC(ZAP_MAP *, zap_load_map, (const char *mapfile));
    ZAP_FUNC(ZAP_MAP *, zap_save_map, (ZAP_MAP *map, const char *mapfile));
    ZAP_FUNC(void, zap_destroy_map, (ZAP_MAP *map));
    ZAP_FUNC(void, zap_set_map_name, (ZAP_MAP *map, const char *name));

#ifdef __cplusplus
}
#endif

#endif
