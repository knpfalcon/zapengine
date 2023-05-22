#ifndef ADLIB_H
#define ADLIB_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(void, zap_load_music_file, (const char *filename));
    ZAP_FUNC(void, zap_play_music, (void));
    ZAP_FUNC(void, zap_pause_music, (void));
    ZAP_FUNC(void, zap_resume_music, (void));
    ZAP_FUNC(void, zap_restart_music, (void));

#ifdef __cplusplus
    extern "C"
}
#endif

#endif