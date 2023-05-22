#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_graphics.h"
#include "zapengine/internal/zintern_bitmap.h"

//ZAP_GRAPHIC gfx_native;

void _load_actor_graphics(void)
{
    //gfx_test_actor.atlas = _load_bitmap(gfx_act_smiley);
    //gfx_test_actor.frames[0] = al_create_sub_bitmap(gfx_test_actor.atlas, 0, 0, 32, 32);
    zlog("Test Actor Graphics loaded.");
}

void _destroy_actor_graphics(void)
{
    /* al_destroy_bitmap(gfx_test_actor.frames[0]);
    al_destroy_bitmap(gfx_test_actor.atlas);*/
    zlog("Test Actor Graphics Destroyed.");
}

void _load_native_graphics(void)
{
    //gfx_native.loading = al_load_bitmap("GRAPHICS/gfx_fs_loading");
}