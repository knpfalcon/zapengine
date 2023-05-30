#include <stdlib.h>
#include <time.h>
#include "demo_actor.h"

static void init(ZAP_ACTOR *self);
static void update(ZAP_ACTOR *self);
static void draw(ZAP_ACTOR *self);
static void destroy(ZAP_ACTOR *self);

static void init(ZAP_ACTOR *self)
{
    z_set_actor_builtin_movement(self, e_movement_player_platform);
    zlog(INFO, "Demo Actor initialized with ID %d.", z_get_actor_id(self));
}

static void update(ZAP_ACTOR *self)
{

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
