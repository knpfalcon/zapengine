#ifndef ZINTERN_UTIL_H
#define ZINTERN_UTIL_H

#include <allegro5/allegro.h>
#include "util.h"

int _populate_frames(ALLEGRO_BITMAP *atlas, int w, int h, ALLEGRO_BITMAP **frame_array, int array_size);
void _depopulate_frames(ALLEGRO_BITMAP **frame_array, int frame_count);

#endif