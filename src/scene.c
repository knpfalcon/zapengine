#include "scene_intern.h"
#include "game_intern.h"
#include "zutil.h"
#include "draw_intern.h"


void change_scene(t_scene next_scene)
{
    draw_loading_screen();
    zlog("Changing Scene from %s to %s", game.current_scene.name ? game.current_scene.name : "noname", next_scene.name ? next_scene.name : "noname");
    if (game.current_scene.destroy)
        (*game.current_scene.destroy)();

    game.current_scene = next_scene;

    if (game.current_scene.init)
        game.current_scene.init();
}