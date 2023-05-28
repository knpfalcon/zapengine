#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_memfile.h>
#include <allegro5/allegro_physfs.h>
#include <physfs.h>
#include "zapengine/zlog.h"
#include "zapengine/internal/zintern_init.h"
#include "zapengine/internal/zintern_game.h"
#include "zapengine/internal/zintern_controls.h"
#include "zapengine/internal/zintern_sprite.h"
#include "zapengine/internal/zintern_draw.h"
#include "zapengine/internal/zintern_bitmap.h"
#include "zapengine/internal/zintern_cleanup.h"
#include "zapengine/internal/zintern_adlib.h"
#include "zapengine/internal/zintern_sound.h"
#include "zapengine/internal/zintern_zapsplash.h"
#include "zapengine/internal/zintern_progbar.h"
#include "zapengine/internal/zintern_actor.h"
#include "zapengine/internal/zintern_version.h"

static void allegro_init(void);

char *DATAFILE_NAME;

/*  Called from entry point main. Startup happens here. */
void game_begin(int fps, int window_w, int window_h, char *argv0, char *datafile, ZAP_SCENE *first_scene)
{
    zlog(NONE, "Starting Zap Engine %d.%d.%d", zap_get_version_major(), zap_get_version_minor(), zap_get_version_revision());
    zlog(NONE, "Inializing PHYSFS.");
    if (!PHYSFS_init(argv0))
    {
        zlog(FAIL, "Problem initializing PhysFS!");
        exit(1);
    }

    DATAFILE_NAME = datafile;

    game.fps = fps;
    zlog(INFO, "Frames Per Second: %d", game.fps);
    game.window_w = window_w;
    zlog(INFO, "Window Width: %d", game.window_w);
    game.window_h = window_h;
    zlog(INFO, "Window Height: %d", game.window_h);
    game.reserved_samples = 10;
    zlog(INFO, "Reserved Audio Samples: %d", game.reserved_samples);

    //register cleanup atexit functions
    /* zlog(LOAD, "Registering Cleanup Functions.");
    if (atexit(_exit_cleanup) != 0)
        zlog(FAIL, "Failed to register _exit_cleanup for atexit()"); */

        // Start Allegro
    allegro_init();

    //Bitmaps
    zlog(NONE, "Creating game view bitmap.");
    game.view = _create_bitmap(320, 200, "game.view");
    if (!game.view)
    {
        zlog(FAIL, "Couldn't create game.view");
        exit(1);
    }
    ZAP_PROGRESS_BAR *progbar = _create_progress_bar(96, 158, 132, 16, 255, 255, 255);

    game.sys_font = al_create_builtin_font();

    //Load splash from hardcoded data
    zlog(LOAD, "Loading Zap Engine Splash from memfile.");
    ALLEGRO_FILE *splashfp = al_open_memfile(zap_splash, sizeof(zap_splash), "r");
    game.splash = al_load_bitmap_f(splashfp, ".png");
    if (!game.splash)
        zlog(WARN, "Couldn't load Zap Engine Splash from memfile.");
    al_fclose(splashfp);
    _draw_splash_screen();

    //Load Datafile
    zlog(LOAD, "Mounting datafile.");
    if (!PHYSFS_mount(DATAFILE_NAME, NULL, 1)) //DATAFILE needs to be passed in from end-user
    {
        zlog(INFO, "Problem loading %s!", DATAFILE_NAME);
        exit(1);
    }
    al_set_physfs_file_interface();

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

    //Entering the Main Game Loop
    al_set_target_bitmap(game.view);

    //Load first scene
    zap_change_scene(first_scene);

    game.done = false;
    _main_event_loop();

    zlog(NONE, "Breaking from main loop.");

    _exit_cleanup();

    al_uninstall_system();
}

/* Initialize Allegro Stuff */
static void allegro_init(void)
{
    zlog(NONE, "Installing Allegro 5.");
    if (!al_install_system(ALLEGRO_VERSION_INT, NULL)) //because this is a shared library
    {
        zlog(FAIL, "Problem initializing Allegro!");
        exit(1);
    }

    //Initialize addons
    zlog(NONE, "Initializing Primitives Addon.");
    if (!al_init_primitives_addon())
    {
        zlog(FAIL, "Problem initializing Primitives Addon!");
        exit(1);
    }
    zlog(NONE, "Initializing Font Addon.");
    if (!al_init_font_addon())
    {
        zlog(FAIL, "Problem initializing Font Addon!");
        exit(1);
    }
    zlog(NONE, "Initializing Image Addon.");
    if (!al_init_image_addon())
    {
        zlog(FAIL, "Problem initializing Image Addon!");
        exit(1);
    }
    zlog(NONE, "Initializing Audio Addon.");
    if (!al_install_audio())
    {
        zlog(FAIL, "Problem initializing Audio!");
        exit(1);
    }
    zlog(NONE, "Initializing Audio Codec Addon.");
    if (!al_init_acodec_addon())
    {
        zlog(FAIL, "Problem initializing Audio Codec!");
        exit(1);
    }
    zlog(NONE, "Installing Keyboard.");
    if (!al_install_keyboard())
    {
        zlog(FAIL, "Problem installing Keyboard!");
        exit(1);
    }


    //Create display
    zlog(NONE, "Creating Display.");
    game.display = al_create_display(game.window_w, game.window_h);
    if (!game.display)
    {
        zlog(FAIL, "Problem creating display!");
        exit(1);
    }

    // Create update timer.
    zlog(NONE, "Creating Timer.");
    game.update_timer = al_create_timer(1.0f / game.fps);
    if (!game.update_timer)
    {
        zlog(FAIL, "Problem creating update timer!");
        exit(1);
    }

    // Create event queue.
    zlog(NONE, "Creating Event Queue.");
    game.event_queue = al_create_event_queue();
    if (!game.event_queue)
    {
        zlog(FAIL, "Problem creating Event Queue!");
        exit(1);
    }

    // Start libADLMidi
    _adlmidi_init();

    //Register even sources
    zlog(NONE, "Registering Display Event Source.");
    al_register_event_source(game.event_queue, al_get_display_event_source(game.display));
    zlog(NONE, "Registering Timer Event Source.");
    al_register_event_source(game.event_queue, al_get_timer_event_source(game.update_timer));
    zlog(NONE, "Registering Keyboard Event Source.");
    al_register_event_source(game.event_queue, al_get_keyboard_event_source());

    // Start update timer
    al_start_timer(game.update_timer);

    game.ticks = 0;
}
