#include <allegro5/allegro.h>
#include <adlmidi.h>

#include "zapengine/zutil.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_adlib.h"

void exit_cleanup(void)
{
    //Not really needed, but calling them anyway for good practice.

    if (game.current_scene.destroy)
        (*game.current_scene.destroy)();

    al_destroy_bitmap(game.view);
    zlog("Destroy Game View Bitmap");

    al_destroy_timer(game.update_timer);
    zlog("Destroy Timer");

    al_destroy_event_queue(game.event_queue);
    zlog("Destroy Event Queue");

    al_destroy_display(game.display);
    zlog("Destroy Display");

    al_destroy_audio_stream(music.stream);
    zlog("Destroy audio music.stream");

    adl_close(music.midi_player);
    zlog("Close Midi Player");

    PHYSFS_deinit();
    zlog("De-initialize PhysFS");
}