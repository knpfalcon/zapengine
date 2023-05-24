#ifndef ZINTERN_GAME_H
#define ZINTERN_GAME_H

#include "game.h"

#include "zintern_scene.h"

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
        struct ALLEGRO_FONT *sys_font;
        struct ALLEGRO_BITMAP *splash;

        ZAP_SCENE *current_scene;

    } ZAP_GAME;

    extern ZAP_GAME game;

    void _main_event_loop(void);

#ifdef __cplusplus
}
#endif

#endif