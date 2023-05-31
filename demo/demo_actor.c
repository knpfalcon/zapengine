#include <stdlib.h>
#include <time.h>
#include <zapengine/zapengine.h>
#include "data.h"

static void init(ZAP_ACTOR *self);
static void update(ZAP_ACTOR *self);
static void draw(ZAP_ACTOR *self);
static void destroy(ZAP_ACTOR *self);

static void init(ZAP_ACTOR *self)
{
    z_set_actor_builtin_movement(self, E_MOVEMENT_PLAYER_PLATFORM);
    zlog(INFO, "Demo Actor initialized with ID %d.", z_get_actor_id(self));
}

static void update(ZAP_ACTOR *self)
{
    //Set animation frames based on state
    if (z_get_actor_state(self) == E_ACTOR_STATE_WALKING)
        z_set_actor_animation_frames(self, ACTOR_TALLY_ANIM_WALK);
    else if (z_get_actor_state(self) == E_ACTOR_STATE_FALLING)
        z_set_actor_animation_frames(self, ACTOR_TALLY_ANIM_FALL);
    else if (z_get_actor_state(self) == E_ACTOR_STATE_JUMPING)
        z_set_actor_animation_frames(self, ACTOR_TALLY_ANIM_JUMP);
    else if (z_get_actor_state(self) == E_ACTOR_STATE_STOPPED)
        z_set_actor_animation_frames(self, ACTOR_TALLY_ANIM_STOP);
}

static void draw(ZAP_ACTOR *self)
{

}

static void destroy(ZAP_ACTOR *self)
{

}

ZAP_ACTOR *CREATE_ACTOR_TALLY(void)
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
