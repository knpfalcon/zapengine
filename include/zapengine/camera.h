#ifndef CAMERA_H_
#define CAMERA_H_

typedef struct
{
    int x;
    int y;
    int w;
    int h;
}t_camera;

extern t_camera cam;

void init_camera(int x, int y, int w, int h);
bool is_point_in_view(int x, int y, int w, int h);
void draw_cam_rect();

#endif