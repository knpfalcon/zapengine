#ifndef ZINTERN_PROGBAR
#define ZINTERN_PROGBAR

typedef struct ZAP_PROGRESS_BAR
{
    int val;
    int x;
    int y;
    int w;
    int h;
    int r, g, b;
    struct ALLEGRO_BITMAP *bitmap;
} ZAP_PROGRESS_BAR;

void _increment_progress_bar(ZAP_PROGRESS_BAR *bar, int increment);
void _draw_progress_bar(ZAP_PROGRESS_BAR *bar);

ZAP_PROGRESS_BAR *_create_progress_bar(int x, int y, int w, int h, int r, int g, int b);
void _destroy_progress_bar(ZAP_PROGRESS_BAR *bar);

#endif