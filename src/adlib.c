#include <adlmidi.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <physfs.h>
#include "zapengine/zapengine.h"
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_adlib.h"
#include "zapengine/internal/zintern_game.h"

t_adlib music;

void stream_opl()
{
    music.opl_buffer = al_get_audio_stream_fragment(music.stream);

    if (!music.opl_buffer)
    {
        zlog("music.opl_buffer returned null!");
    }
    else
    {
        music.samples_count = adl_play(music.midi_player, BUFFER_SAMPLES * 2, music.opl_buffer);
    }

    if (music.samples_count > 0)
    {
        al_set_audio_stream_fragment(music.stream, music.opl_buffer);
    }
    if (music.samples_count <= 0)
    {
        al_drain_audio_stream(music.stream);
    }
}

void adlmidi_init(void)
{
    music.is_playing = false;
    music.vol = 1.0f;

    music.midi_player = adl_init(STREAM_FREQ);
    adl_setLoopEnabled(music.midi_player, 1);
    adl_switchEmulator(music.midi_player, ADLMIDI_EMU_NUKED);
    adl_setBank(music.midi_player, 74);
    adl_setVolumeRangeModel(music.midi_player, ADLMIDI_VolumeModel_APOGEE_Fixed);

    music.stream = al_create_audio_stream(2, BUFFER_SAMPLES, STREAM_FREQ, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);
    if (music.stream) zlog("music.stream created.");

    al_register_event_source(game.event_queue, al_get_audio_stream_event_source(music.stream));
    zlog("music.stream registered as audio stream event source.");

    if (!al_reserve_samples(game.reserved_samples))
    {
        zlog("Problem reserving Audio Samples!");
        exit(1);
    }
    zlog("Audio Samples Reserved.");

    al_set_mixer_gain(al_get_default_mixer(), 1.0f); //Turn down the volume during development
    al_set_audio_stream_gain(music.stream, music.vol);
    al_attach_audio_stream_to_mixer(music.stream, al_get_default_mixer());
    al_set_audio_stream_playing(music.stream, false);
    zlog("Music Device Reset.");
}

void open_music_file(const char *filename)
{
    pause_music();
    PHYSFS_file *musfile = PHYSFS_openRead(filename);
    char *buffer = malloc(PHYSFS_fileLength(musfile));

    PHYSFS_readBytes(musfile, buffer, PHYSFS_fileLength(musfile));
    if (adl_openData(music.midi_player, buffer, PHYSFS_fileLength(musfile)) < 0)
    {
        zlog("Couldn't open music file: %s", adl_errorInfo(music.midi_player));
    }
    free(buffer);
    PHYSFS_close(musfile);
}

void play_music(void)
{
    adl_positionRewind(music.midi_player);
    al_set_audio_stream_playing(music.stream, true);
    music.is_playing = true;
}

void pause_music(void)
{
    al_set_audio_stream_playing(music.stream, false);
    music.is_playing = false;
}

void resume_music(void)
{
    al_set_audio_stream_playing(music.stream, true);
    music.is_playing = true;
}

void restart_music(void)
{
    adl_positionRewind(music.midi_player);
    music.is_playing = true;
}

void reset_music_device(void)
{
    al_destroy_audio_stream(music.stream);
    adl_close(music.midi_player);
    adlmidi_init();
}