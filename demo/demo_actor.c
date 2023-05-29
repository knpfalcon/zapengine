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
    srand(time(0));
}

static void update(ZAP_ACTOR *self)
{
    //if (zap_get_drawn_game_frames() % 50 == 0) zap_set_actor_direction(self, rand() % 4);
    zap_update_actor_movement(self);
    while (zap_get_actor_bottom(self) > 200) zap_set_actor_y(self, zap_get_actor_y(self) - 1);
    while (zap_get_actor_top(self) < 0) zap_set_actor_y(self, zap_get_actor_y(self) + 1);
    while (zap_get_actor_right(self) > 320) zap_set_actor_x(self, zap_get_actor_x(self) - 1);
    while (zap_get_actor_left(self) < 0) zap_set_actor_x(self, zap_get_actor_x(self) + 1);
    if (zap_get_actor_bottom(self) == 200)
    {
        zap_set_actor_direction(self, (rand() % 3) - 1);
        if (zap_get_actor_direction(self) < 0) zap_set_actor_direction(self, 7);
    }
    else if (zap_get_actor_top(self) == 0)
    {
        zap_set_actor_direction(self, (rand() % 3) + 3);
    }
    else if (zap_get_actor_right(self) == 320)
    {
        zap_set_actor_direction(self, ((rand() % 3) + 5));
    }
    else if (zap_get_actor_left(self) == 0)
    {
        zap_set_actor_direction(self, (rand() % 3) + 1);
    }

    if (zap_get_actor_direction(self) == DIR_RIGHT) zap_move_actor(self, DIR_RIGHT);
    if (zap_get_actor_direction(self) == DIR_DOWN_RIGHT) zap_move_actor(self, DIR_DOWN_RIGHT);
    if (zap_get_actor_direction(self) == DIR_DOWN) zap_move_actor(self, DIR_DOWN);
    if (zap_get_actor_direction(self) == DIR_DOWN_LEFT) zap_move_actor(self, DIR_DOWN_LEFT);
    if (zap_get_actor_direction(self) == DIR_LEFT) zap_move_actor(self, DIR_LEFT);
    if (zap_get_actor_direction(self) == DIR_UP_LEFT) zap_move_actor(self, DIR_UP_LEFT);
    if (zap_get_actor_direction(self) == DIR_UP_RIGHT) zap_move_actor(self, DIR_UP_RIGHT);


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
    zlog(NONE, "Creating Demo Actor.");
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
