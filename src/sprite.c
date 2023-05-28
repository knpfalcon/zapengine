#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_sprite.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_actor.h"

ZAP_ACTOR_SPRITE *_actor_sprites[MAX_ACTOR_TYPES];

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
        _actor_sprites[type]->current_frame = 0;

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

    _actor_sprites[type]->start_frame = 0;
    _actor_sprites[type]->end_frame = _actor_sprites[type]->frame_count - 1;
    zlog(INFO, "Actor sprite sheet loaded. Starting Frame: %d, Ending Frame: %d", _actor_sprites[type]->start_frame, _actor_sprites[type]->end_frame);
}

ZAP_ACTOR_SPRITE *zap_get_actor_sprite(int type)
{
    return _actor_sprites[type];
}