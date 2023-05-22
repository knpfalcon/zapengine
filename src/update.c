/*
*
*   Update All Logic!
*   This is where all functions can be placed to update
*   any logic; player movement, positions, etc.
*
*/
#include "update_intern.h"
#include "game_intern.h"
#include "adlib_intern.h"
#include "scene_intern.h"
#include "actor_intern.h"

void update_logic(void)
{
    update_actors();
    if (game.current_scene.update)
        (*game.current_scene.update)();
}