#ifndef ZINTERN_GRAPHICS_H
#define ZINTERN_GRAPHICS_H

#include "graphics.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct ZAP_GRAPHIC
    {
        struct ALLEGRO_BITMAP *loading;
    };

    struct ZAP_ACTOR_SPRITE
    {
        int frame_count;
        int current_frame;
        int start_frame;
        int end_frame;
        struct ALLEGRO_BITMAP *atlas;
        struct ALLEGRO_BITMAP *frames[MAX_FRAMES];
    };

    extern ZAP_GRAPHIC gfx_native;

    void _load_actor_graphics(void);
    void _destroy_actor_graphics(void);

    void _load_native_graphics(void);

#ifdef __cplusplus
}
#endif

#endif