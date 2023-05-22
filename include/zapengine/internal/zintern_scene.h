#ifndef ZINTERN_SCENE_H
#define ZINTERN_SCENE_H

#include "scene.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ZAP_SCENE
    {
        char *name;
        void(*init)(void);
        void(*update)(void);
        void(*draw)(void);
        void(*destroy)(void);
        void(*on_key_down)(int keycode);
        void(*on_key_up)(int keycode);
    } ZAP_SCENE;

#ifdef __cplusplus
}
#endif

#endif