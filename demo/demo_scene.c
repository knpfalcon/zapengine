#include "demo_scene.h"

char *scene_name = "Template Scene";

static void init(void);
static void update(void);
static void draw(void);
static void destroy(void);
static void on_key_down(int keycode);
static void on_key_up(int keycode);

static void init(void)
{
    zlog("%s initialized!", scene_name);
}

static void update(void)
{
    zlog("%s updating!", scene_name);
}

static void draw(void)
{
    zlog("%s drawing!", scene_name);
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

    zap_set_init_func(scene, init);
    zap_set_update_func(scene, update);
    zap_set_draw_func(scene, draw);
    zap_set_destroy_func(scene, destroy);
    zap_set_key_down_func(scene, on_key_down);
    zap_set_key_up_func(scene, on_key_up);

    zlog("%s Created.", scene_name);
    return scene;
}