#include <allegro5/allegro.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_controls.h"

ZAP_CONTROLS controls;

void _init_controls(void)
{
    controls.key_fire = ALLEGRO_KEY_X;
    controls.key_jump = ALLEGRO_KEY_Z;
    controls.key_left = ALLEGRO_KEY_LEFT;
    controls.key_right = ALLEGRO_KEY_RIGHT;
    controls.key_up = ALLEGRO_KEY_UP;
    controls.key_down = ALLEGRO_KEY_DOWN;
}

void _check_player_controls(void)
{

}

//maybe rename to zap_is_key_down
bool zap_get_key_state(int keycode)
{
    return controls.key_state[keycode];
}