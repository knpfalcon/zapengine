#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zapengine.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_graphics.h"
#include "zapengine/internal/zintern_game.h"

static ZAP_ACTOR_MODULE_CALLBACK actor_module_list[MAX_ACTOR_TYPES];

//static ZAP_ACTOR *create_actor(ZAP_ACTOR *type, int x, int y, int dir, int id);

static void update_actor_modules(void);

ZAP_ACTOR *_actor_list[MAX_ACTORS];

/* Finds and empty slot in actor list and adds and actor. */
int zap_add_actor(int x, int y, int dir, ZAP_ACTOR *type)
{
    for (int i = 0; i < MAX_ACTORS; i++)
    {
        if (_actor_list[i] != NULL && _actor_list[i]->active == false)
        {
            zlog("Found DEAD actor at %d", i);
            _destroy_actor(_actor_list[i]);
            _actor_list[i] = NULL;
            _actor_list[i] = type;
            _actor_list[i]->id = i;
            return 1;
        }
        else if (_actor_list[i] == NULL)
        {
            zlog("Found NULL actor slot at %d", i);
            _actor_list[i] = type; //Why create an acotor from scratch?? use this type
            _actor_list[i]->id = i;
            return 1;
        }
    }

    zlog("No free actor slots!");
    return 0;
}

/* Removes actor from actor list and sets its old slot to NULL */
int zap_remove_actor(int id)
{
    if (_actor_list[id] == NULL)
    {
        zlog("Actor slot null!");
        return 0;
    }
    else if (_actor_list[id] != NULL)
    {
        if (_actor_list[id]->active)
        {
            _kill_actor(_actor_list, id);
            zlog("Actor %d removed from list. NULL? %s", id, _actor_list[id] == NULL ? "Yes." : "No.");
            return 1;
        }
    }
    return 0;
}

/* // this probably isn't needed now! ///////////////////////////////////////
static ZAP_ACTOR *create_actor(ZAP_ACTOR *type, int x, int y, int dir, int id)
{
    ZAP_ACTOR *actor = type;
    if (actor == NULL) return NULL;

    actor->x = x;
    actor->y = y;

    actor->dir = dir;

    actor->id = id;
    actor->active = true;

    zlog("Actor with ID %d Created.", id);
    zlog("Active = %d", actor->active);

    //_set_actor_points(actor);
    return actor;
}
 */

 /* Destorys an actor, freeing its memory */
void _destroy_actor(ZAP_ACTOR *actor)
{
    if (actor == NULL)
    {
        zlog("Actor was null, returning!");
        return;
    }
    actor->active = false;
    int actor_id = actor->id;
    actor->update = NULL;
    actor->draw = NULL;
    free(actor);
    zlog("Actor %d Destroyed", actor_id);
}

/* Sets an actor's active stats to false but doesn't destory it */
void _kill_actor(ZAP_ACTOR **actor_list, int id)
{
    if (actor_list[id] == NULL)
    {
        zlog("Can't kill actor! Actor was null, returning!");
        return;
    }
    else if (actor_list[id] != NULL && actor_list[id])
    {
        actor_list[id]->active = false;
        zlog("Actor %d killed. Active status set to %d", id, actor_list[id]->active);
    }
}

/* Update all actor modules not specific to their instances*/
static void update_actor_modules(void)
{
    for (int i = 0; i < MAX_ACTOR_TYPES; i++)
    {
        if (actor_module_list[i] == NULL)
        {
            return;
        }
        else if (actor_module_list[i] != NULL)
        {
            actor_module_list[i](i);
        }
    }
}

/* Update all actor instances (selfs) */
void _update_actors()
{
    update_actor_modules();

    for (int i = 0; i < MAX_ACTORS; i++)
    {
        if (_actor_list[i] != NULL)
        {
            if (_actor_list[i]->active == true)
            {
                if (zap_is_point_in_view(_actor_list[i]->x, _actor_list[i]->y, _actor_list[i]->w, _actor_list[i]->h))
                {
                    _actor_list[i]->in_view = true;
                }
                else
                {
                    _actor_list[i]->in_view = false;
                }
                _actor_list[i]->update(_actor_list[i]);
            }
        }
        else return;
    }
}

