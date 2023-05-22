#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "zapengine/internal/zintern_camera.h"

ZAP_CAMERA cam;

void _init_camera(int x, int y, int w, int h)
{
    cam.x = x;
    cam.y = y;
    cam.w = w;
    cam.h = h;
}

bool is_point_in_view(int x, int y, int w, int h)
{
    if (x > cam.x - w && x < cam.x + cam.w && y > cam.y - h && y < cam.y + cam.h)
        return true;

    return false;
}

void _draw_cam_rect()
{
    al_draw_rectangle(cam.x, cam.y, cam.x + cam.w, cam.y + cam.h, al_map_rgb(255, 0, 0), 1);
}