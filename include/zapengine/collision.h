#ifndef COLLISION_H_
#define COLLISION_H_

#include "base.h"

#include "actor.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(bool, zap_is_touching, (ZAP_ACTOR *actor1, ZAP_ACTOR *actor2));

#ifdef __cplusplus
}
#endif

#endif
