#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_sprite.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_util.h"


ZAP_ACTOR_SPRITE *_actor_sprites[MAX_ACTOR_TYPES];

void _destroy_sprites()
{
    for (int i = 0; i < MAX_ACTOR_TYPES; i++)
    {
        if (_actor_sprites[i])
        {
            zlog(NONE, "Destroying Actor Type %d's frames", i);
            _depopulate_frames(_actor_sprites[i]->frames, _actor_sprites[i]->frame_count);
            if (_actor_sprites[i]->atlas)
            {
                zlog(NONE, "Destroying Actor Type %d's atlas", i);
                if (_actor_sprites[i]->atlas) al_destroy_bitmap(_actor_sprites[i]->atlas);
                _actor_sprites[i]->atlas = NULL;
                zlog(INFO, "Actor %d's atlas Destroyed.", i);
            }
            zlog(NONE, "Freeing actor sprite type %d.", i);
            free(_actor_sprites[i]);
            _actor_sprites[i] = NULL;
            zlog(INFO, "Actor Sprite %d freed.", i);
        }
    }
}

void zap_load_actor_sprite(char *file, int frame_w, int frame_h, int type)
{
    zlog(LOAD, "Loading actor sprite from file %s for type %d", file, type);


    if (_actor_sprites[type] == NULL)
    {
        _actor_sprites[type] = malloc(sizeof(ZAP_ACTOR_SPRITE));
        _actor_sprites[type]->atlas = _load_bitmap(file);

        _actor_sprites[type]->frame_count = _populate_frames(_actor_sprites[type]->atlas, 32, 32, _actor_sprites[type]->frames, MAX_ACTOR_TYPES);
    }
    else return;

    zlog(INFO, "Actor sprite sheet loaded.");
}

ZAP_ACTOR_SPRITE *zap_get_actor_sprite(int type)
{
    return _actor_sprites[type];
}

