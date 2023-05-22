#ifndef BITMAP_H
#define BITMAP_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct ALLEGRO_BITMAP *load_bitmap(const char *filename);
    struct ALLEGRO_BITMAP *create_bitmap(int w, int h, const char *name);

#ifdef __cplusplus
    extern "C"
}
#endif

#endif