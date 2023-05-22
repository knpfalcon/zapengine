#ifndef SOUND_H
#define SOUND_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INTERUPT_NONE 0
#define INTERUPT_SELF 1
#define INTERUPT_ALL 2

#define MAX_SAMPLES 32

    typedef struct ZAP_SAMPLE ZAP_SAMPLE;

    ZAP_FUNC(void, play_sound, (ZAP_SAMPLE *sample, int interupt));
    ZAP_FUNC(void, load_sample, (ZAP_SAMPLE *sample, const char *filename));

#ifdef __cplusplus
}
#endif


#endif