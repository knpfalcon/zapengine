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
    //if (zap_get_drawn_game_frames() % 50 == 0) zap_set_actor_direction(self, rand() % 4);

    if (zap_is_touching(self, zap_get_actor(3)) && zap_get_actor(3) != self)
    {
        zap_set_actor_direction(self, rand() % 4);
        zap_set_actor_direction(zap_get_actor(3), rand() % 4);
    }
    if (zap_get_actor_bottom(self) > 200) zap_set_actor_direction(self, DIR_UP);
    else if (zap_get_actor_top(self) < 0) zap_set_actor_direction(self, DIR_DOWN);
    else if (zap_get_actor_right(self) > 320) zap_set_actor_direction(self, DIR_LEFT);
    else if (zap_get_actor_left(self) < 0) zap_set_actor_direction(self, DIR_RIGHT);

    if (zap_get_actor_direction(self) == DIR_RIGHT) zap_move_actor_right(self);
    if (zap_get_actor_direction(self) == DIR_LEFT) zap_move_actor_left(self);
    if (zap_get_actor_direction(self) == DIR_UP) zap_move_actor_up(self);
    if (zap_get_actor_direction(self) == DIR_DOWN) zap_move_actor_down(self);


    zap_update_actor_movement(self);
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