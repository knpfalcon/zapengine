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

CFLAGS_DLL = -Wall -O3 -g -shared -Wl,--subsystem,windows,--out-implib,$(LIBDIR)/libzapengine.a

#Source files.
_SRC = \
%.c

########
SRC = $(patsubst %,$(SRCDIR)/%,$(_SRC))

_DEPS = \
base.h \
zlog.h \
actor.h \
internal/zintern_actor.h

_OBJ = \
zlog.o \
actor.o


#Headers
DEPS = $(patsubst %,$(INCLUDEDIR)/%,$(_DEPS))

#Object files - Add object files that correspond to source files
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: zapengine demo clean

demo : zapengine
	@cd $(BUILDDIR) && @mkdir demo > nul 2>&1 || (exit 0)
	$(CC) -I./build/zapengine/include -L./build/zapengine/lib demo/main.c -o build/demo/demo.exe -lzapengine -DDEBUG -DZLOG_ON
	@robocopy ./build/zapengine/bin/ ./build/demo zapengine.dll
zapengine: $(DLLDIR)/$(DLL)

$(DLLDIR)/$(DLL): $(OBJ)
	@cd $(BUILDDIR) && @mkdir zapengine > nul 2>&1 || (exit 0)
	@cd $(BUILDDIR) && @cd zapengine && @mkdir bin > nul 2>&1 || (exit 0)
	@cd $(BUILDDIR) && @cd zapengine && @mkdir lib > nul 2>&1 || (exit 0)
	$(CC) -shared $^ $(CFLAGS_DLL) $(LIBS) -o $@
	@Xcopy include\zapengine $(BUILDDIR)\zapengine\include\zapengine\ /H /C /I

$(ODIR)/%.o: $(SRC) $(DEPS)
	@mkdir $(BUILDDIR) > nul 2>&1 || (exit 0)
	@cd $(BUILDDIR) && @mkdir obj > nul 2>&1 || (exit 0)
	$(CC) $(INC) -o $@ -c $< $(CFLAGS) $(LIBS)

clean:
	@if exist $(BUILDDIR) rmdir /Q /S $(BUILDDIR)