/* Draws all actors to game view */
void _draw_actors()
{
    for (int i = 0; i < MAX_ACTORS; i++)
    {
        if (_actor_list[i] != NULL)
        {
            if (_actor_list[i]->active == true) //&& _actor_list[i]->in_view == true
            {
                _actor_list[i]->draw(_actor_list[i]);
                al_draw_bitmap(_actor_list[i]->sprite->frames[_actor_list[i]->sprite->current_frame], _actor_list[i]->x, _actor_list[i]->y, 0);
            }
        }
        else
            return;
    }
}

/*Registers a function that updates an actor's "module" seperate from its instance.*/
void zap_register_actor_module(ZAP_ACTOR_MODULE_CALLBACK actor_module_update_function)
{
    for (int i = 0; i < MAX_ACTOR_TYPES; i++)
    {
        if (actor_module_list[i] == NULL)
        {
            actor_module_list[i] = actor_module_update_function;
            break;
        }
    }
}
size_t zap_get_actor_type_size()
{
    return sizeof(ZAP_ACTOR);
}

void _zap_destroy_actor_list()
{
    zlog("Destroying Actor List");

    for (int i = 0; i < MAX_ACTORS; i++)
    {
        if (_actor_list[i] == NULL) break;
        _destroy_actor(_actor_list[i]);
        _actor_list[i] = NULL;
    }

}

ZAP_ACTOR *zap_create_empty_actor(void)
{
    zlog("Create Empty Scene");
    ZAP_ACTOR *actor = malloc(sizeof(ZAP_ACTOR));
    memset(actor, 0, sizeof(ZAP_ACTOR));
    actor->active = true;
    if (actor) return actor;
    zlog("Error creating empty actor");
    return NULL;
}

void zap_set_actor_init_func(ZAP_ACTOR *actor, void(*init)(ZAP_ACTOR *self))
{
    actor->init = init;
}
void zap_set_actor_update_func(ZAP_ACTOR *actor, void(*update)(ZAP_ACTOR *self))
{
    actor->update = update;
}
void zap_set_actor_draw_func(ZAP_ACTOR *actor, void(*draw)(ZAP_ACTOR *self))
{
    actor->draw = draw;
}
void zap_set_actor_destroy_func(ZAP_ACTOR *actor, void(*destroy)(ZAP_ACTOR *self))
{
    actor->destroy = destroy;
}
void zap_set_actor_key_down_func(ZAP_ACTOR *actor, void(*on_key_down)(int keycode, ZAP_ACTOR *self))
{
    actor->on_key_down = on_key_down;
}
void zap_set_actor_key_up_func(ZAP_ACTOR *actor, void(*on_key_up)(int keycode, ZAP_ACTOR *self))
{
    actor->on_key_up = on_key_up;
}

void zap_set_actor_type(ZAP_ACTOR *actor, int type)
{
    actor->type = type;
}

int zap_get_actor_type(ZAP_ACTOR *actor)
{
    return actor->type;
}

void zap_set_actor_active(ZAP_ACTOR *actor, bool active)
{
    actor->active = active;
}

void zap_set_actor_sprite(ZAP_ACTOR *actor, ZAP_ACTOR_SPRITE *sprite)
{
    actor->sprite = sprite;
}

void zap_animate_actor(ZAP_ACTOR *actor, int speed, int start_frame, int num_frames)
{
    if (actor->sprite->current_frame == actor->sprite->frame_count - 1)
        actor->sprite->current_frame = 0;

    if (actor->sprite->current_frame == start_frame)
        goto inc_frame;

    if (actor->sprite->current_frame < start_frame || actor->sprite->current_frame >= (start_frame + num_frames))
        actor->sprite->current_frame = start_frame;


inc_frame:
    if (zap_get_drawn_game_frames() % speed == 0)
    {
        if (num_frames > 1) ++actor->sprite->current_frame;
    }
}