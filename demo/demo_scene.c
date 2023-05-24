#include "demo_scene.h"
#include "demo_actor.h"

char *scene_name = "Demo Scene";

static void init(void);
static void update(void);
static void draw(void);
static void destroy(void);
static void on_key_down(int keycode);
static void on_key_up(int keycode);

static void init(void)
{
    zap_load_actor_sprite("GRAPHICS/SPR_TALLY", 32, 32, 0);
    zap_add_actor(32, 32, DIR_RIGHT, demo_actor());
    zlog("%s initialized!", scene_name);
}

static void update(void)
{

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
    zlog("DEMO SCENE CREATE begin.");
    ZAP_SCENE *scene = zap_create_empty_scene();
    zap_set_scene_name(scene, scene_name);

    zap_set_scene_init_func(scene, init);
    zap_set_scene_update_func(scene, update);
    zap_set_scene_draw_func(scene, draw);
    zap_set_scene_destroy_func(scene, destroy);
    zap_set_scene_key_down_func(scene, on_key_down);
    zap_set_scene_key_up_func(scene, on_key_up);
    zap_scene_use_actors(scene, 1);

    zlog("%s Created.", scene_name);
    return scene;
}