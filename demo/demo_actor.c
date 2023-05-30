#include <stdlib.h>
#include <time.h>
#include "demo_actor.h"

static void init(ZAP_ACTOR *self);
static void update(ZAP_ACTOR *self);
static void draw(ZAP_ACTOR *self);
static void destroy(ZAP_ACTOR *self);
static void update_movement(ZAP_ACTOR *self);

static void init(ZAP_ACTOR *self)
{
    zlog(INFO, "Demo Actor initialized with ID %d.", z_get_actor_id(self));
}

static void update(ZAP_ACTOR *self)
{
    update_movement(self);
}


static void draw(ZAP_ACTOR *self)
{

}

static void destroy(ZAP_ACTOR *self)
{

}

static void update_movement(ZAP_ACTOR *self)
{
    z_update_actor_movement(self);
    z_animate_actor(self, 6);
    z_apply_actor_gravity(self);

    while (z_get_actor_bottom(self) > 200) z_set_actor_y(self, z_get_actor_y(self) - 1);
    while (z_get_actor_top(self) < 0) z_set_actor_y(self, z_get_actor_y(self) + 1);
    while (z_get_actor_right(self) > 320) z_set_actor_x(self, z_get_actor_x(self) - 1);
    while (z_get_actor_left(self) < 0) z_set_actor_x(self, z_get_actor_x(self) + 1);

    if (z_get_actor_right(self) < 320 && z_get_key_state(z_get_key(e_key_right)) && !z_get_key_state(z_get_key(e_key_left)))
    {
        z_set_actor_direction(self, DIR_RIGHT);
        z_move_actor(self, DIR_RIGHT);
        z_set_actor_state(self, e_state_walking);
    }
    else if (z_get_actor_left(self) > 1 && z_get_key_state(z_get_key(e_key_left)) && !z_get_key_state(z_get_key(e_key_right)))
    {
        z_set_actor_direction(self, DIR_LEFT);
        z_move_actor(self, DIR_LEFT);
        z_set_actor_state(self, e_state_walking);

    }
    else if (!z_get_key_state(z_get_key(e_key_left)) || !z_get_key_state(z_get_key(e_key_right)))
    {

        z_stop_actor_h(self);
        if (z_get_actor_x_velocity(self) == 0) z_set_actor_state(self, e_state_stopped);
    }
    else if (z_get_key_state(z_get_key(e_key_left)) && z_get_key_state(z_get_key(e_key_right)))
    {

        z_stop_actor_h(self);
        if (z_get_actor_x_velocity(self) == 0) z_set_actor_state(self, e_state_stopped);
    }

    if (z_get_actor_bottom(self) == 200)
    {
        z_set_actor_acceleration(self, z_get_actor_speed(self) * 0.2);
        z_set_actor_deceleration(self, z_get_actor_speed(self) * 0.2);
        z_stop_actor_v(self);
    }

    if (z_get_actor_bottom(self) == 200 && z_get_key_state(z_get_key(e_key_jump)))
    {
        z_set_actor_acceleration(self, ACCELERATION_DEFAULT);
        z_set_actor_deceleration(self, DECELERATION_DEFAULT);
        z_actor_jump(self);
    }

    if (z_get_actor_y_velocity(self) >= 0 && z_get_actor_bottom(self) < 200)
    {
        z_set_actor_state(self, e_state_falling);
    }
    else if (z_get_actor_y_velocity(self) < 0)
    {
        z_set_actor_state(self, e_state_jumping);
    }
    else if (z_get_actor_y_velocity(self) == 0 && z_get_actor_state(self) != e_state_walking && z_get_actor_bottom(self) == 200)
    {
        z_set_actor_state(self, e_state_stopped);
    }

    //Set animation frames based on state
    if (z_get_actor_state(self) == e_state_walking)
    {
        z_set_actor_animation_frames(self, 1, 4);
    }
    else if (z_get_actor_state(self) == e_state_falling)
    {
        z_set_actor_animation_frames(self, 6, 6);
    }
    else if (z_get_actor_state(self) == e_state_jumping)
    {
        z_set_actor_animation_frames(self, 5, 5);
    }
    else if (z_get_actor_state(self) == e_state_stopped)
    {
        z_set_actor_animation_frames(self, 0, 0);
    }
}

ZAP_ACTOR *demo_actor(void)
{
    zlog(NONE, "Creating Demo Actor.");
    ZAP_ACTOR *actor = z_create_empty_actor();

    z_set_actor_init_func(actor, init);
    z_set_actor_update_func(actor, update);
    z_set_actor_draw_func(actor, draw);
    z_set_actor_destroy_func(actor, destroy);
    z_set_actor_type(actor, 0);
    z_set_actor_sprite(actor, z_get_actor_sprite(z_get_actor_type(actor)));

    zlog(INFO, "Demo Actor Created.");
    return actor;
}
