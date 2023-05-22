#ifndef ZINTERN_EVENTS_H
#define ZINTERN_EVENTS_H

#include "events.h"

#ifdef __cplusplus
extern "C" {
#endif

    union ALLEGRO_EVENT;

    void _check_misc_events(union ALLEGRO_EVENT *event);
    void _check_keyboard_events(union ALLEGRO_EVENT *event);
    void _check_bgm_audio_stream(union ALLEGRO_EVENT *event);
    void _check_fps_timer(union ALLEGRO_EVENT *event);

#ifdef __cplusplus
    extern "C"
}
#endif

#endif