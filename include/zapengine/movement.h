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
#define DIR_DOWN_RIGHT 1
#define DIR_DOWN 2
#define DIR_DOWN_LEFT 3
#define DIR_LEFT 4
#define DIR_UP_LEFT 5
#define DIR_UP 6
#define DIR_UP_RIGHT 7

#define DIAGONAL_MOVE 1.414

    ZAP_FUNC(void, zap_move_actor, (ZAP_ACTOR *actor, int dir));
    ZAP_FUNC(void, zap_move_actor_right, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_move_actor_left, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_move_actor_up, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_move_actor_down, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_apply_actor_gravity, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_actor_jump, (ZAP_ACTOR *actor));

    ZAP_FUNC(void, zap_update_actor_movement, (ZAP_ACTOR *actor));

    ZAP_FUNC(int, zap_get_actor_x, (ZAP_ACTOR *actor));
    ZAP_FUNC(int, zap_get_actor_y, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_set_actor_x, (ZAP_ACTOR *actor, int x));
    ZAP_FUNC(void, zap_set_actor_y, (ZAP_ACTOR *actor, int y));


    ZAP_FUNC(int, zap_get_actor_direction, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_set_actor_direction, (ZAP_ACTOR *actor, int direction));
    ZAP_FUNC(int, zap_get_actor_speed, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, zap_set_actor_speed, (ZAP_ACTOR *actor, int speed));



#ifdef __cplusplus
}
#endif


#endif
