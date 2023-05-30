#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "zapengine/zapengine.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_sprite.h"
#include "zapengine/internal/zintern_controls.h"

static ZAP_ACTOR_MODULE_CALLBACK actor_module_list[MAX_ACTOR_TYPES];

static void update_actor_modules(void);

ZAP_ACTOR *_actor_list[MAX_ACTORS];

/* Finds and empty slot (NULL or inactive) in actor list and adds and actor. */
int z_add_actor(int x, int y, int dir, ZAP_ACTOR *type)
{
    zlog(NONE, "Adding actor of type %d", type->type);
    for (int i = 0; i < MAX_ACTORS; i++)
    {
        if (_actor_list[i] != NULL && _actor_list[i]->active == false)
        {
            zlog(INFO, "Found DEAD actor at %d", i);
            _destroy_actor(_actor_list[i]);
            _actor_list[i] = NULL;
            _actor_list[i] = type;
            _actor_list[i]->id = i;
            _actor_list[i]->init(_actor_list[i]);
            _actor_list[i]->x = x;
            _actor_list[i]->y = y;
            _actor_list[i]->dir = dir;
            return 1;
        }
        else if (_actor_list[i] == NULL)
        {
            zlog(INFO, "Found NULL actor slot at %d", i);
            _actor_list[i] = type; //Why create an acotor from scratch?? use this type
            _actor_list[i]->id = i;
            _actor_list[i]->init(_actor_list[i]);
            _actor_list[i]->x = x;
            _actor_list[i]->y = y;
            _actor_list[i]->dir = dir;
            return 1;
        }
    }

    zlog(WARN, "No free actor slots!");
    return 0;
}

/* Removes actor from actor list and sets its active status to false */
int z_remove_actor(int id)
{
    zlog(NONE, "Removing actor %d", id);
    if (_actor_list[id] == NULL)
    {
        zlog(WARN, "Actor slot null!");
        return 0;
    }
    else if (_actor_list[id] != NULL)
    {
        if (_actor_list[id]->active)
        {
            _kill_actor(_actor_list, id);
            zlog(INFO, "Actor %d removed from list. NULL? %s", id, _actor_list[id] == NULL ? "Yes." : "No.");
            return 1;
        }
    }
    return 0;
}

/* Destorys an actor, freeing its memory */
void _destroy_actor(ZAP_ACTOR *actor)
{
    zlog(NONE, "Destroying Actor %d", actor->id);
    if (actor == NULL)
    {
        zlog(WARN, "Actor was null, returning!");
        return;
    }
    actor->active = false;
    int actor_id = actor->id;
    actor->update = NULL;
    actor->draw = NULL;
    free(actor);
    zlog(INFO, "Actor %d Destroyed", actor_id);
}

/* Sets an actor's active stats to false but doesn't destory it */
void _kill_actor(ZAP_ACTOR **actor_list, int id)
{
    zlog(NONE, "Killing Actor %d", id);
    if (actor_list[id] == NULL)
    {
        zlog(WARN, "Can't kill actor! Actor was null, returning!");
        return;
    }
    else if (actor_list[id] != NULL && actor_list[id])
    {
        actor_list[id]->active = false;
        zlog(INFO, "Actor %d killed. Active status set to %d", id, actor_list[id]->active);
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
                if (z_is_point_in_view(_actor_list[i]->x, _actor_list[i]->y, _actor_list[i]->w, _actor_list[i]->h))
                {
                    _actor_list[i]->in_view = true;
                }
                else
                {
                    _actor_list[i]->in_view = false;
                }

                //Update built-in movements
                switch (_actor_list[i]->movement_type)
                {
                case e_movement_player_platform:
                    _update_player_platform_movement(_actor_list[i]);
                    break;
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
                if (_actor_list[i]->dir == DIR_RIGHT)
                    al_draw_bitmap(_actor_list[i]->sprite->frames[_actor_list[i]->current_frame], (int)_actor_list[i]->x, (int)_actor_list[i]->y, 0);
                else
                    al_draw_bitmap(_actor_list[i]->sprite->frames[_actor_list[i]->current_frame], (int)_actor_list[i]->x, (int)_actor_list[i]->y, ALLEGRO_FLIP_HORIZONTAL);
            #ifdef DEBUG
                al_draw_rectangle(_actor_list[i]->left, _actor_list[i]->top, _actor_list[i]->right, _actor_list[i]->bottom, al_map_rgb(255, 0, 0), 1);
            #endif
            }
        }
        else
            return;
    }
}

