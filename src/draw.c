#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "zapengine/internal/zintern_draw.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_update.h"
#include "zapengine/internal/zintern_graphics.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_version.h"

void _draw_screen(void)
{
    al_set_target_bitmap(game.view);

    //TEST CODE//////////////////////////////////////////////////////////////////////////
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(_actor_list[0]->sprite->frames[_actor_list[0]->sprite->current_frame], _actor_list[0]->x, _actor_list[0]->y, 0);
    //TEST CODE//////////////////////////////////////////////////////////////////////////

    if (game.current_scene.draw)
        (*game.current_scene.draw)();

    al_set_target_backbuffer(game.display);
    al_draw_scaled_bitmap(game.view, 0, 0, 320, 200, 0, 0, game.window_w, game.window_h, 0);
    al_flip_display();
}

void _draw_splash_screen(void)
{
    al_set_target_bitmap(game.view);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(game.splash, 0, 0, 0);
    al_draw_textf(game.sys_font, al_map_rgb_f(1, 1, 1), 96, 128, 0, "v%d.%d.%d", ZAP_VERSION_MAJOR, ZAP_VERSION_MINOR, ZAP_VERSION_REVISION);

    al_set_target_backbuffer(game.display);
    al_draw_scaled_bitmap(game.view, 0, 0, 320, 200, 0, 0, game.window_w, game.window_h, 0);
    al_flip_display();
}