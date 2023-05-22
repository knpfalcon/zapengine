#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_controls.h"

t_controls controls;

void init_controls(void)
{
    controls.key_fire = ALLEGRO_KEY_X;
    controls.key_jump = ALLEGRO_KEY_Z;
    controls.key_left = ALLEGRO_KEY_LEFT;
    controls.key_right = ALLEGRO_KEY_RIGHT;
    controls.key_up = ALLEGRO_KEY_UP;
    controls.key_down = ALLEGRO_KEY_DOWN;
}

void check_player_controls(void)
{

}
