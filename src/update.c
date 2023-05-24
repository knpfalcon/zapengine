#include "zapengine/internal/zintern_update.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_scene.h"

void _update_logic(void)
{
    _update_actors();
    /* if (_actor_list[0]->sprite->current_frame == _actor_list[0]->sprite->frame_count - 1)
        _actor_list[0]->sprite->current_frame = 0;
    else if (_actor_list[0]->sprite->current_frame < _actor_list[0]->sprite->frame_count)
    {
        _actor_list[0]->sprite->current_frame++;
    } */

    if (game.current_scene->update)
        game.current_scene->update();
}