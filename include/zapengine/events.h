#ifndef EVENTS_H
#define EVENTS_H

#include <allegro5/allegro.h>

void check_misc_events(ALLEGRO_EVENT *event);
void check_keyboard_events(ALLEGRO_EVENT *event);
void check_bgm_audio_stream(ALLEGRO_EVENT *event);
void check_fps_timer(ALLEGRO_EVENT *event);

#endif