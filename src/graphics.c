#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_graphics.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_actor.h"

//ZAP_GRAPHIC gfx_native;

#define ATLAS_FRAME_COUNT (al_get_bitmap_width(_actor_sprites[i]->atlas) / frame_w) * (al_get_bitmap_height(_actor_sprites[i]->atlas) / frame_h)

ZAP_ACTOR_SPRITE *_actor_sprites[MAX_ACTOR_TYPES];

void zap_load_actor_sprite(char *file, int frame_w, int frame_h, int type)
{

    int bh;
    int bw;

    if (_actor_sprites[type] == NULL)
    {
        _actor_sprites[type]->atlas = _load_bitmap(file);

        bh = al_get_bitmap_height(_actor_sprites[type]->atlas) / frame_h;
        bw = al_get_bitmap_width(_actor_sprites[type]->atlas) / frame_w;

        for (int y = 0; y < bh; y++)
        {
            for (int x = 0; x < bw; x++)
            {
                zlog("Actor frame count %d", _actor_sprites[type]->frame_count);
                _actor_sprites[type]->frames[_actor_sprites[type]->frame_count] = al_create_sub_bitmap(_actor_sprites[type]->atlas, x * frame_w, y * frame_h, frame_w, frame_h);
                ++_actor_sprites[type]->frame_count;
            }
        }
    }
    else return;

    zlog("Actor sprite sheet loaded.");
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