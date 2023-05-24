#ifndef CAMERA_H_
#define CAMERA_H_

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    //Does this need to be public?
    ZAP_FUNC(bool, zap_is_point_in_view, (int x, int y, int w, int h));

#ifdef __cplusplus
}
#endif

#endif