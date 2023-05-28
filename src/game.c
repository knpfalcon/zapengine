#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_physfs.h>
#include <physfs.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_init.h"
#include "zapengine/internal/zintern_events.h"
#include "zapengine/internal/zintern_scene.h"

ZAP_GAME game; //Shared globals struct for game related variables

int zap_get_drawn_game_frames(void)
{
    return game.drawn_frames;
}

/****************************
*                           *
*         MAIN LOOP         *
*                           *
*****************************/
void _main_event_loop(void)
{
    ALLEGRO_EVENT event;
    while (!game.done)
    {
        al_wait_for_event(game.event_queue, &event);
        _check_misc_events(&event);
        _check_keyboard_events(&event);
        _check_bgm_audio_stream(&event);
        _check_fps_timer(&event);
    }
}
