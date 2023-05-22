#ifndef SOUND_H
#define SOUND_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "base.h"

#define INTERUPT_NONE 0
#define INTERUPT_SELF 1
#define INTERUPT_ALL 2

#define MAX_SAMPLES 32

    typedef struct ZAP_SAMPLE ZAP_SAMPLE;

    void play_sound(ZAP_SAMPLE *sample, int interupt);
    void load_sample(ZAP_SAMPLE *sample, const char *filename);

#ifdef __cplusplus
    extern "C"
}
#endif


#endif