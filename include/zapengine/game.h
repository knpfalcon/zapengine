#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "base.h"
#include "scene.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ZAP_GAME
    {
        bool done;
        bool redraw;
        bool draw_bounding_boxes;

        int fps;
        int window_w;
        int window_h;
        int reserved_samples;
        int ticks;

        struct ALLEGRO_DISPLAY *display;
        struct ALLEGRO_EVENT_QUEUE *event_queue;
        struct ALLEGRO_TIMER *update_timer;
        struct ALLEGRO_BITMAP *view;

        ZAP_SCENE current_scene;

    } ZAP_GAME;

    extern ZAP_GAME game;

#ifdef __cplusplus
    extern "C"
}
#endif

void main_event_loop(void);

#endif