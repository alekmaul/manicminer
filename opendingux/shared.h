#ifndef SHARED_H
#define SHARED_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>

#include <SDL/SDL.h>

// defines and macros
#define MAX__PATH 1024

#define GF_GAMEINIT    1
#define GF_GAMERUNNING 2
#define GF_MAINUI      3
#define GF_GAMEQUIT    4

#ifndef O_BINARY
#define O_BINARY 0
#endif

#define true 1
#define false 0
typedef int bool;

typedef	unsigned int	DWORD;
typedef	unsigned short	WORD;
typedef	unsigned char	BYTE;

#define GF_TITLES     0
#define GF_DEMO       1
#define GF_GAME       2
#define GF_LOADING    3
#define GF_QUIT       4

#define SYSVID_WIDTH  256
#define SYSVID_HEIGHT 192

#define MANIC_SKIN_SIZE 0x13036
extern unsigned char MANIC_SKIN[];

extern DWORD SCORE;
extern DWORD EXTRA;
extern BYTE	MODE;
extern BYTE	LOADm;
extern BYTE	page;
extern WORD FrCt;
extern BYTE	GAMEm;
extern BYTE	DEMOm;
extern BYTE	TITLEm;
extern BYTE	OVERm;
extern BYTE	INK;
extern BYTE	PAPER;
extern int TONKS;

extern BYTE	PALact[768];
extern BYTE	cMAP[512];
extern BYTE	cCRUMB[512];
extern char	cTITLE[33];
extern BYTE	cBGink;
extern BYTE	cBGpaper;
extern BYTE	cPLAT1ink;
extern BYTE	cPLAT1paper;
extern BYTE	cPLAT2ink;
extern BYTE	cPLAT2paper;
extern BYTE	cWALLink;
extern BYTE	cWALLpaper;
extern BYTE	cCRUMBink;
extern BYTE	cCRUMBpaper;
extern BYTE	cKILL1ink;
extern BYTE	cKILL1paper;
extern BYTE	cKILL2ink;
extern BYTE	cKILL2paper;
extern BYTE	cCONVink;
extern BYTE	cCONVpaper;
extern BYTE	cBORDER;
extern BYTE	cPLAT1gfx;
extern BYTE	cPLAT2gfx;
extern BYTE	cWALLgfx;
extern BYTE	cCRUMBgfx;
extern BYTE	cKILL1gfx;
extern BYTE	cKILL2gfx;
extern BYTE	cCONVgfx;
extern BYTE	cEXITgfx;
extern BYTE	cKEYgfx;

