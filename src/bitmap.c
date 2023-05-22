
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_bitmap.h"


ALLEGRO_BITMAP *_load_bitmap(const char *filename)
{
    ALLEGRO_BITMAP *bmp = al_load_bitmap(filename);
    if (!bmp)
    {
        zlog("Couldn't load %s", filename);
        exit(1);
    }
    else
        zlog("Loaded %s", filename);

    return bmp;
}

ALLEGRO_BITMAP *_create_bitmap(int w, int h, const char *name)
{
    ALLEGRO_BITMAP *bmp = al_create_bitmap(w, h);
    if (!bmp)
    {
        zlog("Couldn't create bitmap: %s!", name);
        exit(1);
    }
    else
        zlog("Bitmap created: %s", name);

    return bmp;
}
