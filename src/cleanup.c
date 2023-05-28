#include <adlmidi.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <physfs.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_adlib.h"

void _exit_cleanup(void)
{
    if (game.current_scene->destroy)
        (*game.current_scene->destroy)();
    _destroy_scene(game.current_scene);
    game.current_scene = NULL;

    adl_close(music.midi_player);
    zlog(NONE, "Close Midi Player");

    PHYSFS_deinit();
    zlog(NONE, "De-initialize PhysFS");

}
