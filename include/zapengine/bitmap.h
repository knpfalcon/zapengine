#ifndef BITMAP_H
#define BITMAP_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP *load_bitmap(const char *filename);
ALLEGRO_BITMAP *create_bitmap(int w, int h, const char *name);

#endif