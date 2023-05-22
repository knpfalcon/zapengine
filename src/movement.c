#include "zapengine/internal/zintern_movement.h""

void move_right(ZAP_ACTOR *actor)
{
    actor->dir = DIR_RIGHT;
    actor->x += actor->vel_x;
    set_actor_points(actor);

}

void move_left(ZAP_ACTOR *actor)
{
    actor->dir = DIR_LEFT;
    actor->x -= actor->vel_x;
    set_actor_points(actor);
}

void move_up(ZAP_ACTOR *actor)
{
    actor->dir = DIR_UP;
    actor->y -= actor->vel_y;
    set_actor_points(actor);

}

void move_down(ZAP_ACTOR *actor)
{
    actor->dir = DIR_DOWN;
    actor->y += actor->vel_y;
    set_actor_points(actor);
}

void apply_gravity(ZAP_ACTOR *actor)
{
    actor->y += actor->vel_y;
    actor->vel_y += actor->gravity;
    if (actor->vel_y > actor->max_vel_y)
        actor->vel_y = actor->max_vel_y;
    set_actor_points(actor);
}

void jump(ZAP_ACTOR *actor)
{
    actor->vel_y = -actor->jump_strength;
    set_actor_points(actor);
}

void set_actor_points(ZAP_ACTOR *actor)
{
    actor->x_center = (actor->w >> 1) + actor->x;
    actor->y_center = (actor->h >> 1) + actor->y;

    actor->left = actor->x + 8;
    actor->right = actor->w - 8 + actor->x;
    actor->bottom = actor->y + actor->h;
    actor->top = actor->y + 8;
}
