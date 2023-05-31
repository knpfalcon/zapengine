#ifndef _ACTOR_H
#define _ACTOR_H

#include <stdbool.h>
#include "base.h"
#include "sprite.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PLAYER 0

#define MAX_ACTORS 512
#define MAX_ACTOR_TYPES 512 //For actor module update callback list

#define ACTOR_SELF ((struct ZAP_ACTOR *)self)

    typedef struct ZAP_ACTOR ZAP_ACTOR;

    enum ACTOR_MOVEMENT_TYPE { E_MOVEMENT_NONE, E_MOVEMENT_PLAYER_PLATFORM };
    enum ACTOR_STATE { E_ACTOR_STATE_STOPPED, E_ACTOR_STATE_WALKING, E_ACTOR_STATE_JUMPING, E_ACTOR_STATE_FALLING };

    typedef void (*ZAP_ACTOR_MODULE_CALLBACK)(int index);

    ZAP_FUNC(int, z_add_actor, (int x, int y, int dir, ZAP_ACTOR *type));
    ZAP_FUNC(int, z_remove_actor, (int id));
    ZAP_FUNC(void, z_register_actor_module, (ZAP_ACTOR_MODULE_CALLBACK actor_module_update_function));

    //Probaly don't need this one after tests
    ZAP_FUNC(ZAP_ACTOR *, z_create_actor, (char *name, float vel_x, int vel_y, int max_vel_y, int gravity, int jump_strength, int w, int h, int type, void (*update_func)(void *self)));

    ZAP_FUNC(ZAP_ACTOR *, z_create_empty_actor, (void));
    ZAP_FUNC(void, z_set_actor_init_func, (ZAP_ACTOR *actor, void(*init)(ZAP_ACTOR *self)));
    ZAP_FUNC(void, z_set_actor_update_func, (ZAP_ACTOR *actor, void(*update)(ZAP_ACTOR *self)));
    ZAP_FUNC(void, z_set_actor_draw_func, (ZAP_ACTOR *actor, void(*draw)(ZAP_ACTOR *self)));
    ZAP_FUNC(void, z_set_actor_destroy_func, (ZAP_ACTOR *actor, void(*destroy)(ZAP_ACTOR *self)));

    ZAP_FUNC(void, z_set_actor_type, (ZAP_ACTOR *actor, int type));
    ZAP_FUNC(int, z_get_actor_type, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_set_actor_active, (ZAP_ACTOR *actor, bool active));
    ZAP_FUNC(void, z_set_actor_sprite, (ZAP_ACTOR *actor, ZAP_ACTOR_SPRITE *sprite));
    ZAP_FUNC(void, z_set_actor_animation_frames, (ZAP_ACTOR *actor, int start_frame, int end_frame));
    ZAP_FUNC(void, z_animate_actor, (ZAP_ACTOR *actor, int speed));
    ZAP_FUNC(void, z_set_actor_state, (ZAP_ACTOR *actor, int state));
    ZAP_FUNC(int, z_get_actor_state, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, z_get_actor_w, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, z_get_actor_h, (ZAP_ACTOR *actor));

    ZAP_FUNC(ZAP_ACTOR *, z_get_actor, (int id));
    ZAP_FUNC(int, z_get_actor_id, (ZAP_ACTOR *actor));

    ZAP_FUNC(void, z_set_actor_builtin_movement, (ZAP_ACTOR *actor, int type));


#ifdef __cplusplus
}
#endif


#endif
