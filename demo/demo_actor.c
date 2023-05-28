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
}

static void draw(ZAP_ACTOR *self)
{

}

static void destroy(ZAP_ACTOR *self)
{

}


ZAP_ACTOR *demo_actor(void)
{
    zlog(LOAD, "Creating Demo Actor.");
    ZAP_ACTOR *actor = zap_create_empty_actor();

    zap_set_actor_init_func(actor, init);
    zap_set_actor_update_func(actor, update);
    zap_set_actor_draw_func(actor, draw);
    zap_set_actor_destroy_func(actor, destroy);
    zap_set_actor_type(actor, 0);
    zap_set_actor_sprite(actor, zap_get_actor_sprite(zap_get_actor_type(actor)));

    zlog(INFO, "Demo Actor Created.");
    return actor;
}