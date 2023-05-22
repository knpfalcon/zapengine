#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "base.h"
#include "actor.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VEL_X_DEFAULT 1
#define VEL_Y_DEFAULT 1
#define MAX_VEL_Y_DEFAULT 12
#define GRAVITY_DEFAULT 1
#define JUMP_STRENGTH_DEFAULT 16

#define DIR_RIGHT 0
#define DIR_DOWN 1 
#define DIR_LEFT 2
#define DIR_UP 3

    ZAP_FUNC(void, move_right, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, move_left, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, move_up, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, move_down, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, apply_gravity, (ZAP_ACTOR *actor));
    ZAP_FUNC(void, jump, (ZAP_ACTOR *actor));

#ifdef __cplusplus
    extern "C"
}
#endif


#endif