/*Registers a function that updates an actor's "module" seperate from its instance.*/
void z_register_actor_module(ZAP_ACTOR_MODULE_CALLBACK actor_module_update_function)
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

void _destroy_actor_list()
{
    zlog(NONE, "Destroying Actor List");

    for (int i = 0; i < MAX_ACTORS; i++)
    {
        if (_actor_list[i] == NULL) break;
        _destroy_actor(_actor_list[i]);
        _actor_list[i] = NULL;
    }
    zlog(INFO, "Actor List Destroyed");
    _destroy_sprites();
}

ZAP_ACTOR *z_create_empty_actor(void)
{
    zlog(NONE, "Creating Empty Actor.");
    ZAP_ACTOR *actor = malloc(sizeof(ZAP_ACTOR));
    memset(actor, 0, sizeof(ZAP_ACTOR));
    actor->active = true;
    actor->max_speed = MAX_SPEED_DEFAULT;
    actor->dir = DIR_RIGHT;
    actor->gravity = GRAVITY_DEFAULT;
    actor->jump_strength = JUMP_STRENGTH_DEFAULT;
    actor->max_vel_y = MAX_VEL_Y_DEFAULT;
    actor->acceleration = ACCELERATION_DEFAULT;
    actor->deceleration = DECELERATION_DEFAULT;
    actor->w = 32;
    actor->h = 32;
    actor->movement_type = e_movement_none;
    z_set_actor_box(actor, 12, 12, 6, 0);
    if (actor) return actor;
    zlog(FAIL, "Couldn't create empty actor");
    return NULL;
}

void z_set_actor_init_func(ZAP_ACTOR *actor, void(*init)(ZAP_ACTOR *self))
{
    actor->init = init;
}

void z_set_actor_update_func(ZAP_ACTOR *actor, void(*update)(ZAP_ACTOR *self))
{
    actor->update = update;
}

void z_set_actor_draw_func(ZAP_ACTOR *actor, void(*draw)(ZAP_ACTOR *self))
{
    actor->draw = draw;
}

void z_set_actor_destroy_func(ZAP_ACTOR *actor, void(*destroy)(ZAP_ACTOR *self))
{
    actor->destroy = destroy;
}

void z_set_actor_type(ZAP_ACTOR *actor, int type)
{
    actor->type = type;
}

int z_get_actor_type(ZAP_ACTOR *actor)
{
    return actor->type;
}

void z_set_actor_active(ZAP_ACTOR *actor, bool active)
{
    actor->active = active;
}

void z_set_actor_sprite(ZAP_ACTOR *actor, ZAP_ACTOR_SPRITE *sprite)
{
    if (sprite && actor)
    {
        zlog(NONE, "Changing Actor %d's sprite.", actor->id);
        actor->sprite = sprite;
    }
    else
    {
        zlog(WARN, "Cannot change Actor %d's sprite!", actor->id);
        return;
    }
}

void z_set_actor_animation_frames(ZAP_ACTOR *actor, int start_frame, int end_frame)
{
    if (!actor)
    {
        zlog(WARN, "Can't set actor animations frames! No actor with ID specified.");
        return;
    }
    //Check if animation is already set. If it's the same animation, return.
    if (actor->start_frame == start_frame && actor->end_frame == end_frame)
        return;

    actor->start_frame = start_frame;
    actor->end_frame = end_frame;
    actor->current_frame = start_frame;
    zlog(INFO, "Actor %d animation frames set to START: %d, END: %d.", actor->id, actor->start_frame, actor->end_frame);
}
void z_animate_actor(ZAP_ACTOR *actor, int speed)
{

    if (z_get_drawn_game_frames() % speed == 0)
    {
        if (actor->current_frame < actor->end_frame)
            actor->current_frame++;
        else
            actor->current_frame = actor->start_frame;
    }
}


void z_set_actor_state(ZAP_ACTOR *actor, int state)
{
    actor->state = state;
}

int z_get_actor_state(ZAP_ACTOR *actor)
{
    return actor->state;
}

ZAP_ACTOR *z_get_actor(int id)
{
    if (_actor_list[id])
        return _actor_list[id];

    zlog(WARN, "Cannot get actor. No actor exists with ID %d.", id);
    return NULL;
}

int z_get_actor_id(ZAP_ACTOR *actor)
{
    if (actor)
    {
        return actor->id;
    }

    zlog(WARN, "Cannot get actor ID. Actor doesn't exist.");
    return -1;
}

void z_set_actor_builtin_movement(ZAP_ACTOR *actor, int type)
{
    actor->movement_type = type;
}
