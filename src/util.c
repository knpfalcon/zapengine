#include "zapengine/internal/zintern_util.h"
#include "zapengine/zlog.h"


int _populate_frames(ALLEGRO_BITMAP *atlas, int frame_w, int frame_h, ALLEGRO_BITMAP **frame_array, int max_array_size)
{
    int frame_count = 0;

    for (int y = 0; y < al_get_bitmap_height(atlas) / frame_h; y++)
    {
        for (int x = 0; x < al_get_bitmap_width(atlas) / frame_w; x++)
        {
            if (frame_count == max_array_size - 1) return frame_count;
            zlog(INFO, "Populating Frame %d", frame_count);
            frame_array[frame_count] = al_create_sub_bitmap(atlas, x * frame_w, y * frame_h, frame_w, frame_h);
            frame_count++;
        }
    }

    return frame_count;
}

void _depopulate_frames(ALLEGRO_BITMAP **frame_array, int frame_count)
{
    for (int f = 0; f < frame_count; f++)
    {
        if (frame_array[f]) al_destroy_bitmap(frame_array[f]);
        frame_array[f] = NULL;
        zlog(INFO, "Frame %d Destroyed.", f);
    }

}
