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

    typedef struct
    {
        float vol;
    }t_sound;

    typedef struct ZAP_SAMPLE
    {
        struct ALLEGRO_SAMPLE_ID id;
        struct ALLEGRO_SAMPLE *sample;
    } ZAP_SAMPLE;

    extern t_sound sound;

    void init_sound(float vol);
    void play_sound(ZAP_SAMPLE *sample, int interupt);
    void load_sample(ZAP_SAMPLE *sample, const char *filename);
    void destroy_sample(ZAP_SAMPLE *sample);

#ifdef __cplusplus
    extern "C"
}
#endif


#endif