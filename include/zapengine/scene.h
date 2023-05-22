#ifndef SCENE_H
#define SCENE_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SCENE_NAME_MAX 32

    typedef struct ZAP_SCENE ZAP_SCENE;

    ZAP_FUNC(void, change_scene, (ZAP_SCENE next_scene));

#ifdef __cplusplus
}
#endif

#endif