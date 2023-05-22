#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_physfs.h>
#include <physfs.h>

#include "scene.h"

/*
*   These structs are for better organizations of shared/global data
*   if it ever needs passed, a reference to one struct will be easier
*/

typedef struct
{
    bool done;
    bool redraw;
    bool draw_bounding_boxes;

    int fps;
    int window_w;
    int window_h;
    int reserved_samples;
    int ticks;

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_TIMER *update_timer;
    ALLEGRO_BITMAP *view;

    t_scene current_scene;

} t_game;

extern t_game game;

void main_event_loop(void);

#endif