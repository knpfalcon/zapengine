CC = gcc
CFLAGS = -O3 -Wall -g -static -DDEBUG -DZLOG_ON
LIBDIR =

LIBS = -lallegro_monolith-debug-static -ljpeg -ldumb -lFLAC -ldsound -lopusfile -lopus -lvorbisfile -lvorbis -lfreetype -logg -lpng16 -lzlib \
-lphysfs -lgdiplus -luuid -lkernel32 -lwinmm -lpsapi -lopengl32 -lglu32 -luser32 -lcomdlg32 \
-lgdi32 -lshell32 -lole32 -ladvapi32 -lws2_32 -lshlwapi -lwebp -l:libADLMIDI-static.a -static-libgcc -static-libstdc++ -lstdc++

INC = -I./include -I./include/zapengine -I./include/zapengine/internal

DLL = zapengine.dll
BUILDDIR = build
DLLDIR = $(BUILDDIR)/zapengine/bin
LIBDIR= $(BUILDDIR)/zapengine/lib
SRCDIR = src
INCLUDEDIR = include/zapengine
ODIR = $(BUILDDIR)/obj

CFLAGS_DLL = -Wall -O3 -g -shared -Wl,--subsystem,windows,--out-implib,$(LIBDIR)/libzapengine.a -DDEBUG -DZLOG_ON

#Source files.
_SRC = \
%.c

########
SRC = $(patsubst %,$(SRCDIR)/%,$(_SRC))

_DEPS = \
internal\zintern_actor.h \
internal\zintern_adlib.h \
internal\zintern_bitmap.h \
internal\zintern_camera.h \
internal\zintern_cleanup.h \
internal\zintern_collision.h \
internal\zintern_controls.h \
internal\zintern_draw.h \
internal\zintern_events.h \
internal\zintern_game.h \
internal\zintern_graphics.h \
internal\zintern_init.h \
internal\zintern_movement.h \
internal\zintern_progbar.h \
internal\zintern_scene.h \
internal\zintern_sound.h \
internal\zintern_update.h \
internal\zintern_version.h \
internal\zintern_zapsplash.h \
actor.h \
adlib.h \
base.h \
bitmap.h \
camera.h \
cleanup.h \
collision.h \
controls.h \
draw.h \
events.h \
game.h \
graphics.h \
init.h \
movement.h \
scene.h \
sound.h \
update.h \
zapengine.h \
zlog.h

_OBJ = \
actor.o \
adlib.o \
bitmap.o \
camera.o \
cleanup.o \
collision.o \
controls.o \
draw.o \
events.o \
game.o \
graphics.o \
init.o \
movement.o \
progbar.o \
scene.o \
sound.o \
update.o \
zlog.o


#Headers
DEPS = $(patsubst %,$(INCLUDEDIR)/%,$(_DEPS))

#Object files - Add object files that correspond to source files
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: zapengine demo clean run

demo : zapengine
	@cd $(BUILDDIR) && @mkdir demo > nul 2>&1 || (exit 0)
	@cd demo && GenerateDataHeader.bat
	@cd demo && MakeDatafile.bat
	$(CC) $(CFLAGS) -I./build/zapengine/include -L./build/zapengine/lib demo/main.c -o build/demo/demo.exe -lzapengine
	@robocopy ./build/zapengine/bin/ ./build/demo zapengine.dll || (exit 0)

zapengine: $(DLLDIR)/$(DLL)

$(DLLDIR)/$(DLL): $(OBJ)
	@cd $(BUILDDIR) && @mkdir zapengine > nul 2>&1 || (exit 0)
	@cd $(BUILDDIR) && @cd zapengine && @mkdir bin > nul 2>&1 || (exit 0)
	@cd $(BUILDDIR) && @cd zapengine && @mkdir lib > nul 2>&1 || (exit 0)
	$(CC) -shared $^ $(CFLAGS_DLL) $(LIBS) -o $@
	@Xcopy include\zapengine $(BUILDDIR)\zapengine\include\zapengine\ /H /C /I /Y

$(ODIR)/%.o: $(SRC) $(DEPS)
	@mkdir $(BUILDDIR) > nul 2>&1 || (exit 0)
	@cd $(BUILDDIR) && @mkdir obj > nul 2>&1 || (exit 0)
	$(CC) $(INC) -o $@ -c $< $(CFLAGS) $(LIBS)

clean:
	@if exist $(BUILDDIR) rmdir /Q /S $(BUILDDIR)
	@cd demo && del data.h

run: demo
	@cd build/demo && demo.exe