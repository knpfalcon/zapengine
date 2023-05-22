#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_graphics.h"
#include "zapengine/internal/zintern_bitmap.h"

ZAP_ACTOR_GFX gfx_test_actor;
t_global_graphic gfx_global;

void load_actor_graphics(void)
{
    //gfx_test_actor.atlas = load_bitmap(gfx_act_smiley);
    gfx_test_actor.frames[0] = al_create_sub_bitmap(gfx_test_actor.atlas, 0, 0, 32, 32);
    zlog("Test Actor Graphics loaded.");
}

void destroy_actor_graphics(void)
{
    al_destroy_bitmap(gfx_test_actor.frames[0]);
    al_destroy_bitmap(gfx_test_actor.atlas);
    zlog("Test Actor Graphics Destroyed.");
}

void load_global_graphics(void)
{
    //gfx_global.loading = al_load_bitmap(gfx_fs_loading);
}