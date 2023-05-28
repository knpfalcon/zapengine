#ifndef SPRITE_H_
#define SPRITE_H_

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif


#define MAX_FRAMES 64

    typedef struct ZAP_ACTOR_SPRITE ZAP_ACTOR_SPRITE;
    typedef struct ZAP_GRAPHIC ZAP_GRAPHIC;

    ZAP_FUNC(void, zap_load_actor_sprite, (char *file, int frame_w, int frame_h, int type));
    ZAP_FUNC(ZAP_ACTOR_SPRITE *, zap_get_actor_sprite, (int type));

#ifdef __cplusplus
}
#endif


#endif