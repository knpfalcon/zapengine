#include "zapengine/internal/zintern_movement.h"

static void _set_actor_points(ZAP_ACTOR *actor)
{
    actor->x_center = (actor->w >> 1) + actor->x;
    actor->y_center = (actor->h >> 1) + actor->y;

    actor->left = actor->x + 8;
    actor->right = actor->w - 8 + actor->x;
    actor->bottom = actor->y + actor->h;
    actor->top = actor->y + 8;
}

void zap_move_actor_right(ZAP_ACTOR *actor)
{
    actor->dir = DIR_RIGHT;
    actor->vel_x = actor->speed;
}

void zap_move_actor_left(ZAP_ACTOR *actor)
{
    actor->dir = DIR_LEFT;
    actor->vel_x = -actor->speed;
}

void zap_move_actor_up(ZAP_ACTOR *actor)
{
    actor->dir = DIR_UP;
    actor->vel_y = actor->speed;

}

void zap_move_actor_down(ZAP_ACTOR *actor)
{
    actor->dir = DIR_DOWN;
    actor->vel_y = -actor->speed;
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
    //zap_apply_actor_gravity(actor);
}