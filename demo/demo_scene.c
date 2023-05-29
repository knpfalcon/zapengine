#include <stdlib.h>
#include <time.h>

#include "demo_scene.h"
#include "demo_actor.h"
#include "data.h"

static char *scene_name = "Demo Scene";

static void init(void);
static void update(void);
static void draw(void);
static void destroy(void);
static void on_key_down(int keycode);
static void on_key_up(int keycode);

static void init(void)
{
    z_load_actor_sprite("GRAPHICS/SPR_TALLY", 32, 32, 0);
    z_load_actor_sprite("GRAPHICS/SPR_CREATURES", 32, 32, 1);
    z_add_actor(32, 32, DIR_RIGHT, demo_actor());

    zlog(INFO, "%s initialized!", scene_name);


}

static void update(void)
{
    if (z_get_key_state(28)) z_set_actor_animation_frames(z_get_actor(0), 1, 4);
    else if (z_get_key_state(29)) z_set_actor_animation_frames(z_get_actor(0), 5, 7);
    else if (z_get_key_state(30)) z_set_actor_animation_frames(z_get_actor(0), 8, 9);
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
    z_set_scene_name(scene, scene_name);

    z_set_scene_init_func(scene, init);
    z_set_scene_update_func(scene, update);
    z_set_scene_draw_func(scene, draw);
    z_set_scene_destroy_func(scene, destroy);
    z_set_scene_key_down_func(scene, on_key_down);
    z_set_scene_key_up_func(scene, on_key_up);
    z_scene_use_actors(scene, 1);

    zlog(INFO, "%s Created.", z_get_scene_name(scene));
    return scene;
}
