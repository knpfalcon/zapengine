#ifndef ZINTERN_BITMAP_H
#define ZINTERN_BITMAP_H

#include "bitmap.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct ALLEGRO_BITMAP *_load_bitmap(const char *filename);
    struct ALLEGRO_BITMAP *_create_bitmap(int w, int h, const char *name);

#ifdef __cplusplus
}
#endif

#endif