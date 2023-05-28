#include "zapengine/internal/zintern_collision.h"

bool zap_is_touching(ZAP_ACTOR *actor1, ZAP_ACTOR *actor2)
{
    if ((actor1->left > actor2->right) || (actor1->right < actor2->left) ||
        (actor1->top > actor2->bottom) || (actor1->bottom < actor2->top))
    {

        return false;
    }

    return true;
}