# Define compilation type
OSTYPE=msys
#OSTYPE=a320-od
#OSTYPE=gcw0-od


# define compilation default flags
CFLAGS=-std=c99 -O2 -Os -W -Wall -Wno-long-long -ansi -pedantic
CFLAGS+=-Wno-unused-parameter

# define regarding OS, which compiler to use
ifeq "$(OSTYPE)" "msys"	
CC=gcc
AR=ar
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
F_OPTS 		= -fomit-frame-pointer -ffunction-sections -ffast-math -fsingle-precision-constant 
ifeq "$(OSTYPE)" "a320-od"	
CC_OPTS		= -O2 -mips32 -mips32 -mtune=mips32r2 -mno-mips16 -msoft-float -G0 -D_OPENDINGUX_ $(F_OPTS)
else
CC_OPTS		= -O2 -mips32 -mips32 -mtune=mips32r2 -mno-mips16 -mhard-float -G0 -D_OPENDINGUX_ $(F_OPTS)
endif
CFLAGS+=$(CC_OPTS)
endif

LIBS=

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Files to be compiled
CFILES = $(wildcard *.c)
OFILES = $(CFILES:%.c=%.o)

all: libmodplay.a

# Rules to make library
libmodplay.a: $(OFILES)
	$(AR) -r $@ $^

clean:
	rm -f libmodplay.a $(OFILES)
