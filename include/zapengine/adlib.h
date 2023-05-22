#ifndef ADLIB_H
#define ADLIB_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_SAMPLES 2048
#define STREAM_FREQ 44100

    typedef struct
    {
        bool is_playing;
        short *opl_buffer;
        int samples_count;
        float vol;
        struct ALLEGRO_AUDIO_STREAM *stream;
        struct ADL_MIDIPlayer *midi_player;
    } t_adlib;

    extern t_adlib music;

    void adlmidi_init(void);
    void stream_opl(void);
    void open_music_file(const char *filename);
    void play_music(void);
    void pause_music(void);
    void resume_music(void);
    void restart_music(void);
    void reset_music_device(void);

#ifdef __cplusplus
    extern "C"
}
#endif

#endif