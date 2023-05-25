#include "zapengine/internal/zintern_update.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_scene.h"

void _update_logic(void)
{

    if (game.current_scene->use_actors == true) _update_actors();

    if (game.current_scene->update)
        game.current_scene->update();

}