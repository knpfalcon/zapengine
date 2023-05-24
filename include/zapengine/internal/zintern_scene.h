#ifndef ZINTERN_SCENE_H
#define ZINTERN_SCENE_H

#include <stdbool.h>
#include "scene.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct ZAP_SCENE
    {
        char *name;
        void(*init)(void);
        void(*update)(void);
        void(*draw)(void);
        void(*destroy)(void);
        void(*on_key_down)(int keycode);
        void(*on_key_up)(int keycode);

        bool use_actors;
    };

    void _destroy_scene(ZAP_SCENE *scene);

#ifdef __cplusplus
}
#endif

#endif