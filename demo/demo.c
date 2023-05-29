#include <stdio.h>
#include "zapengine/zapengine.h"
#include "demo_scene.h"
#include "data.h"

int main(int argc, char **argv)
{
    z_game_begin(60, 1280, 800, argv[0], DATAFILE_NAME, demo_scene());

    return 0;
}
