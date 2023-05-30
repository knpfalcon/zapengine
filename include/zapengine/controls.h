#ifndef CONTROLS_H
#define CONTROLS_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    enum PLAYER_KEYS { E_KEY_FIRE, E_KEY_JUMP, E_KEY_LEFT, E_KEY_RIGHT, E_KEY_UP, E_KEY_DOWN };

    typedef struct ZAP_CONTROLS ZAP_CONTROLS;

    ZAP_FUNC(bool, z_get_key_state, (int keycode));
    ZAP_FUNC(int, z_get_key, (int key));

#ifdef __cplusplus
}
#endif

#endif
