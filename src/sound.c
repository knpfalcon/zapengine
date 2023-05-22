#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#include "sound_intern.h"
#include "zutil.h"

t_sound sound;

void init_sound(float vol)
{
    sound.vol = vol;
}

void play_sound(t_sample *sample, int interupt)
{
    if (interupt == INTERUPT_ALL)
        al_stop_samples();
    else if (interupt == INTERUPT_SELF)
        al_stop_sample(&(sample->id));

    al_play_sample(sample->sample, sound.vol, 0, 1, ALLEGRO_PLAYMODE_ONCE, &(sample->id));
}


void load_sample(t_sample *sample, const char *filename)
{
    sample->sample = al_load_sample(filename);
    if (!sample->sample)
    {
        zlog("Couldn't open sample from %s", filename);
        return;
    }
    zlog("Sample %s loaded.", filename);
}

void destroy_sample(t_sample *sample)
{
    al_destroy_sample(sample->sample);
    sample->sample = NULL;
}
