#ifndef _ACTOR_H
#define _ACTOR_H

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

    ZAP_FUNC(ZAP_ACTOR *, zap_create_actor, (char *name, int vel_x, int vel_y, int max_vel_y, int gravity, int jump_strength, int w, int h, void (*update_func)(void *self)));

#ifdef __cplusplus
}
#endif


#endif
