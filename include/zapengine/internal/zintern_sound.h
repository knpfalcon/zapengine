#ifndef ZINTERN_SOUND_H
#define ZINTERN_SOUND_H

#include "sound.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ZAP_SOUND
    {
        float vol;
    } ZAP_SOUND;

    typedef struct ZAP_SAMPLE
    {
        struct ALLEGRO_SAMPLE_ID id;
        struct ALLEGRO_SAMPLE *sample;
    }ZAP_SAMPLE;

    extern ZAP_SOUND sound;

    void _init_sound(float vol);
    void _destroy_sample(ZAP_SAMPLE *sample);

#ifdef __cplusplus
}
#endif

#endif