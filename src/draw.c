#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "zapengine/internal/zintern_draw.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_update.h"
#include "zapengine/internal/zintern_sprite.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_version.h"
#include "zapengine/internal/zintern_movement.h"
#include "zapengine/internal/zintern_collision.h"

void _draw_screen(void)
{
    al_set_target_bitmap(game.view);
    al_clear_to_color(al_map_rgb(0, 0, 0)); //test code
    if (game.current_scene->draw)
        game.current_scene->draw();

    if (game.current_scene->use_actors == true) _draw_actors();

    //testcode///////////////////////////////////////////
    for (int i = 0; i < 40; i++)
    {
        al_draw_pixel(i * 8, 200, al_map_rgb(255, 0, 0));
    }
    al_draw_pixel(64, 200 - 64, al_map_rgb(255, 0, 0));
    al_draw_pixel(64, 200 - 16, al_map_rgb(255, 0, 0));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 0, 0, "X %f", z_get_actor_x(z_get_actor(0)));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 8, 0, "Y %f", z_get_actor_y(z_get_actor(0)));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 16, 0, "VELX %f", z_get_actor_x_velocity(z_get_actor(0)));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 24, 0, "VELY %f", z_get_actor_y_velocity(z_get_actor(0)));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 32, 0, "TOP %d", z_get_actor_top(z_get_actor(0)));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 40, 0, "BOTTOM %d", z_get_actor_bottom(z_get_actor(0)));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 48, 0, "LEFT %d", z_get_actor_left(z_get_actor(0)));
    al_draw_textf(game.sys_font, al_map_rgb(50, 50, 50), 0, 56, 0, "RIGHT %d", z_get_actor_right(z_get_actor(0)));

    ////////////////////////////////////////////////////////

    al_set_target_backbuffer(game.display);
    al_draw_scaled_bitmap(game.view, 0, 0, 320, 200, 0, 0, game.window_w, game.window_h, 0);
    al_flip_display();

    if (game.drawn_frames == 6000) game.drawn_frames = 0;
    game.drawn_frames++;
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
