#include "zapengine/internal/zintern_movement.h"

static void _set_actor_points(ZAP_ACTOR *actor)
{
    actor->x_center = (actor->w >> 1) + actor->x;
    actor->y_center = (actor->h >> 1) + actor->y;

    actor->left = actor->x + actor->bbl;
    actor->right = actor->x + actor->w - actor->bbr;
    actor->bottom = actor->y + actor->h - actor->bbb;
    actor->top = actor->y + actor->bbt;
}

void zap_move_actor_right(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_y = 0;
    actor->vel_x = actor->speed;
}

void zap_move_actor_left(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_y = 0;
    actor->vel_x = -actor->speed;
}

void zap_move_actor_up(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_x = 0;
    actor->vel_y = -actor->speed;
}

void zap_move_actor_down(ZAP_ACTOR *actor)
{
    if (!actor->platform_movement) actor->vel_x = 0;
    actor->vel_y = actor->speed;
}

void zap_apply_actor_gravity(ZAP_ACTOR *actor)
{
    actor->vel_y += actor->gravity;
    if (actor->vel_y > actor->max_vel_y)
    {
        actor->vel_y = actor->max_vel_y;
    }
}

void zap_actor_jump(ZAP_ACTOR *actor)
{
    actor->vel_y = -actor->jump_strength;
}

void zap_update_actor_movement(ZAP_ACTOR *actor)
{
    actor->x += actor->vel_x;
    actor->y += actor->vel_y;
    _set_actor_points(actor);
}

int zap_get_actor_x(ZAP_ACTOR *actor)
{
    return actor->x;
}

int zap_get_actor_y(ZAP_ACTOR *actor)
{
    return actor->y;
}

int zap_get_actor_center_x(ZAP_ACTOR *actor)
{
    return actor->x_center;
}

int zap_get_actor_center_y(ZAP_ACTOR *actor)
{
    return actor->y_center;
}

void zap_set_actor_box(ZAP_ACTOR *actor, int left, int right, int top, int bottom)
{
    actor->bbl = left;
    actor->bbr = right;
    actor->bbt = top;
    actor->bbb = bottom;
}

int zap_get_actor_direction(ZAP_ACTOR *actor)
{
    return actor->dir;
}

void zap_set_actor_direction(ZAP_ACTOR *actor, int direction)
{
    actor->dir = direction;
}

int zap_get_actor_speed(ZAP_ACTOR *actor)
{
    return actor->speed;
}

void zap_set_actor_speed(ZAP_ACTOR *actor, int speed)
{
    actor->speed = speed;
}

int zap_get_actor_left(ZAP_ACTOR *actor)
{
    return actor->left;
}
int zap_get_actor_right(ZAP_ACTOR *actor)
{
    return actor->right;
}
int zap_get_actor_top(ZAP_ACTOR *actor)
{
    return actor->top;
}
int zap_get_actor_bottom(ZAP_ACTOR *actor)
{
    return actor->bottom;
}
/* Getters and Setters that need to be implemented:
*
*
*
*/
