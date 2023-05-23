#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif


#define MAX_FRAMES 64

    typedef struct ZAP_ACTOR_SPRITE ZAP_ACTOR_SPRITE;

    ZAP_FUNC(void, zap_load_actor_sprite, (char *file, int frame_w, int frame_h, int type));

#ifdef __cplusplus
}
#endif


#endif