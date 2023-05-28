#include <stdlib.h>
#include <time.h>

#include "demo_scene.h"
#include "demo_actor.h"

static char *scene_name = "Demo Scene";

static void init(void);
static void update(void);
static void draw(void);
static void destroy(void);
static void on_key_down(int keycode);
static void on_key_up(int keycode);

static void init(void)
{
    srand(time(0));
    zap_load_actor_sprite("GRAPHICS/SPR_TALLY", 32, 32, 0);
    zap_load_actor_sprite("GRAPHICS/SPR_CREATURES", 32, 32, 1);
    zap_add_actor(32, 32, DIR_RIGHT, demo_actor());
    zap_add_actor(64, 32, DIR_RIGHT, demo_actor());
    zap_add_actor(64, 64, DIR_RIGHT, demo_actor());
    zap_add_actor(128, 128, DIR_RIGHT, demo_actor());
    zap_set_actor_sprite(zap_get_actor(3), zap_get_actor_sprite(1));
    zlog(INFO, "%s initialized!", scene_name);

    zap_set_actor_animation_frames(zap_get_actor(0), 0, 0);
    zap_set_actor_animation_frames(zap_get_actor(1), 1, 4);
    zap_set_actor_animation_frames(zap_get_actor(2), 5, 7);
    zap_set_actor_animation_frames(zap_get_actor(3), 0, 119);

}

static void update(void)
{
    if (zap_get_key_state(28)) zap_set_actor_animation_frames(zap_get_actor(0), 1, 4);
    else if (zap_get_key_state(29)) zap_set_actor_animation_frames(zap_get_actor(0), 5, 7);
    else if (zap_get_key_state(30)) zap_set_actor_animation_frames(zap_get_actor(0), 8, 9);
}

static void draw(void)
{

}

static void destroy(void)
{

}

static void on_key_down(int keycode)
{

}

static void on_key_up(int keycode)
{

}

ZAP_SCENE *demo_scene(void)
{
    zlog(NONE, "Creating %s.", scene_name);
    ZAP_SCENE *scene = zap_create_empty_scene();
    zap_set_scene_name(scene, scene_name);

    zap_set_scene_init_func(scene, init);
    zap_set_scene_update_func(scene, update);
    zap_set_scene_draw_func(scene, draw);
    zap_set_scene_destroy_func(scene, destroy);
    zap_set_scene_key_down_func(scene, on_key_down);
    zap_set_scene_key_up_func(scene, on_key_up);
    zap_scene_use_actors(scene, 1);

    zlog(INFO, "%s Created.", zap_get_scene_name(scene));
    return scene;
}
