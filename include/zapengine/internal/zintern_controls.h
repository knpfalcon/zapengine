#ifndef ZINTERN_CONTROLS_H
#define ZINTERN_CONTROLS_H

#include "controls.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ZAP_KEY_MAX 227

    struct ZAP_CONTROLS
    {
        bool key_state[ZAP_KEY_MAX];

        int key_fire;
        int key_jump;
        int key_left;
        int key_right;
        int key_up;
        int key_down;

    };

    extern ZAP_CONTROLS controls;

    void _init_controls(void);
    void _check_player_controls(void);

#ifdef __cplusplus
}
#endif

#endif