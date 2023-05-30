#include "zapengine/internal/zintern_movement.h"

static void _set_actor_points(ZAP_ACTOR *actor)
{
    actor->x_center = (actor->w / 2) + actor->x;
    actor->y_center = (actor->h / 2) + actor->y;

    actor->left = actor->x + actor->bbl;
    actor->right = actor->x + actor->w - actor->bbr;
    actor->bottom = actor->y + actor->h - actor->bbb;
    actor->top = actor->y + actor->bbt;
}

void z_move_actor(ZAP_ACTOR *actor, int dir)
{
    switch (dir)
    {
    case DIR_RIGHT:
        if (!actor->platform_movement) actor->vel_y = 0;
        actor->vel_x += actor->acceleration;
        if (actor->vel_x > actor->max_speed)
        {
            actor->vel_x = actor->max_speed;
        }
        break;
    case DIR_DOWN_RIGHT:
        actor->vel_x = actor->max_speed / DIAGONAL_MOVE;
        actor->vel_y = actor->max_speed / DIAGONAL_MOVE;
        break;
    case DIR_DOWN:
        if (!actor->platform_movement) actor->vel_x = 0;
        actor->vel_y = actor->max_speed;
        break;
    case DIR_DOWN_LEFT:
        actor->vel_x = -actor->max_speed / DIAGONAL_MOVE;
        actor->vel_y = actor->max_speed / DIAGONAL_MOVE;
        break;
    case DIR_LEFT:
        if (!actor->platform_movement) actor->vel_y = 0;
        actor->vel_x += -actor->acceleration;
        if (actor->vel_x < -actor->max_speed)
        {
            actor->vel_x = -actor->max_speed;
        }
        break;
    case DIR_UP_LEFT:
        actor->vel_x = -actor->max_speed / DIAGONAL_MOVE;
        actor->vel_y = -actor->max_speed / DIAGONAL_MOVE;
        break;
    case DIR_UP:
        if (!actor->platform_movement) actor->vel_x = 0;
        actor->vel_y = -actor->max_speed;
        break;
    case DIR_UP_RIGHT:
        actor->vel_x = actor->max_speed / DIAGONAL_MOVE;
        actor->vel_y = -actor->max_speed / DIAGONAL_MOVE;
        break;
    }
}

void z_stop_actor_h(ZAP_ACTOR *actor)
{
    if (actor->dir == DIR_RIGHT)
    {
        if (actor->vel_x > 0) actor->vel_x += -actor->deceleration;
        if ((int)actor->vel_x == 0) actor->vel_x = 0;
    }
    else if (actor->dir == DIR_LEFT)
    {
        if (actor->vel_x < 0) actor->vel_x += actor->deceleration;
        if ((int)actor->vel_x == 0) actor->vel_x = 0;
    }
}

void z_hard_stop_actor_h(ZAP_ACTOR *actor)
{
    actor->vel_x = 0;
}

void z_stop_actor_v(ZAP_ACTOR *actor)
{
    actor->vel_y = 0;
}

void z_move_actor_right(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_y = 0;
    actor->vel_x = actor->max_speed;
}

void z_move_actor_left(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_y = 0;
    actor->vel_x = -actor->max_speed;
}

void z_move_actor_up(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_x = 0;
    actor->vel_y = -actor->max_speed;
}

void z_move_actor_down(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_x = 0;
    actor->vel_y = actor->max_speed;
}

void z_apply_actor_gravity(ZAP_ACTOR *actor)
{
    actor->vel_y += actor->gravity;
    if (actor->vel_y > actor->max_vel_y)
    {
        actor->vel_y = actor->max_vel_y;
    }
}

void z_actor_jump(ZAP_ACTOR *actor)
{
    actor->vel_y = -actor->jump_strength;
}

void z_update_actor_movement(ZAP_ACTOR *actor)
{
    actor->x += actor->vel_x;
    actor->y += actor->vel_y;
    _set_actor_points(actor);
}

float z_get_actor_x(ZAP_ACTOR *actor)
{
    return actor->x;
}

float z_get_actor_y(ZAP_ACTOR *actor)
{
    return actor->y;
}

void z_set_actor_x(ZAP_ACTOR *actor, int x)
{
    actor->x = x;
    _set_actor_points(actor);
}

void z_set_actor_y(ZAP_ACTOR *actor, int y)
{
    actor->y = y;
    _set_actor_points(actor);
}

float z_get_actor_y_velocity(ZAP_ACTOR *actor)
{
    return actor->vel_y;
}

float z_get_actor_x_velocity(ZAP_ACTOR *actor)
{
    return actor->vel_x;
}

int z_get_actor_direction(ZAP_ACTOR *actor)
{
    return actor->dir;
}

void z_set_actor_acceleration(ZAP_ACTOR *actor, float accel)
{
    actor->acceleration = accel;
}
void z_set_actor_deceleration(ZAP_ACTOR *actor, float decel)
{
    actor->deceleration = decel;
}

void z_set_actor_direction(ZAP_ACTOR *actor, int direction)
{
    actor->dir = direction;
}

float z_get_actor_speed(ZAP_ACTOR *actor)
{
    return actor->max_speed;
}

void z_set_actor_speed(ZAP_ACTOR *actor, float speed)
{
    actor->max_speed = speed;
}


/*
*
*   Built-in movements ?
*
*/
