#include "zapengine/internal/zintern_movement.h"
#include "zapengine/internal/zintern_controls.h"
#include "zapengine/internal/zintern_collision.h"

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
        if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_y = 0;
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
        if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_x = 0;
        actor->vel_y = actor->max_speed;
        break;
    case DIR_DOWN_LEFT:
        actor->vel_x = -actor->max_speed / DIAGONAL_MOVE;
        actor->vel_y = actor->max_speed / DIAGONAL_MOVE;
        break;
    case DIR_LEFT:
        if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_y = 0;
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
        if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_x = 0;
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
    if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_y = 0;
    actor->vel_x = actor->max_speed;
}

void z_move_actor_left(ZAP_ACTOR *actor)
{
    if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_y = 0;
    actor->vel_x = -actor->max_speed;
}

void z_move_actor_up(ZAP_ACTOR *actor)
{
    if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_x = 0;
    actor->vel_y = -actor->max_speed;
}

void z_move_actor_down(ZAP_ACTOR *actor)
{
    if (actor->movement_type != E_MOVEMENT_PLAYER_PLATFORM) actor->vel_x = 0;
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
*   Each of these should probably go into their own modules eventually.
*/

void _update_player_platform_movement(ZAP_ACTOR *actor)
{
    z_animate_actor(actor, 6);
    z_update_actor_movement(actor);
    z_apply_actor_gravity(actor);

    //If actor is somehow inside ground pull it out before moving on.
    while (z_get_actor_bottom(actor) > 200) z_set_actor_y(actor, z_get_actor_y(actor) - 1);
    while (z_get_actor_top(actor) < 0) z_set_actor_y(actor, z_get_actor_y(actor) + 1);
    while (z_get_actor_right(actor) > 320) z_set_actor_x(actor, z_get_actor_x(actor) - 1);
    while (z_get_actor_left(actor) < 0) z_set_actor_x(actor, z_get_actor_x(actor) + 1);

    //When keys are pressed or not pressed
    if (z_get_actor_right(actor) < 320 && z_get_key_state(z_get_key(E_KEY_RIGHT)) && !z_get_key_state(z_get_key(E_KEY_LEFT)))
    {
        z_set_actor_direction(actor, DIR_RIGHT);
        z_move_actor(actor, DIR_RIGHT);
        z_set_actor_state(actor, E_ACTOR_STATE_WALKING);
    }
    else if (z_get_actor_left(actor) > 1 && z_get_key_state(z_get_key(E_KEY_LEFT)) && !z_get_key_state(z_get_key(E_KEY_RIGHT)))
    {
        z_set_actor_direction(actor, DIR_LEFT);
        z_move_actor(actor, DIR_LEFT);
        z_set_actor_state(actor, E_ACTOR_STATE_WALKING);
    }
    else if (!z_get_key_state(z_get_key(E_KEY_LEFT)) || !z_get_key_state(z_get_key(E_KEY_RIGHT)))
    {
        z_stop_actor_h(actor);
        if (z_get_actor_x_velocity(actor) == 0)
            z_set_actor_state(actor, E_ACTOR_STATE_STOPPED);
    }
    else if (z_get_key_state(z_get_key(E_KEY_LEFT)) && z_get_key_state(z_get_key(E_KEY_RIGHT)))
    {
        z_stop_actor_h(actor);
        if (z_get_actor_x_velocity(actor) == 0)
            z_set_actor_state(actor, E_ACTOR_STATE_STOPPED);
    }

    //Raise Acceleration and Decelerations rates if on ground
    if (z_get_actor_bottom(actor) == 200)
    {
        z_set_actor_acceleration(actor, z_get_actor_speed(actor) * 0.2);
        z_set_actor_deceleration(actor, z_get_actor_speed(actor) * 0.2);
        z_stop_actor_v(actor);
    }

    //On ground level and presses jump key
    if (z_get_actor_bottom(actor) == 200 && z_get_key_state(z_get_key(E_KEY_JUMP)))
    {
        z_set_actor_acceleration(actor, ACCELERATION_DEFAULT);
        z_set_actor_deceleration(actor, DECELERATION_DEFAULT);
        z_actor_jump(actor);
    }

    //Set states based on certain conditions
    if (z_get_actor_y_velocity(actor) >= 0 && z_get_actor_bottom(actor) < 200)
        z_set_actor_state(actor, E_ACTOR_STATE_FALLING);
    else if (z_get_actor_y_velocity(actor) < 0)
        z_set_actor_state(actor, E_ACTOR_STATE_JUMPING);
    else if (z_get_actor_y_velocity(actor) == 0 && z_get_actor_state(actor) != E_ACTOR_STATE_WALKING && z_get_actor_bottom(actor) == 200)
        z_set_actor_state(actor, E_ACTOR_STATE_STOPPED);


}
