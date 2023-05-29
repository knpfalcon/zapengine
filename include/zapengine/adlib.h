#ifndef ADLIB_H
#define ADLIB_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(void, z_load_music_file, (const char *filename));
    ZAP_FUNC(void, z_play_music, (void));
    ZAP_FUNC(void, z_pause_music, (void));
    ZAP_FUNC(void, z_resume_music, (void));
    ZAP_FUNC(void, z_restart_music, (void));

#ifdef __cplusplus
}
#endif

#endif
