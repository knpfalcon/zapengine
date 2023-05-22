#ifndef EVENTS_H
#define EVENTS_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    union ALLEGRO_EVENT;

    void check_misc_events(union ALLEGRO_EVENT *event);
    void check_keyboard_events(union ALLEGRO_EVENT *event);
    void check_bgm_audio_stream(union ALLEGRO_EVENT *event);
    void check_fps_timer(union ALLEGRO_EVENT *event);

#ifdef __cplusplus
    extern "C"
}
#endif

#endif