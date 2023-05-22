#include <allegro5/allegro.h>
#include "zapengine/internal/zintern_draw.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_update.h"
#include "zapengine/internal/zintern_graphics.h"

void _draw_screen(void)
{
    al_set_target_bitmap(game.view);

    if (game.current_scene.draw)
        (*game.current_scene.draw)();

    al_set_target_backbuffer(game.display);
    al_draw_scaled_bitmap(game.view, 0, 0, 320, 200, 0, 0, game.window_w, game.window_h, 0);
    al_flip_display();
}

void _draw_loading_screen(void)
{
    al_set_target_bitmap(game.view);
    al_clear_to_color(al_map_rgb(50, 200, 50));
    //al_draw_bitmap(gfx_native.loading, 0, 0, 0);
    al_set_target_backbuffer(game.display);
    al_draw_scaled_bitmap(game.view, 0, 0, 320, 200, 0, 0, game.window_w, game.window_h, 0);
    al_flip_display();
}