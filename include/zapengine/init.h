#ifndef INIT_H
#define INIT_H

#include "base.h"
#include "scene.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(void, z_game_begin, (int fps, int window_w, int window_h, char *argv0, char *datafile, ZAP_SCENE *first_scene));

#ifdef __cplusplus
}
#endif

#endif
