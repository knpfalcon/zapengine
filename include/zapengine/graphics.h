#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define MAX_FRAMES 64
// Holds global bitmaps
typedef struct
{
    struct ALLEGRO_BITMAP *loading;
} t_global_graphic;

typedef struct ZAP_ACTOR_GFX
{
    struct ALLEGRO_BITMAP *atlas;
    struct ALLEGRO_BITMAP *frames[MAX_FRAMES];
} ZAP_ACTOR_GFX;

extern t_global_graphic gfx_global;
extern ZAP_ACTOR_GFX gfx_test_actor;

void load_actor_graphics(void);
void destroy_actor_graphics(void);

void load_global_graphics(void);

#endif