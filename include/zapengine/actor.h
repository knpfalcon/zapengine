#ifndef _ACTOR_H
#define _ACTOR_H

#include <stdbool.h>
#include "base.h"
#include "graphics.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PLAYER 0

#define MAX_ACTORS 512
#define MAX_ACTOR_TYPES 512 //For actor module update callback list

#define ACTOR_SELF ((struct ZAP_ACTOR *)self)

    typedef struct ZAP_ACTOR ZAP_ACTOR;

    typedef void (*ZAP_ACTOR_MODULE_CALLBACK)(int index);

    ZAP_FUNC(int, zap_add_actor, (int x, int y, int dir, ZAP_ACTOR *type));
    ZAP_FUNC(int, zap_remove_actor, (int id));
    ZAP_FUNC(void, zap_register_actor_module, (ZAP_ACTOR_MODULE_CALLBACK actor_module_update_function));

    //Probaly don't need this one after tests
    ZAP_FUNC(ZAP_ACTOR *, zap_create_actor, (char *name, int vel_x, int vel_y, int max_vel_y, int gravity, int jump_strength, int w, int h, int type, void (*update_func)(void *self)));

    ZAP_FUNC(ZAP_ACTOR *, zap_create_empty_actor, (void));
    ZAP_FUNC(void, zap_set_actor_init_func, (ZAP_ACTOR *actor, void(*init)(ZAP_ACTOR *self)));
    ZAP_FUNC(void, zap_set_actor_update_func, (ZAP_ACTOR *actor, void(*update)(ZAP_ACTOR *self)));
    ZAP_FUNC(void, zap_set_actor_draw_func, (ZAP_ACTOR *actor, void(*draw)(ZAP_ACTOR *self)));
    ZAP_FUNC(void, zap_set_actor_destroy_func, (ZAP_ACTOR *actor, void(*destroy)(ZAP_ACTOR *self)));
    ZAP_FUNC(void, zap_set_actor_key_down_func, (ZAP_ACTOR *actor, void(*on_key_down)(int keycode, ZAP_ACTOR *self)));
    ZAP_FUNC(void, zap_set_actor_key_up_func, (ZAP_ACTOR *actor, void(*on_key_up)(int keycode, ZAP_ACTOR *self)));
    ZAP_FUNC(void, zap_set_actor_type, (ZAP_ACTOR *actor, int type));
    ZAP_FUNC(int, zap_get_actor_type, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_set_actor_active, (ZAP_ACTOR *actor, bool active));
    ZAP_FUNC(void, zap_set_actor_sprite, (ZAP_ACTOR *actor, ZAP_ACTOR_SPRITE *sprite));
    ZAP_FUNC(void, zap_set_actor_animation_frames, (ZAP_ACTOR *actor, int start_frame, int end_frame));
    ZAP_FUNC(void, zap_animate_actor, (ZAP_ACTOR *actor, int speed));


#ifdef __cplusplus
}
#endif


#endif
