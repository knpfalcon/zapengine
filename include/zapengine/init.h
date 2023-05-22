#ifndef INIT_H
#define INIT_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(void, game_begin, (int fps, int window_w, int window_h, char *argv0, char *datafile));

#ifdef __cplusplus
    extern "C"
}
#endif

#endif