#ifndef ZINTERN_ACTOR_H
#define ZINTERN_ACTOR_H

#include "actor.h"
#include "zapengine/internal/zintern_sprite.h"

#ifdef __cplusplus
extern "C" {
#endif
    extern ZAP_ACTOR *_actor_list[MAX_ACTORS];

    extern ZAP_ACTOR_SPRITE *_actor_sprites[MAX_ACTOR_TYPES];

    enum _ACTOR_STATE { WALKING, JUMPING, FALLING };

    struct ZAP_ACTOR
    {
        char *name;

        bool active;
        bool in_view;
        bool platform_movement;

        int type;
        int id;

        int state;

        float x;
        float y;
        float speed;
        float vel_x;
        float vel_y;
        float max_vel_y;
        float jump_strength;
        float gravity;
        int dir;

        int w;
        int h;

        int bbr, bbl, bbt, bbb;

        int right;
        int left;
        int top;
        int bottom;

        int x_center;
        int y_center;

        int health;

        int current_frame;
        int start_frame;
        int end_frame;
        struct ZAP_ACTOR_SPRITE *sprite;

        void(*init)(ZAP_ACTOR *self);
        void(*update)(ZAP_ACTOR *self);
        void(*draw)(ZAP_ACTOR *self);
        void(*destroy)(ZAP_ACTOR *self);
    };

    void _kill_actor(ZAP_ACTOR **actor_list, int id);
    void _destroy_actor(ZAP_ACTOR *actor);
    void _destroy_actor_list();
    void _zap_set_actor_list(ZAP_ACTOR **actor_list); //not needed. prune.
    void _draw_actors();
    void _update_actors();

#ifdef __cplusplus
}
#endif

#endif