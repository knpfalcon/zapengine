#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "base.h"
#include "actor.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_VEL_Y_DEFAULT 12;
#define GRAVITY_DEFAULT 2;
#define JUMP_STRENGTH_DEFAULT 12;
#define SPEED_DEFAULT 4;

#define DIR_RIGHT 0
#define DIR_DOWN 1 
#define DIR_LEFT 2
#define DIR_UP 3

    ZAP_FUNC(void, zap_move_actor_right, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_move_actor_left, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_move_actor_up, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_move_actor_down, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_apply_actor_gravity, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_actor_jump, (ZAP_ACTOR *actor));

    ZAP_FUNC(void, zap_update_actor_movement, (ZAP_ACTOR *actor));

    ZAP_FUNC(int, zap_get_actor_x, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, zap_get_actor_y, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, zap_get_actor_center_x, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, zap_get_actor_center_y, (ZAP_ACTOR *actor));

    ZAP_FUNC(void, zap_set_actor_box, (ZAP_ACTOR *actor, int left, int right, int top, int bottom));

    ZAP_FUNC(int, zap_get_actor_direction, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_set_actor_direction, (ZAP_ACTOR *actor, int direction));
    ZAP_FUNC(int, zap_get_actor_speed, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_set_actor_speed, (ZAP_ACTOR *actor, int speed));

    ZAP_FUNC(int, zap_get_actor_left, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, zap_get_actor_right, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, zap_get_actor_top, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, zap_get_actor_bottom, (ZAP_ACTOR *actor));

#ifdef __cplusplus
}
#endif


#endif