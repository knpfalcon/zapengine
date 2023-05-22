#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "actor.h"

#define VEL_X_DEFAULT 1
#define VEL_Y_DEFAULT 1
#define MAX_VEL_Y_DEFAULT 12
#define GRAVITY_DEFAULT 1
#define JUMP_STRENGTH_DEFAULT 16

#define DIR_RIGHT 0
#define DIR_DOWN 1 
#define DIR_LEFT 2
#define DIR_UP 3

void move_right(ZAP_ACTOR *actor);
void move_left(ZAP_ACTOR *actor);
void move_up(ZAP_ACTOR *actor);
void move_down(ZAP_ACTOR *actor);
void apply_gravity(ZAP_ACTOR *actor);
void jump(ZAP_ACTOR *actor);
void set_actor_points(ZAP_ACTOR *actor);

#endif