#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "base.h"
#include "actor.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_VEL_Y_DEFAULT 12
#define GRAVITY_DEFAULT 0.25
#define ACCELERATION_DEFAULT 0.25
#define DECELERATION_DEFAULT 0.25
#define JUMP_STRENGTH_DEFAULT 6
#define MAX_SPEED_DEFAULT 2.5

#define DIR_RIGHT 0
#define DIR_DOWN_RIGHT 1
#define DIR_DOWN 2
#define DIR_DOWN_LEFT 3
#define DIR_LEFT 4
#define DIR_UP_LEFT 5
#define DIR_UP 6
#define DIR_UP_RIGHT 7

#define DIAGONAL_MOVE 1.414

    ZAP_FUNC(void, z_move_actor, (ZAP_ACTOR *actor, int dir));
    ZAP_FUNC(void, z_stop_actor_h, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_stop_actor_v, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_hard_stop_actor_h, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_move_actor_right, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_move_actor_left, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_move_actor_up, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_move_actor_down, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_apply_actor_gravity, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_actor_jump, (ZAP_ACTOR *actor));

    ZAP_FUNC(void, z_update_actor_movement, (ZAP_ACTOR *actor));

    ZAP_FUNC(float, z_get_actor_x, (ZAP_ACTOR *actor));
    ZAP_FUNC(float, z_get_actor_y, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_set_actor_x, (ZAP_ACTOR *actor, float x));
    ZAP_FUNC(void, z_set_actor_y, (ZAP_ACTOR *actor, float y));
    ZAP_FUNC(float, z_get_actor_y_velocity, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_set_actor_y_velocity, (ZAP_ACTOR *actor, float vely));
    ZAP_FUNC(float, z_get_actor_x_velocity, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_set_actor_x_velocity, (ZAP_ACTOR *actor, float velx));


    ZAP_FUNC(int, z_get_actor_direction, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_set_actor_direction, (ZAP_ACTOR *actor, int direction));

    ZAP_FUNC(void, z_set_actor_acceleration, (ZAP_ACTOR *actor, float accel));
    ZAP_FUNC(void, z_set_actor_deceleration, (ZAP_ACTOR *actor, float decel));

    ZAP_FUNC(float, z_get_actor_speed, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, z_set_actor_speed, (ZAP_ACTOR *actor, float speed));



#ifdef __cplusplus
}
#endif


#endif
