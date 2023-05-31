#include <stdlib.h>
#include <time.h>
#include "demo_scene.h"
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
    z_load_actor_sprite(ACTOR_000_TALLY_FILE, 32, 32, ACTOR_000_TALLY);
    z_load_actor_sprite(ACTOR_001_CREATURES_FILE, 32, 32, ACTOR_001_CREATURES);
    z_add_actor(32, 32, DIR_RIGHT, CREATE_ACTOR_000_TALLY());

    zlog(INFO, "%s initialized!", scene_name);


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
