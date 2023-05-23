#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "zapengine/internal/zintern_progbar.h"
#include "zapengine/internal/zintern_game.h"

ZAP_PROGRESS_BAR *_create_progress_bar(int x, int y, int w, int h, int r, int g, int b)
{
    ZAP_PROGRESS_BAR *barp = malloc(sizeof(ZAP_PROGRESS_BAR));
    barp->val = 0;
    barp->x = x;
    barp->y = y;
    barp->w = w;
    barp->h = h;
    barp->r = r;
    barp->g = g;
    barp->b = b;

    barp->bitmap = al_create_bitmap(w, h);

    return barp;
}

void _destroy_progress_bar(ZAP_PROGRESS_BAR *bar)
{
    al_destroy_bitmap(bar->bitmap);
    if (bar) free(bar);
}

void _increment_progress_bar(ZAP_PROGRESS_BAR *bar, int increment)
{
    if (bar->val < 100) bar->val += increment;
}

void _draw_progress_bar(ZAP_PROGRESS_BAR *bar)
{
    al_set_target_bitmap(bar->bitmap);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(0, 0, bar->val / bar->w, bar->h, al_map_rgb(bar->r, bar->g, bar->b));

    al_set_target_bitmap(game.view);
    al_draw_bitmap(bar->bitmap, bar->x, bar->y, 0);

    al_set_target_backbuffer(game.display);
    al_draw_scaled_bitmap(game.view, 0, 0, 320, 200, 0, 0, game.window_w, game.window_h, 0);
    al_flip_display();
}
