#ifndef CONTROLS_H
#define CONTROLS_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ZAP_CONTROLS ZAP_CONTROLS;

    ZAP_FUNC(bool, zap_get_key_state, (int keycode));

#ifdef __cplusplus
}
#endif

#endif
