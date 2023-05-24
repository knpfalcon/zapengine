#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_memfile.h>
#include <allegro5/allegro_physfs.h>
#include <physfs.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_init.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_controls.h"
#include "zapengine/internal/zintern_graphics.h"
#include "zapengine/internal/zintern_draw.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_cleanup.h"
#include "zapengine/internal/zintern_adlib.h"
#include "zapengine/internal/zintern_sound.h"
#include "zapengine/internal/zintern_zapsplash.h"
#include "zapengine/internal/zintern_progbar.h"
#include "zapengine/internal/zintern_actor.h"

static void allegro_init(void);

char *DATAFILE_NAME;

/*  Called from entry point main. Startup happens here. */
void game_begin(int fps, int window_w, int window_h, char *argv0, char *datafile, ZAP_SCENE *first_scene)
{
    zlog("Begin.");
    if (!PHYSFS_init(argv0))
    {
        zlog("Problem initializing PhysFS!");
        exit(1);
    }
    DATAFILE_NAME = datafile;

    game.fps = fps;
    zlog("Frames Per Second: %d", game.fps);
    game.window_w = window_w;
    zlog("Window Width: %d", game.window_w);
    game.window_h = window_h;
    zlog("Window Height: %d", game.window_h);
    game.reserved_samples = 10;
    zlog("Reserved Audio Samples: %d", game.reserved_samples);

    //register cleanup atexit functions
    if (atexit(_exit_cleanup) != 0)
        zlog("Failed to register _exit_cleanup for atexit()");
    else
        zlog("Registered _exit_cleanup for atexit()");

    // Start Allegro
    allegro_init();

    //Bitmaps
    game.view = _create_bitmap(320, 200, "game.view");
    if (!game.view)
    {
        zlog("Couldn't create game.view");
        exit(1);
    }
    ZAP_PROGRESS_BAR *progbar = _create_progress_bar(96, 158, 132, 16, 255, 255, 255);

    game.sys_font = al_create_builtin_font();

    //Load splash from hardcoded data
    ALLEGRO_FILE *splashfp = al_open_memfile(zap_splash, sizeof(zap_splash), "r");
    game.splash = al_load_bitmap_f(splashfp, ".png");
    al_fclose(splashfp);
    _draw_splash_screen();

    //Load Datafile
    if (!PHYSFS_mount(DATAFILE_NAME, NULL, 1)) //DATAFILE needs to be passed in from end-user
    {
        zlog("Problem loading %s!", DATAFILE_NAME);
        exit(1);
    }
    al_set_physfs_file_interface();

    _load_native_graphics();

    //Assign keys
    _init_controls();

    //Initialize sound sample stuff
    _init_sound(0.5f);

    //Fake loading bar
    for (int i = 0; i < 10; i++)
    {
        _increment_draw_progress_bar(progbar, 10);
    }

    _destroy_progress_bar(progbar);


    /* //TEST CODE//////////////////////////////////////////////////////////////////////////
    zap_load_actor_sprite("GRAPHICS/SPR_TALLY", 32, 32, 0);
    zap_add_actor(32, 32, 0, zap_create_actor("Tally", 1, 1, 8, 4, 8, 32, 32, 0, NULL));
    ///////////////////////////////////////////////////////////////////////////////////// */

    //Entering the Main Game Loop
    al_set_target_bitmap(game.view);

    //Load first scene
    zap_change_scene(first_scene);

    game.done = false;
    _main_event_loop();

    zlog("Breaking from main loop.");

    al_uninstall_system();
}

/* Initialize Allegro Stuff */
static void allegro_init(void)
{
    if (!al_install_system(ALLEGRO_VERSION_INT, NULL)) //because this is a shared library
    {
        zlog("Problem initializing Allegro!");
        exit(1);
    }

    //Initialize addons
    if (!al_init_primitives_addon())
    {
        zlog("Problem initializing Primitives Addon!");
        exit(1);
    }
    if (!al_init_font_addon())
    {
        zlog("Problem initializing Font Addon!");
        exit(1);
    }
    if (!al_init_ttf_addon())
    {
        zlog("Problem initializing TTF Addon!");
        exit(1);
    }
    if (!al_init_image_addon())
    {
        zlog("Problem initializing Image Addon!");
        exit(1);
    }
    if (!al_install_audio())
    {
        zlog("Problem initializing Audio!");
        exit(1);
    }
    if (!al_init_acodec_addon())
    {
        zlog("Problem initializing Audio Codec!");
        exit(1);
    }
    if (!al_install_keyboard())
    {
        zlog("Problem installing Keyboard!");
        exit(1);
    }


    //Create display
    game.display = al_create_display(game.window_w, game.window_h);
    if (!game.display)
    {
        zlog("Problem creating display!");
        exit(1);
    }

    // Create update timer.
    game.update_timer = al_create_timer(1.0f / game.fps);
    if (!game.update_timer)
    {
        zlog("Problem creating update timer!");
        exit(1);
    }

    // Create event queue.
    game.event_queue = al_create_event_queue();
    if (!game.event_queue)
    {
        zlog("Problem creating Event Queue!");
        exit(1);
    }

    // Start libADLMidi
    _adlmidi_init();

    //Register even sources
    al_register_event_source(game.event_queue, al_get_display_event_source(game.display));
    al_register_event_source(game.event_queue, al_get_timer_event_source(game.update_timer));
    al_register_event_source(game.event_queue, al_get_keyboard_event_source());

    // Start update timer
    al_start_timer(game.update_timer);

    game.ticks = 0;
}