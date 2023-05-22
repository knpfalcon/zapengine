#ifndef ZINTERN_GRAPHICS_H
#define ZINTERN_GRAPHICS_H

#include "graphics.h"

#ifdef __cplusplus
extern "C" {
#endif

    // Holds global bitmaps
    typedef struct
    {
        struct ALLEGRO_BITMAP *loading;
    } ZAP_GRAPHIC;

    typedef struct ZAP_ACTOR_GFX
    {
        struct ALLEGRO_BITMAP *atlas;
        struct ALLEGRO_BITMAP *frames[MAX_FRAMES];
    } ZAP_ACTOR_GFX;

    extern ZAP_GRAPHIC gfx_native;

    void _load_actor_graphics(void);
    void _destroy_actor_graphics(void);

    void _load_native_graphics(void);

#ifdef __cplusplus
}
#endif

#endif