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

bool zap_get_key_state(int keycode)
{
    return controls.key_state[keycode];
}

int zap_get_key(int key)
{
    switch (key)
    {
    case e_key_left:
        return controls.key_left;
        break;
    case e_key_right:
        return controls.key_right;
        break;
    case e_key_down:
        return controls.key_down;
        break;
    case e_key_up:
        return controls.key_up;
        break;
    case e_key_fire:
        return controls.key_fire;
        break;
    case e_key_jump:
        return controls.key_jump;
        break;
    }
    return 0;
}
