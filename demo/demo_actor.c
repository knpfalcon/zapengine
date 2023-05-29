#include <stdlib.h>
#include <time.h>
#include "demo_actor.h"

static void init(ZAP_ACTOR *self);
static void update(ZAP_ACTOR *self);
static void draw(ZAP_ACTOR *self);
static void destroy(ZAP_ACTOR *self);

static void init(ZAP_ACTOR *self)
{
    zlog(INFO, "Demo Actor initialized with ID %d.", zap_get_actor_id(self));
}

static void update(ZAP_ACTOR *self)
{
    zap_animate_actor(self, 4);

    zap_update_actor_movement(self);

    while (zap_get_actor_bottom(self) > 200) zap_set_actor_y(self, zap_get_actor_y(self) - 1);
    while (zap_get_actor_top(self) < 0) zap_set_actor_y(self, zap_get_actor_y(self) + 1);
    while (zap_get_actor_right(self) > 320) zap_set_actor_x(self, zap_get_actor_x(self) - 1);
    while (zap_get_actor_left(self) < 1) zap_set_actor_x(self, zap_get_actor_x(self) + 1);

    if (zap_get_actor_right(self) < 320 && zap_get_key_state(zap_get_key(e_key_right)) && !zap_get_key_state(zap_get_key(e_key_left)))
    {
        zap_set_actor_direction(self, DIR_RIGHT);
        zap_move_actor(self, DIR_RIGHT);
        zap_set_actor_state(self, e_state_walking);
    }
    else if (zap_get_actor_left(self) > 1 && zap_get_key_state(zap_get_key(e_key_left)) && !zap_get_key_state(zap_get_key(e_key_right)))
    {
        zap_set_actor_direction(self, DIR_LEFT);
        zap_move_actor(self, DIR_LEFT);
        zap_set_actor_state(self, e_state_walking);

    }
    else if (!zap_get_key_state(zap_get_key(e_key_left)) || !zap_get_key_state(zap_get_key(e_key_right)))
    {
        zap_stop_actor_h(self);
        zap_set_actor_state(self, e_state_stopped);
    }
    else if (zap_get_key_state(zap_get_key(e_key_left)) && zap_get_key_state(zap_get_key(e_key_right)))
    {
        zap_stop_actor_h(self);
        zap_set_actor_state(self, e_state_stopped);
    }

    if (zap_get_actor_bottom(self) == 200)
    {
        zap_stop_actor_v(self);
    }

    if (zap_get_actor_bottom(self) == 200 && zap_get_key_state(zap_get_key(e_key_jump)))
        zap_actor_jump(self);

    if (zap_get_actor_y_velocity(self) >= 0 && zap_get_actor_bottom(self) < 200)
    {
        zap_set_actor_state(self, e_state_falling);
    }
    else if (zap_get_actor_y_velocity(self) < 0)
    {
        zap_set_actor_state(self, e_state_jumping);
    }
    else if (zap_get_actor_y_velocity(self) == 0 && zap_get_actor_state(self) != e_state_walking && zap_get_actor_bottom(self) == 200)
    {
        zap_set_actor_state(self, e_state_stopped);
    }

    //Set animation frames based on state
    if (zap_get_actor_state(self) == e_state_walking)
    {
        zap_set_actor_animation_frames(self, 1, 4);
    }
    else if (zap_get_actor_state(self) == e_state_falling)
    {
        zap_set_actor_animation_frames(self, 6, 6);
    }
    else if (zap_get_actor_state(self) == e_state_jumping)
    {
        zap_set_actor_animation_frames(self, 5, 5);
    }
    else if (zap_get_actor_state(self) == e_state_stopped)
    {
        zap_set_actor_animation_frames(self, 0, 0);
    }

    zap_apply_actor_gravity(self);
}


static void draw(ZAP_ACTOR *self)
{

}

static void destroy(ZAP_ACTOR *self)
{

}


ZAP_ACTOR *demo_actor(void)
{
    zlog(NONE, "Creating Demo Actor.");
    ZAP_ACTOR *actor = zap_create_empty_actor();

    zap_set_actor_init_func(actor, init);
    zap_set_actor_update_func(actor, update);
    zap_set_actor_draw_func(actor, draw);
    zap_set_actor_destroy_func(actor, destroy);
    z_set_actor_type(actor, 0);
    zap_set_actor_sprite(actor, zap_get_actor_sprite(zap_get_actor_type(actor)));

    zlog(INFO, "Demo Actor Created.");
    return actor;
}
