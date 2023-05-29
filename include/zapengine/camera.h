#ifndef CAMERA_H_
#define CAMERA_H_

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(bool, z_is_point_in_view, (int x, int y, int w, int h));

#ifdef __cplusplus
}
#endif

#endif
