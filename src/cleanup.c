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
    //Not really needed, but calling them anyway for good practice.

    if (game.current_scene.destroy)
        (*game.current_scene.destroy)();

    al_destroy_bitmap(game.view);
    zlog("Destroy Game View Bitmap");

    al_destroy_font(game.sys_font);
    zlog("Destroy System Font");

    al_destroy_timer(game.update_timer);
    zlog("Destroy Timer");

    al_destroy_event_queue(game.event_queue);
    zlog("Destroy Event Queue");

    al_destroy_audio_stream(music.stream);
    zlog("Destroy audio music.stream");

    adl_close(music.midi_player);
    zlog("Close Midi Player");

    PHYSFS_deinit();
    zlog("De-initialize PhysFS");


}