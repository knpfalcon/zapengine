#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_scene.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_draw.h"


void change_scene(ZAP_SCENE next_scene)
{
    draw_loading_screen();
    zlog("Changing Scene from %s to %s", game.current_scene.name ? game.current_scene.name : "noname", next_scene.name ? next_scene.name : "noname");
    if (game.current_scene.destroy)
        (*game.current_scene.destroy)();

    game.current_scene = next_scene;

    if (game.current_scene.init)
        game.current_scene.init();
}