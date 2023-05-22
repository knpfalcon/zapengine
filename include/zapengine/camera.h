#ifndef CAMERA_H_
#define CAMERA_H_

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
    extern "C"
}
#endif

#endif