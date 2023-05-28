#ifndef ZINTERN_SPRITE_H
#define ZINTERN_SPRITE_H

#include "sprite.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct ZAP_ACTOR_SPRITE
    {
        int frame_count;
        int current_frame;
        int start_frame;
        int end_frame;
        struct ALLEGRO_BITMAP *atlas;
        struct ALLEGRO_BITMAP *frames[MAX_FRAMES];
    };

#ifdef __cplusplus
}
#endif

#endif