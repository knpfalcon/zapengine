#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_scene.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_draw.h"
#include "zapengine/internal/zintern_actor.h"

void zap_change_scene(ZAP_SCENE *next_scene)
{
    zlog(NONE, "Changing Scene to %s", next_scene->name);
    if (game.current_scene != NULL && game.current_scene->destroy)
    {
        (game.current_scene->destroy)();
        game.current_scene = NULL;
    }
    game.current_scene = next_scene;

    if (game.current_scene->init)
        game.current_scene->init();
}

ZAP_SCENE *zap_create_empty_scene(void)
{
    zlog(NONE, "Creating empty scene.");
    ZAP_SCENE *scene = malloc(sizeof(ZAP_SCENE));
    memset(scene, 0, sizeof(ZAP_SCENE));
    if (scene) return scene;
    zlog(FAIL, "Couldn't created empty scene.");
    return NULL;
}

void _destroy_scene(ZAP_SCENE *scene)
{
    if (scene->use_actors) _destroy_actor_list();
    if (scene)
    {
        zlog(NONE, "Destroying scene %s", scene->name);
        free(scene);
    }
    zlog(INFO, "Scene destroyed.");
}

void z_set_scene_name(ZAP_SCENE *scene, char *name)
{
    scene->name = name;
}

char *z_get_scene_name(ZAP_SCENE *scene)
{
    return scene->name;
}

void z_set_scene_init_func(ZAP_SCENE *scene, void(*init)(void))
{
    scene->init = init;
}

void z_set_scene_update_func(ZAP_SCENE *scene, void(*update)(void))
{
    scene->update = update;
}

void z_set_scene_draw_func(ZAP_SCENE *scene, void(*draw)(void))
{
    scene->draw = draw;
}

void z_set_scene_destroy_func(ZAP_SCENE *scene, void(*destroy)(void))
{
    scene->destroy = destroy;
}

void z_set_scene_key_down_func(ZAP_SCENE *scene, void(*on_key_down)(int keycode))
{
    scene->on_key_down = on_key_down;
}

void z_set_scene_key_up_func(ZAP_SCENE *scene, void(*on_key_up)(int keycode))
{
    scene->on_key_up = on_key_up;
}

void z_scene_use_actors(ZAP_SCENE *scene, bool use_actors)
{
    scene->use_actors = use_actors;
}
