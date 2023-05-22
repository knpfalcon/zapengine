#ifndef CONTROLS_H
#define CONTROLS_H

#include <allegro5/allegro.h>

typedef struct
{
    bool key_state[ALLEGRO_KEY_MAX];

    int key_fire;
    int key_jump;
    int key_left;
    int key_right;
    int key_up;
    int key_down;

}t_controls;

extern t_controls controls;

void init_controls(void);
void check_player_controls(void);

#endif