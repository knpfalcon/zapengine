#ifndef ZINTERN_SPRITE_H
#define ZINTERN_SPRITE_H

#include "sprite.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct ZAP_ACTOR_SPRITE
    {
        int frame_count;
        struct ALLEGRO_BITMAP *atlas;
        struct ALLEGRO_BITMAP *frames[MAX_FRAMES];
    };


    void _destroy_sprites();
#ifdef __cplusplus
}
#endif

#endif