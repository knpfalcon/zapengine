#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_progbar.h"
#include "zapengine/internal/zintern_game.h"

ZAP_PROGRESS_BAR *_create_progress_bar(int x, int y, float w, float h, int r, int g, int b)
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

void _increment_progress_bar(ZAP_PROGRESS_BAR *bar, float num)
{
    if (bar->val < 100) bar->val += num;
}

void _decrement_progress_bar(ZAP_PROGRESS_BAR *bar, float num)
{
    if (bar->val > 0) bar->val -= num;
}

void _draw_progress_bar(ZAP_PROGRESS_BAR *bar)
{
    al_set_target_bitmap(bar->bitmap);
    al_draw_filled_rectangle(0, 0, bar->w * (bar->val / 100), bar->h, al_map_rgb(bar->r, bar->g, bar->b));
    al_draw_rectangle(1, 1, bar->w, bar->h, al_map_rgba(228, 120, 0, 255), 1);
    if (bar->val < 100) al_draw_text(game.sys_font, al_map_rgb(228, 120, 0), bar->w / 2, bar->h - 12, ALLEGRO_ALIGN_CENTRE, "LOADING");
    else al_draw_text(game.sys_font, al_map_rgb(228, 120, 0), bar->w / 2, bar->h - 12, ALLEGRO_ALIGN_CENTRE, "PRESS ANY KEY!");
    al_set_target_bitmap(game.view);
    al_draw_bitmap(bar->bitmap, bar->x, bar->y, 0);

    al_set_target_backbuffer(game.display);
    al_draw_scaled_bitmap(game.view, 0, 0, 320, 200, 0, 0, game.window_w, game.window_h, 0);
    al_flip_display();
}

void _increment_draw_progress_bar(ZAP_PROGRESS_BAR *bar, float num)
{
    _increment_progress_bar(bar, num);
    _draw_progress_bar(bar);
}
