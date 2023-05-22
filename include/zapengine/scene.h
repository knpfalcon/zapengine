#ifndef SCENE_H
#define SCENE_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SCENE_NAME_MAX 32

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

    void change_scene(ZAP_SCENE next_scene);

#ifdef __cplusplus
    extern "C" }
#endif

#endif