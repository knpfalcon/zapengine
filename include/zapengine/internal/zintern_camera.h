#ifndef ZINTERN_CAMERA_H
#define ZINTERN_CAMERA_H_

#include "camera.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ZAP_CAMERA
    {
        int x;
        int y;
        int w;
        int h;
    } ZAP_CAMERA;

    extern ZAP_CAMERA cam;

    void _init_camera(int x, int y, int w, int h);
    void _draw_cam_rect();

#ifdef __cplusplus
    extern "C"
}
#endif

#endif