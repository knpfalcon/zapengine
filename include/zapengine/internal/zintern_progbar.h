#ifndef ZINTERN_PROGBAR
#define ZINTERN_PROGBAR

typedef struct ZAP_PROGRESS_BAR
{
    float val;
    int x;
    int y;
    float w;
    float h;
    int r, g, b;
    struct ALLEGRO_BITMAP *bitmap;
} ZAP_PROGRESS_BAR;

void _increment_progress_bar(ZAP_PROGRESS_BAR *bar, float num);
void _draw_progress_bar(ZAP_PROGRESS_BAR *bar);
void _increment_draw_progress_bar(ZAP_PROGRESS_BAR *bar, float num);
void _decrement_progress_bar(ZAP_PROGRESS_BAR *bar, float num);

ZAP_PROGRESS_BAR *_create_progress_bar(int x, int y, float w, float h, int r, int g, int b);
void _destroy_progress_bar(ZAP_PROGRESS_BAR *bar);

#endif