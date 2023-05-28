#ifndef SCENE_H
#define SCENE_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SCENE_NAME_MAX 32

    typedef struct ZAP_SCENE ZAP_SCENE;

    ZAP_FUNC(void, zap_change_scene, (ZAP_SCENE *next_scene));
    ZAP_FUNC(ZAP_SCENE *, zap_create_empty_scene, ());

    ZAP_FUNC(void, zap_set_scene_name, (ZAP_SCENE *scene, char *name));
    ZAP_FUNC(char *, zap_get_scene_name, (ZAP_SCENE *scene));
    ZAP_FUNC(void, zap_set_scene_init_func, (ZAP_SCENE *scene, void(*init)(void)));
    ZAP_FUNC(void, zap_set_scene_update_func, (ZAP_SCENE *scene, void(*update)(void)));
    ZAP_FUNC(void, zap_set_scene_draw_func, (ZAP_SCENE *scene, void(*draw)(void)));
    ZAP_FUNC(void, zap_set_scene_destroy_func, (ZAP_SCENE *scene, void(*destroy)(void)));
    ZAP_FUNC(void, zap_set_scene_key_down_func, (ZAP_SCENE *scene, void(*on_key_down)(int keycode)));
    ZAP_FUNC(void, zap_set_scene_key_up_func, (ZAP_SCENE *scene, void(*on_key_up)(int keycode)));
    ZAP_FUNC(void, zap_scene_use_actors, (ZAP_SCENE *scene, bool use_actors));


#ifdef __cplusplus
}
#endif

#endif
