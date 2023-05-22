#ifndef ZINTERN_ACTOR_H
#define ZINTERN_ACTOR_H

#include "actor.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct ZAP_ACTOR
    {
        //temporary
        bool touching;
        bool active;
        bool in_view;

        bool jumping;

        int id;

        char *name;

        int x;
        int y;
        int vel_x;
        int vel_y;
        int max_vel_y;
        int jump_strength;
        int gravity;
        int dir;

        int w;
        int h;

        int right;
        int left;
        int top;
        int bottom;

        int x_center;
        int y_center;

        int health;

        int r, g, b;

        //struct ALLEGRO_BITMAP *current_frame;

        void (*update)(void *self);
        void (*draw)(void *self);
    };

    void _kill_actor(ZAP_ACTOR **actor_list, int id);
    void _destroy_actor(ZAP_ACTOR *actor);
    void _zap_destroy_actor_list();
    void _zap_set_actor_list(ZAP_ACTOR **actor_list);
    void _draw_actors();
    void _update_actors();

#ifdef __cplusplus
}
#endif

#endif