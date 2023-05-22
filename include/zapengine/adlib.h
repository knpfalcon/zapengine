#ifndef ADLIB_H
#define ADLIB_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#define BUFFER_SAMPLES 2048
#define STREAM_FREQ 44100

typedef struct
{
    bool is_playing;
    short *opl_buffer;
    int samples_count;
    float vol;
    ALLEGRO_AUDIO_STREAM *stream;
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

#endif