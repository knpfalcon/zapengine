#ifndef COLLISION_H_
#define COLLISION_H_

#include "base.h"

#include "actor.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(bool, z_is_touching, (ZAP_ACTOR *actor1, ZAP_ACTOR *actor2));

    ZAP_FUNC(void, z_set_actor_box, (ZAP_ACTOR *actor, float left, float right, float top, float bottom));

    ZAP_FUNC(float, z_get_actor_center_x, (ZAP_ACTOR *actor));
    ZAP_FUNC(float, z_get_actor_center_y, (ZAP_ACTOR *actor));

    ZAP_FUNC(float, z_get_actor_left, (ZAP_ACTOR *actor));
    ZAP_FUNC(float, z_get_actor_right, (ZAP_ACTOR *actor));
    ZAP_FUNC(float, z_get_actor_top, (ZAP_ACTOR *actor));
    ZAP_FUNC(float, z_get_actor_bottom, (ZAP_ACTOR *actor));

#ifdef __cplusplus
}
#endif

#endif