extern WORD	cWILLYx;
extern WORD	cWILLYy;
extern WORD	cWILLYxold[2];
extern WORD	cWILLYyold[2];
extern WORD	cWILLYf;
extern BYTE	cWILLYd;
extern BYTE	cWILLYm;
extern BYTE	cWILLYj;
extern BYTE	cWILLYbuff[2][256];
extern WORD	cWILLYfall;
extern WORD	cWILLYjs;
extern BYTE	cWILLYcol[128][256];
extern WORD	cCONVx;
extern WORD	cCONVy;
extern BYTE	cCONVd;
extern BYTE	cCONVl;
extern BYTE	cCONVf;
extern BYTE	cCONVm;
extern BYTE	cCONV1;
extern WORD	cKEYx[5];
extern WORD	cKEYy[5];
extern BYTE	cKEYb[5];
extern BYTE	cKEYs[5];
extern WORD	cSWITCHx[2];
extern WORD	cSWITCHy[2];
extern BYTE	cSWITCHs[2];
extern WORD cEXITx;
extern WORD cEXITy;
extern BYTE	cEXITb;
extern BYTE	cEXITm;
extern BYTE	cAIR;
extern BYTE	cAIRp;
extern BYTE	cHROBOink[4];
extern BYTE	cHROBOpaper[4];
extern WORD	cHROBOx[4];
extern WORD	cHROBOy[4];
extern WORD	cHROBOmin[4];
extern WORD	cHROBOmax[4];
extern BYTE	cHROBOd[4];
extern BYTE	cHROBOs[4];
extern WORD	cHROBOgfx[4];
extern BYTE	cHROBOflip[4];
extern BYTE	cHROBOanim[4];
extern WORD	cHROBOxold[4][2];
extern WORD	cHROBOyold[4][2];
extern BYTE	cVROBOink[4];
extern BYTE	cVROBOpaper[4];
extern WORD	cVROBOx[4];
extern WORD	cVROBOy[4];
extern WORD	cVROBOmin[4];
extern WORD	cVROBOmax[4];
extern BYTE	cVROBOd[4];
extern BYTE	cVROBOs[4];
extern WORD	cVROBOgfx[4];
extern BYTE	cVROBOanim[4];
extern WORD	cVROBOxold[4][2];
extern WORD	cVROBOyold[4][2];
extern WORD EUGENEx;
extern WORD EUGENEy;
extern WORD EUGENEmin;
extern WORD EUGENEmax;
extern BYTE	EUGENEd;
extern BYTE	EUGENEm;
extern BYTE	EUGENEc;
extern WORD	EUGENExold[2];
extern WORD	EUGENEyold[2];
extern BYTE	SWITCH1m;
extern BYTE	SWITCH2m;
extern WORD HOLEy;
extern BYTE	HOLEl;
extern WORD KONGx;
extern WORD KONGy;
extern WORD	KONGxold[2];
extern WORD	KONGyold[2];
extern WORD KONGmax;
extern BYTE KONGm;
extern BYTE KONGc;
extern BYTE KONGf;
extern BYTE KONGp;
extern WORD	SKYx[3];
extern WORD	SKYy[3];
extern WORD	SKYmax[3];
extern WORD	SKYxold[3][2];
extern WORD	SKYyold[3][2];
extern BYTE	SKYs[3];
extern BYTE	SKYf[3];
extern BYTE	SKYm[3];
extern BYTE	SKYc[3];
extern BYTE	SKYp[3];
extern BYTE DEATHm;
extern WORD DEATHc;
extern WORD BOOTy;
extern WORD SUNy;
extern BYTE SUNm;
extern BYTE SUNh;
extern BYTE	SUNbuff[2][384];
extern WORD	SUNyold[2];
extern BYTE	SUNhold[2];
extern WORD	SPGx[2][64];
extern WORD	SPGy[2][64];
extern DWORD SCORE;
extern DWORD HISCORE;
extern DWORD EXTRA;
extern BYTE EXTRAm;
extern BYTE EXTRAc;
extern WORD LIVES;
extern BYTE LIVESf;
extern BYTE LIVESp;
extern BYTE LEVEL;
extern BYTE MUSICon;
extern BYTE old;
extern BYTE SPEED;
extern BYTE GAMEm;
extern BYTE DEMOm;
extern BYTE DEMOp;
extern BYTE TITLEm;
extern BYTE TITLEwf;
extern BYTE TITLEwp;
extern BYTE OVERm;
extern BYTE OVERink;
extern BYTE OVERp;
extern BYTE INK;
extern BYTE PAPER;
extern BYTE CHEAT;
extern BYTE CHEATp;
extern BYTE CHEATh;
extern BYTE LOADm;
extern DWORD LOADp;

extern BYTE PREFSm;
extern BYTE PREFSh1;
extern BYTE PREFSh2;
extern BYTE PREFSh3;

#define PIX_TO_RGB(fmt, r, g, b) (((r>>fmt->Rloss)<<fmt->Rshift)| ((g>>fmt->Gloss)<<fmt->Gshift)|((b>>fmt->Bloss)<<fmt->Bshift))

typedef struct {
  unsigned int sndLevel;
  unsigned int m_ScreenRatio; // 0 = original show, 1 = full screen
  unsigned int OD_Joy[12]; // each key mapping
  unsigned int m_DisplayFPS;
  unsigned int m_Scanline;
  char current_dir_rom[MAX__PATH];
} gamecfg;


extern SDL_Surface* screen;						// Main program screen
extern SDL_Surface* actualScreen;						// Main program screen

extern SDL_Surface *layer,*layerback,*layerbackgrey;

extern SDL_Event event;

extern gamecfg GameConf;

extern char current_conf_app[MAX__PATH];

// menu
extern void screen_showtopmenu(void);
extern void print_string_video(int x, int y, const char *s);

extern void system_loadcfg(char *cfg_name);
extern void system_savecfg(char *cfg_name);

extern void gethomedir(char *dir, char* name);

#endif
