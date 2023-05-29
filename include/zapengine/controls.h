#ifndef CONTROLS_H
#define CONTROLS_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    enum PLAYER_KEYS { e_key_fire, e_key_jump, e_key_left, e_key_right, e_key_up, e_key_down };

    typedef struct ZAP_CONTROLS ZAP_CONTROLS;

    ZAP_FUNC(bool, zap_get_key_state, (int keycode));
    ZAP_FUNC(int, zap_get_key, (int key));

#ifdef __cplusplus
}
#endif

#endif
