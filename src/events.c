#include <allegro5/allegro.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_events.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_controls.h"
#include "zapengine/internal/zintern_draw.h"
#include "zapengine/internal/zintern_update.h"
#include "zapengine/internal/zintern_adlib.h"
#include "zapengine/internal/zintern_sound.h"

void _check_misc_events(ALLEGRO_EVENT *event)
{
    if (event->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        zlog("Quit by clicking X");
        game.done = true;
    }
}

void _check_keyboard_events(ALLEGRO_EVENT *event)
{
    if (event->type == ALLEGRO_EVENT_KEY_DOWN)
    {
        controls.key_state[event->keyboard.keycode] = true;
        if (game.current_scene.on_key_down)
            (*game.current_scene.on_key_down)(event->keyboard.keycode);

#ifdef DEBUG
        //Bounding box draw toggle
        if (event->keyboard.keycode == ALLEGRO_KEY_B)
        {
            if (game.draw_bounding_boxes == true) game.draw_bounding_boxes = false;
            else if (game.draw_bounding_boxes == false) game.draw_bounding_boxes = true;
        }
#endif

    }

    if (event->type == ALLEGRO_EVENT_KEY_UP)
    {
        controls.key_state[event->keyboard.keycode] = false;
        if (game.current_scene.on_key_up)
            (*game.current_scene.on_key_up)(event->keyboard.keycode);
    }
}

void _check_bgm_audio_stream(ALLEGRO_EVENT *event)
{
    if (music.is_playing)
    {
        if (event->type == ALLEGRO_EVENT_AUDIO_STREAM_FRAGMENT)
        {
            _stream_opl();
        }
    }
}

void _check_fps_timer(ALLEGRO_EVENT *event)
{

    if (event->type == ALLEGRO_EVENT_TIMER)
    {
        if (event->timer.source == game.update_timer)
        {
            ++game.ticks;
            if (game.ticks == 1)
            {
                _update_logic();
            }
            game.redraw = true;
        }
    }

    if (game.redraw && al_is_event_queue_empty(game.event_queue))
    {
        game.redraw = false;

        _draw_screen();

        game.ticks = 0;
    }
}
