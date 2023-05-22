#ifndef _ZINTERN_ADLIB_H
#define _ZINTERN_ADLIB_H

#include "adlib.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_SAMPLES 2048
#define STREAM_FREQ 44100

    typedef struct ZAP_OPL_PLAYER
    {
        bool is_playing;
        short *opl_buffer;
        int samples_count;
        float vol;
        struct ALLEGRO_AUDIO_STREAM *stream;
        struct ADL_MIDIPlayer *midi_player;
    } ZAP_OPL_PLAYER;

    extern ZAP_OPL_PLAYER music;

    void _adlmidi_init(void);
    void _stream_opl(void);
    void _reset_music_device(void);

#ifdef __cplusplus
    extern "C"
}
#endif

#endif