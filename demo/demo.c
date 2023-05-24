#include <stdio.h>
#include "zapengine/zapengine.h"
#include "demo_scene.h"
#include "data.h"

int main(int argc, char **argv)
{
    game_begin(15, 640, 480, argv[0], DATAFILE_NAME, demo_scene());

    return 0;
}