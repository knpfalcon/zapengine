#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_init.h"
#include "zapengine/internal/zintern_events.h"

ZAP_GAME game; //Shared globals struct for game related variables

/****************************
*                           *
*         MAIN LOOP         *
*                           *
*****************************/
void main_event_loop(void)
{
    ALLEGRO_EVENT event;
    while (!game.done)
    {
        al_wait_for_event(game.event_queue, &event);
        check_misc_events(&event);
        check_keyboard_events(&event);
        check_bgm_audio_stream(&event);
        check_fps_timer(&event);
    }
}