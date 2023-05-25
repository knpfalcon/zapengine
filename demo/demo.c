#include <stdio.h>
#include "zapengine/zapengine.h"
#include "demo_scene.h"
#include "data.h"

int main(int argc, char **argv)
{
    game_begin(30, 960, 600, argv[0], DATAFILE_NAME, demo_scene());

    return 0;
}