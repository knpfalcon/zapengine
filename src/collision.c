#include "zapengine/internal/zintern_collision.h"

bool z_is_touching(ZAP_ACTOR *actor1, ZAP_ACTOR *actor2)
{
    if ((actor1->left > actor2->right) || (actor1->right < actor2->left) ||
        (actor1->top > actor2->bottom) || (actor1->bottom < actor2->top))
    {

        return false;
    }

    return true;
}

int z_get_actor_left(ZAP_ACTOR *actor)
{
    return actor->left;
}
int z_get_actor_right(ZAP_ACTOR *actor)
{
    return actor->right;
}
int z_get_actor_top(ZAP_ACTOR *actor)
{
    return actor->top;
}
int z_get_actor_bottom(ZAP_ACTOR *actor)
{
    return actor->bottom;
}

void z_set_actor_box(ZAP_ACTOR *actor, int left, int right, int top, int bottom)
{
    actor->bbl = left;
    actor->bbr = right;
    actor->bbt = top;
    actor->bbb = bottom;
}

int z_get_actor_center_x(ZAP_ACTOR *actor)
{
    return actor->x_center;
}

int z_get_actor_center_y(ZAP_ACTOR *actor)
{
    return actor->y_center;
}
