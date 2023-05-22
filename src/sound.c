#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_sound.h"

ZAP_SOUND sound;

void _init_sound(float vol)
{
    sound.vol = vol;
}

void play_sound(ZAP_SAMPLE *sample, int interupt)
{
    if (interupt == INTERUPT_ALL)
        al_stop_samples();
    else if (interupt == INTERUPT_SELF)
        al_stop_sample(&(sample->id));

    al_play_sample(sample->sample, sound.vol, 0, 1, ALLEGRO_PLAYMODE_ONCE, &(sample->id));
}


void load_sample(ZAP_SAMPLE *sample, const char *filename)
{
    sample->sample = al_load_sample(filename);
    if (!sample->sample)
    {
        zlog("Couldn't open sample from %s", filename);
        return;
    }
    zlog("Sample %s loaded.", filename);
}

void _destroy_sample(ZAP_SAMPLE *sample)
{
    al_destroy_sample(sample->sample);
    sample->sample = NULL;
}
