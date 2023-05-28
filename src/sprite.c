#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_sprite.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_actor.h"


ZAP_ACTOR_SPRITE *_actor_sprites[MAX_ACTOR_TYPES];

void _destroy_sprites()
{
    for (int i = 0; i < MAX_ACTOR_TYPES; i++)
    {
        if (_actor_sprites[i])
        {
            for (int f = 0; f < _actor_sprites[i]->frame_count; f++)
            {
                zlog(INFO, "Destroying Actor Type %d's frame %d", i, f);
                if (_actor_sprites[i]->frames[f]) al_destroy_bitmap(_actor_sprites[i]->frames[f]);
                _actor_sprites[i]->frames[f] = NULL;
                zlog(INFO, "Actor %d frame %d Destroyed.", i, f);
            }
            if (_actor_sprites[i]->atlas)
            {
                zlog(INFO, "Destroying Actor Type %d's atlas", i);
                if (_actor_sprites[i]->atlas) al_destroy_bitmap(_actor_sprites[i]->atlas);
                _actor_sprites[i]->atlas = NULL;
                zlog(INFO, "Actor %d's atlas Destroyed.", i);
            }
            zlog(INFO, "Freeing Actor Sprite Type %d.", i);
            free(_actor_sprites[i]);
            _actor_sprites[i] = NULL;
            zlog(INFO, "Actor Sprite %d freed.", i);
        }
    }
}

void zap_load_actor_sprite(char *file, int frame_w, int frame_h, int type)
{
    zlog(LOAD, "Loading actor sprite from file %s for type %d", file, type);
    int bh;
    int bw;

    if (_actor_sprites[type] == NULL)
    {
        _actor_sprites[type] = malloc(sizeof(ZAP_ACTOR_SPRITE));
        _actor_sprites[type]->atlas = _load_bitmap(file);
        _actor_sprites[type]->frame_count = 0;

        bh = al_get_bitmap_height(_actor_sprites[type]->atlas) / frame_h;
        bw = al_get_bitmap_width(_actor_sprites[type]->atlas) / frame_w;

        for (int y = 0; y < bh; y++)
        {
            for (int x = 0; x < bw; x++)
            {
                zlog(INFO, "Actor frame count %d", _actor_sprites[type]->frame_count);
                _actor_sprites[type]->frames[_actor_sprites[type]->frame_count] = al_create_sub_bitmap(_actor_sprites[type]->atlas, x * frame_w, y * frame_h, frame_w, frame_h);
                _actor_sprites[type]->frame_count++;
            }
        }
    }
    else return;

    zlog(INFO, "Actor sprite sheet loaded.");
}

ZAP_ACTOR_SPRITE *zap_get_actor_sprite(int type)
{
    return _actor_sprites[type];
}

