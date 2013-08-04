# Define compilation type
OSTYPE=msys
#OSTYPE=a320-od
#OSTYPE=gcw0-od

PRGNAME     = manicminer

# define regarding OS, which compiler to use
ifeq "$(OSTYPE)" "msys"	
EXESUFFIX = .exe
TOOLCHAIN = /d/MinGW
CC          = gcc
CCP          = g++
LD          = gcc
else
ifeq "$(OSTYPE)" "a320-od"	
TOOLCHAIN = /opt/opendingux-toolchain/usr
else
TOOLCHAIN = /opt/gcw0-toolchain/usr
endif
EXESUFFIX = .dge
CC = $(TOOLCHAIN)/bin/mipsel-linux-gcc
CCP = $(TOOLCHAIN)/bin/mipsel-linux-g++
LD = $(TOOLCHAIN)/bin/mipsel-linux-g++
endif

# add SDL dependencies
SDL_LIB     = $(TOOLCHAIN)/lib
SDL_INCLUDE = $(TOOLCHAIN)/include

INCLUDES = -I./modplay

# change compilation / linking flag options
ifeq "$(OSTYPE)" "msys"	
F_OPTS 		= -fomit-frame-pointer -ffunction-sections -ffast-math -fsingle-precision-constant -fsigned-char 
CC_OPTS		= -O2 $(F_OPTS) -g 
CFLAGS      = -I$(SDL_INCLUDE) $(INCLUDES) $(CC_OPTS)
CXXFLAGS	= $(CFLAGS) -fno-rtti -fno-exceptions
LDFLAGS     = -L$(SDL_LIB)  -lmingw32 -lSDLmain -lSDL -mwindows
else
F_OPTS 		= -fomit-frame-pointer -ffunction-sections -ffast-math -fsingle-precision-constant -fsigned-char 
ifeq "$(OSTYPE)" "a320-od"	
CC_OPTS		= -O2 -mips32 -msoft-float -G0 -D_OPENDINGUX_ $(F_OPTS)
else
CC_OPTS		= -O2 -mips32 -mhard-float -G0 -D_OPENDINGUX_ $(F_OPTS)
endif
CFLAGS      = -I$(SDL_INCLUDE) $(INCLUDES) $(CC_OPTS)
CXXFLAGS	= -fno-exceptions -fno-rtti $(CFLAGS) 
LDFLAGS     = -L$(SDL_LIB) $(CC_OPTS) -lSDL 
endif

# Files to be compiled
SRCDIR   = . ./opendingux
VPATH    = $(SRCDIR)
SRC_C    = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CP   = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
OBJ_C    = $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CP   = $(notdir $(patsubst %.cpp, %.o, $(SRC_CP)))
OBJS     = $(OBJ_C) $(OBJ_CP)

# Rules to make executable
$(PRGNAME)$(EXESUFFIX): $(OBJS)  modplay/libmodplay.a
ifeq "$(OSTYPE)" "msys"	
	$(LD) $(CFLAGS) -o $(PRGNAME)$(EXESUFFIX) $^ $(LDFLAGS)
else
	$(LD) $(LDFLAGS) -o $(PRGNAME)$(EXESUFFIX) $^
endif

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_CP) : %.o : %.cpp
	$(CCP) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(PRGNAME)$(EXESUFFIX) *.o
