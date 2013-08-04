#include "opendingux/shared.h"
#include "modplay/modplay.h"

gamecfg GameConf;

unsigned int m_Flag;

char current_conf_app[MAX__PATH];
SDL_Surface *layer,*layerback,*layerbackgrey;
SDL_Surface *actualScreen, *screen;
short manic_palette[256];

SDL_Event event;
SDL_Joystick *stick = NULL;
#define JOYSTICK_AXIS 8192

MODFILE mod;
SDL_AudioSpec spec;
SDL_AudioSpec obtained;
SDL_mutex *sndlock;

unsigned char XBuf[256*192];

///////////////////////////////////////////////////////////////
//	Globals
///////////////////////////////////////////////////////////////

BYTE		KeyTable[256];

BYTE	page;

WORD  FrCt;
WORD	NEXTBIT=0;

BYTE	bright[]= {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1};
BYTE	bright2[]={0,1,2,3,4,3,2,1,0,1,2,3,4,3,2,1};

#define	KONGPAUSE	8

BYTE	PALwhite[768];
BYTE	PALblack[768];
BYTE	PALfade[768];
BYTE	PALover[768];
BYTE	PALact[768];

///////////////////////////////////////////////////////////////
//	Current Map Info
///////////////////////////////////////////////////////////////

BYTE	cMAP[512];
BYTE	cCRUMB[512];
char	cTITLE[33];

BYTE	cBGink;
BYTE	cBGpaper;

BYTE	cPLAT1ink;
BYTE	cPLAT1paper;

BYTE	cPLAT2ink;
BYTE	cPLAT2paper;

BYTE	cWALLink;
BYTE	cWALLpaper;

BYTE	cCRUMBink;
BYTE	cCRUMBpaper;

BYTE	cKILL1ink;
BYTE	cKILL1paper;

BYTE	cKILL2ink;
BYTE	cKILL2paper;

BYTE	cCONVink;
BYTE	cCONVpaper;

BYTE	cBORDER;

BYTE	cPLAT1gfx;
BYTE	cPLAT2gfx;
BYTE	cWALLgfx;
BYTE	cCRUMBgfx;
BYTE	cKILL1gfx;
BYTE	cKILL2gfx;
BYTE	cCONVgfx;
BYTE	cEXITgfx;
BYTE	cKEYgfx;

WORD	cWILLYx;
WORD	cWILLYy;
WORD	cWILLYxold[2];
WORD	cWILLYyold[2];
WORD	cWILLYf;
BYTE	cWILLYd;
BYTE	cWILLYm;
BYTE	cWILLYj;
BYTE	cWILLYbuff[2][256];
WORD	cWILLYjp[]={4,4,3,3,2,2,1,1,0,0,1,1,2,2,3,3,4,4};
WORD	cWILLYfall;
WORD	cWILLYjs;
BYTE	cWILLYcol[128][256];

WORD	cCONVx;
WORD	cCONVy;
BYTE	cCONVd;
BYTE	cCONVl;
BYTE	cCONVf;
BYTE	cCONVm;
BYTE	cCONV1;

WORD	cKEYx[5];
WORD	cKEYy[5];
BYTE	cKEYb[5];
BYTE	cKEYs[5];

WORD	cSWITCHx[2];
WORD	cSWITCHy[2];
BYTE	cSWITCHs[2];

WORD	cEXITx;
WORD	cEXITy;
BYTE	cEXITb;
BYTE	cEXITm;

BYTE	cAIR;
BYTE	cAIRp;

BYTE	cHROBOink[4];
BYTE	cHROBOpaper[4];
WORD	cHROBOx[4];
WORD	cHROBOy[4];
WORD	cHROBOmin[4];
WORD	cHROBOmax[4];
BYTE	cHROBOd[4];
BYTE	cHROBOs[4];
WORD	cHROBOgfx[4];
BYTE	cHROBOflip[4];
BYTE	cHROBOanim[4];
WORD	cHROBOxold[4][2];
WORD	cHROBOyold[4][2];

BYTE	cVROBOink[4];
BYTE	cVROBOpaper[4];
WORD	cVROBOx[4];
WORD	cVROBOy[4];
WORD	cVROBOmin[4];
WORD	cVROBOmax[4];
BYTE	cVROBOd[4];
BYTE	cVROBOs[4];
WORD	cVROBOgfx[4];
BYTE	cVROBOanim[4];
WORD	cVROBOxold[4][2];
WORD	cVROBOyold[4][2];

///////////////////////////////////////////////////////////////
//	Special Robots
///////////////////////////////////////////////////////////////

WORD	EUGENEx;
WORD	EUGENEy;
WORD	EUGENEmin;
WORD	EUGENEmax;
BYTE	EUGENEd;
BYTE	EUGENEm;
BYTE	EUGENEc;
WORD	EUGENExold[2];
WORD	EUGENEyold[2];

BYTE	SWITCH1m;
BYTE	SWITCH2m;

WORD	HOLEy;
BYTE	HOLEl;

WORD	KONGx;
WORD	KONGy;
WORD	KONGxold[2];
WORD	KONGyold[2];
WORD	KONGmax;
BYTE	KONGm;
BYTE	KONGc;
BYTE	KONGf;
BYTE	KONGp;

WORD	SKYx[3];
WORD	SKYy[3];
WORD	SKYmax[3];
WORD	SKYxold[3][2];
WORD	SKYyold[3][2];
BYTE	SKYs[3];
BYTE	SKYf[3];
BYTE	SKYm[3];
BYTE	SKYc[3];
BYTE	SKYp[3];

BYTE	DEATHm;
WORD	DEATHc;

WORD	BOOTy;

WORD	SUNy;
BYTE	SUNm;
BYTE	SUNh;
BYTE	SUNbuff[2][384];
WORD	SUNyold[2];
BYTE	SUNhold[2];

///////////////////////////////////////////////////////////////
//	Solar Power Generator
///////////////////////////////////////////////////////////////

WORD	SPGx[2][64];
WORD	SPGy[2][64];

///////////////////////////////////////////////////////////////
//	Game Globals
///////////////////////////////////////////////////////////////
#define EXTRAdelta 10000

DWORD	SCORE;
DWORD	HISCORE=0;
DWORD	EXTRA;
BYTE		EXTRAm;
BYTE		EXTRAc;

WORD	LIVES;
BYTE	LIVESf;
BYTE	LIVESp;
BYTE	LEVEL=0;

BYTE	MUSICon=1;

BYTE	old=0;

BYTE	SPEED=2;

BYTE	MODE=GF_LOADING;
BYTE	GAMEm=0;

BYTE	DEMOm=0;
BYTE	DEMOp;

BYTE	TITLEm=0;
BYTE	TITLEwf;
BYTE	TITLEwp;

BYTE	OVERm=0;
BYTE	OVERink;
BYTE	OVERp;

BYTE	INK=7;
BYTE	PAPER=0;

BYTE	CHEAT=0;
BYTE	CHEATp=0;
BYTE	CHEATh;
BYTE	CHEATkey[]={9,11,3,10,3,7};

BYTE	PAUSE;
BYTE	LASTm;
WORD	LASTc;
BYTE	LASTp;
WORD	WINDOW[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

BYTE	TEXTm;
WORD	TEXTpause;
BYTE	TEXTpoint;
BYTE	TEXTink;
BYTE	TEXTfade;

///////////////////////////////////////////////////////////////

BYTE	PIANOkhit[32];
BYTE	PIANOkey[]={0,1,1,2,0,1,2,0,1,1,2,0,1,2,0,1,2,0,1,1,2,0,1,2,0,1,1,2,0,1,2,3};
WORD	PIANOc;
BYTE	PIANObodge1;
BYTE	PIANObodge2;
BYTE	PIANObodgep;
BYTE	PIANObodgep2;

BYTE	SCROLLbuff[]="                                 ";
WORD	SCROLLpos;
BYTE	PIXELbuff[264*8];
WORD	PIXELoff;

BYTE	LOADm;
DWORD  LOADp;

BYTE	PREFSm;
BYTE	PREFSh1;
BYTE	PREFSh2;
BYTE	PREFSh3;

BYTE	CHAN[]={0,1,2,8,9,10,16,17,18};


///////////////////////////////////////////////////////////////
//	Tales from a Parallel Universe
///////////////////////////////////////////////////////////////

int TONKS=0;

BYTE MUSICtype;

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
void gaphics_scanline(unsigned short y, unsigned short width, unsigned short *buf) {
	#define SCANLINE_INTENSITY 0x18E3
	unsigned int x;
	unsigned short *pScr=buf;
	
    if (y & 1) {
		for (x=0;x<width;x++)  {
			*pScr -= (*pScr>>3) & SCANLINE_INTENSITY; 
			pScr++;
		}
	}
    else {
		for (x=0;x<width;++x) {
			*pScr += (~*pScr>>3) & SCANLINE_INTENSITY; 
			pScr++;
		}
	}
}

void SDL_ScaleSurface(void) {
	unsigned short *buffer_scr = (unsigned short *) actualScreen->pixels;
	unsigned char *buffer_flip = (unsigned char *) XBuf;
	unsigned int W,H,ix,iy,x,y, xfp,yfp;
	static char buffer[32];

	if(SDL_MUSTLOCK(actualScreen)) SDL_LockSurface(actualScreen);
	
	if (GameConf.m_ScreenRatio) { // Full screen
		x=0;
		y=0; 
		W=320;
		H=240;
		ix=(SYSVID_WIDTH<<16)/W;
		iy=(SYSVID_HEIGHT<<16)/H;

		do   
		{
			unsigned char *buffer_mem=(buffer_flip+((y>>16)*SYSVID_WIDTH));
			W=320; x=0;
			do {
				*buffer_scr++=manic_palette[buffer_mem[x>>16]];
				x+=ix;
			} while (--W);
			if (GameConf.m_Scanline) gaphics_scanline(240-H,320,buffer_scr-320);
			y+=iy;
		} while (--H);
	}
	else { // Original show
		x=((screen->w - SYSVID_WIDTH)/2);
		y=((screen->h - SYSVID_HEIGHT)/2); 
		W=SYSVID_WIDTH;
		H=SYSVID_HEIGHT;
		ix=(SYSVID_WIDTH<<16)/W;
		iy=(SYSVID_HEIGHT<<16)/H;
		
		buffer_scr += (y-5)*320;
		buffer_scr += (x);
		do   
		{
			unsigned char *buffer_mem=(buffer_flip+((y>>16)*SYSVID_WIDTH));
			W=SYSVID_WIDTH; x=((screen->w - SYSVID_WIDTH)/2);
			do {
				*buffer_scr++=manic_palette[buffer_mem[x>>16]];
				x+=ix;
			} while (--W);
			if (GameConf.m_Scanline) gaphics_scanline(y>>16,SYSVID_WIDTH,buffer_scr-SYSVID_WIDTH);
			y+=iy;
			buffer_scr += actualScreen->pitch - 320 - SYSVID_WIDTH;
		} while (--H);
	}
			
	if (SDL_MUSTLOCK(actualScreen)) SDL_UnlockSurface(actualScreen);
	SDL_Flip(actualScreen);
}

///////////////////////////////////////////////////////////////
//	Revision Number
///////////////////////////////////////////////////////////////
char	VERSION[]={"V1.00"};

///////////////////////////////////////////////////////////////
//	Includes
///////////////////////////////////////////////////////////////
void musicLoadXM(unsigned int len, unsigned char *pMod);
void sfxLoadWAV(unsigned int len, unsigned char *pWav, unsigned int frequency);

#include "./data/DIE_WAV.h"
#include "./data/PICK_WAV.h"
#include "./data/JUMP_WAV.h"

#include "./data/FINAL_XM.h"
#include "./data/INGAME_XM.h"
#include "./data/LASTFIRST_XM.h"
#include "./data/OPTIONS_XM.h"
#include "./data/ORIGINAL_XM.h"
#include "./data/TITLE_XM.h"

#include	"./gfx/mm-pal.c"

#include	"./gfx/mm-blocx.c"
#include	"./gfx/mm-conv.c"
#include	"./gfx/mm-exits.c"
#include	"./gfx/mm-keys2.c"
#include	"./gfx/mm-tplat.c"
#include	"./gfx/mm-air.c"
#include    "./gfx/mm-hrob2.c"
#include	"./gfx/mm-vrobo.c"
#include	"./gfx/mm-final.c"
#include	"./gfx/mm-swit.c"
#include	"./gfx/mm-font.c"
#include	"./gfx/mm-fant.c"
#include	"./gfx/mm-over.c"

#include	"./gfx/mm-eug2.c"
#include	"./gfx/mm-kong.c"
#include	"./gfx/mm-sky.c"
#include	"./gfx/mm-sun.c"
#include	"./gfx/mm-fill.c"
#include	"./gfx/mm-piano.c"
#include	"./gfx/mm-pkeys.c"
#include	"./gfx/mm-load.c"

#include	"./gfx/mm-willy.c"
#include	"./gfx/mm-ftsml.c"

#include	"./gfx/mm-house.c"
#include	"./gfx/mm-win.c"

#include	"./mm-keydf.inc"
#include	"./mm-map2.inc"
#include	"./mm-end.inc"

#include "./manic.inc"

#define CHUNK_NUM 7
#define MAXSND_NUM 8
typedef struct {
  unsigned char *buf;
  unsigned int len;
} sound_t;
typedef struct {
	sound_t *snd;
	unsigned char *buf;
	unsigned int len;
	char loop;
} channel_t;
static channel_t channel[MAXSND_NUM];
static sound_t chunk[CHUNK_NUM];

void audio_callback(void *userdata, Uint8 *stream, int len) {
	unsigned short c;
	signed short s;
	unsigned int i;

	MODFILE *mod = userdata;

	SDL_mutexP(sndlock);

	if (mod->songlength) {
		mod->mixingbuf = (void*)stream;
		mod->mixingbuflen = len;
		MODFILE_Player(mod);
	}

	for (i = 0; i < len; i++) {
		s = stream[i]-0x80;
		for (c = 0; c < MAXSND_NUM; c++) {
			if (channel[c].loop != 0) {  /* channel is active */
				if (channel[c].len > 0) {  /* not ending */
					s += *channel[c].buf-0x80;
					channel[c].buf++;
					channel[c].len--;
				}
				else {  /* ending */
					channel[c].loop--;
				}
			}
		}
		s += 0x80;
		if (s>0xff) s=0xff;
		if (s<0) s = 0;
		stream[i] = (unsigned char) s;
	}

	SDL_mutexV(sndlock);
}

void initSDL(void) 
{
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
		exit(1);
	}
	atexit(SDL_Quit);

	actualScreen = SDL_SetVideoMode(320, 240, 16, SDL_DOUBLEBUF | SDL_HWSURFACE );
	if(actualScreen == NULL) {
		fprintf(stderr, "Couldn't set video mode: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_ShowCursor(SDL_DISABLE);

    screen = SDL_CreateRGBSurface (actualScreen->flags,
                                actualScreen->w,
                                actualScreen->h,
                                actualScreen->format->BitsPerPixel,
                                actualScreen->format->Rmask,
                                actualScreen->format->Gmask,
                                actualScreen->format->Bmask,
                                actualScreen->format->Amask);
								
	if(screen == NULL) {
		fprintf(stderr, "Couldn't create surface: %s\n", SDL_GetError());
		exit(1);
	}

	// Init new layer to add background and text
	layer = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, 16, 0,0,0,0);
	if(layer == NULL) {
		fprintf(stderr, "Couldn't create surface: %s\n", SDL_GetError());
		exit(1);
	}
	layerback = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, 16, 0,0,0,0);
	if(layerback == NULL) {
		fprintf(stderr, "Couldn't create surface: %s\n", SDL_GetError());
		exit(1);
	}
	layerbackgrey = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, 16, 0,0,0,0);
	if(layerbackgrey == NULL) {
		fprintf(stderr, "Couldn't create surface: %s\n", SDL_GetError());
		exit(1);
	}

	MODFILE_Init(&mod);

	spec.freq = 44100;
	spec.format = AUDIO_U8;
	spec.channels = 2;
	spec.samples = 44100/60;
	spec.callback = audio_callback;
	spec.userdata = &mod;

	if (SDL_OpenAudio(&spec, &obtained) < 0) {
		fprintf(stderr, "Couldn't start audio: %s\n", SDL_GetError());
		exit(1);
	}

	sndlock = SDL_CreateMutex();
	if (sndlock == NULL) {
		fprintf(stderr,"Couldn't create lock: %s\n", SDL_GetError());
		SDL_CloseAudio();
		return;
	}

	// Init joystick
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	SDL_JoystickEventState(SDL_ENABLE);
	stick = SDL_JoystickOpen(0);
}

void musicLoadXM(unsigned int len, unsigned char *pMod) {
	SDL_PauseAudio(1);

	MODFILE_loadxm_from_buffer(len, pMod, &mod,
		obtained.freq, obtained.channels,
		obtained.format == AUDIO_S16 || obtained.format == AUDIO_U16 ? 16 : 8,
		obtained.format == AUDIO_S16 || obtained.format == AUDIO_S8);

	SDL_PauseAudio(0);
}

void sfxLoadWAV(unsigned int len, unsigned char *pWav, unsigned int frequency) {
    SDL_AudioSpec wave;
    Uint8 *data;
    Uint32 dlen;
    SDL_AudioCVT cvt;
	int i;
	    
	i = 0;
	SDL_mutexP(sndlock);
	while ((channel[i].loop == 0) && (channel[i].loop != 0) && (i < CHUNK_NUM))
		i++;
	if (i == CHUNK_NUM)
		i = -1;

	if (i >= 0) {
		// Load the sound file and convert it to 16-bit stereo at 44,1kHz 
		SDL_RWops *rw = SDL_RWFromMem(pWav, len);
		if ( SDL_LoadWAV_RW(rw,1, &wave, &data, &dlen) != NULL ) {
			SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, frequency /*wave.freq*/, AUDIO_U8, 2, 44100);
			cvt.buf = malloc(dlen*cvt.len_mult);
			memcpy(cvt.buf, data, dlen);
			cvt.len = dlen;
			SDL_ConvertAudio(&cvt);
			SDL_FreeWAV(data);

			if (chunk[i].buf) free(chunk[i].buf);
			
			chunk[i].buf = cvt.buf;
			chunk[i].len = cvt.len_cvt;
			//sfx.dpos = 0;

			channel[i].loop = 1;
			channel[i].snd = &chunk[i];
			channel[i].buf = chunk[i].buf;
			channel[i].len = chunk[i].len;
		}
	}
	SDL_mutexV(sndlock);

}

int main(int argc, char *argv[]) {
	SDL_Event event;
	
	// Get init file directory & name
	gethomedir(current_conf_app, "manicminer");
	sprintf(current_conf_app,"%s//manicminer.cfg",current_conf_app);

	
	initSDL();
	
	m_Flag = GF_GAMEINIT;
	LoadInfo();

	SDL_WM_SetCaption("manic miner", NULL);

	while (m_Flag != GF_GAMEQUIT) {
		SDL_PollEvent(&event);
		unsigned char *keys = SDL_GetKeyState(NULL);

		switch (m_Flag) {
			case GF_GAMEINIT:
				if (!GameConf.m_ScreenRatio) {
					screen_prepback(actualScreen, MANIC_SKIN, MANIC_SKIN_SIZE);
					SDL_Flip(actualScreen);
					screen_prepback(actualScreen, MANIC_SKIN, MANIC_SKIN_SIZE);
					SDL_Flip(actualScreen);
				}

				MODE = GF_LOADING;

				PaletteSet(PALmain);

				LOADm=0;
				page = 0;
				FrCt = 0;
				SDL_PauseAudio(0);
				m_Flag = GF_GAMERUNNING;
				break;

			case GF_MAINUI:
				SDL_PauseAudio(1);
				screen_showtopmenu();
				SDL_PauseAudio(0);
				break;
		
			case GF_GAMERUNNING:
				if (MODE == GF_QUIT) m_Flag = GF_GAMEQUIT;
				//while (MODE != GF_QUIT) {
				switch (MODE) {
				  case GF_TITLES:
					Titles(); 
					break;
				 
				  case GF_DEMO:
					DoDemo();
					break;

				  case GF_LOADING:
					DoLoading();
					break;
				
				  case GF_GAME:
					DoGame();
					break;
				}

				KeyTable[key_a] = 0;
				KeyTable[key_esc] = 0;
				KeyTable[key_return] = 0;
				KeyTable[key_f1] = 0;
				KeyTable[key_f2] = 0;
				KeyTable[key_f4] = 0;

				KeyTable[key_q] = 0;
				KeyTable[key_w] = 0;
				KeyTable[key_z] = 0;

				// check if a key is pressed
#if 0
				while(SDL_PollEvent(&event)) {
					switch (event.type)	{
						case SDL_KEYDOWN:
							if (event.key.keysym.sym == SDLK_LEFT) KeyTable[key_q] = 1;
							if (event.key.keysym.sym == SDLK_RIGHT) KeyTable[key_w] = 1;
							if (event.key.keysym.sym == SDLK_LCTRL) KeyTable[key_z] = 1;
							if (event.key.keysym.sym == SDLK_LALT) KeyTable[key_z] = 1;
							break;
						case SDL_KEYUP:
							if (event.key.keysym.sym == SDLK_LEFT) KeyTable[key_q] = 0;
							if (event.key.keysym.sym == SDLK_RIGHT) KeyTable[key_w] = 0;
							if (event.key.keysym.sym == SDLK_LCTRL) KeyTable[key_z] = 0;
							if (event.key.keysym.sym == SDLK_LALT) KeyTable[key_z] = 0;

							if (event.key.keysym.sym == SDLK_SPACE) KeyTable[key_esc] = 1;
							if (event.key.keysym.sym == SDLK_LSHIFT) KeyTable[key_f4] = 1;

							if (event.key.keysym.sym == SDLK_BACKSPACE) KeyTable[key_a] = 1;
							if (event.key.keysym.sym == SDLK_TAB) KeyTable[key_f2] = 1;

							if (event.key.keysym.sym == SDLK_RETURN) KeyTable[key_return] = 1;
							if (event.key.keysym.sym == SDLK_ESCAPE) KeyTable[key_f1] = 1;
							break;
						case SDL_QUIT:
							MODE = GF_QUIT;
							break;
					}
				} // while(SDL_PollEvent(&event)
#endif
				if (keys[SDLK_LEFT] == SDL_PRESSED) {KeyTable[key_q] = 1; }
				if (keys[SDLK_RIGHT] == SDL_PRESSED) {KeyTable[key_w] = 1; }
				if ((keys[SDLK_LCTRL] == SDL_PRESSED) || (keys[SDLK_LALT] == SDL_PRESSED)) { KeyTable[key_z] = 1; }

				if (keys[SDLK_SPACE] == SDL_PRESSED) { KeyTable[key_esc] = 1; }
				if (keys[SDLK_LSHIFT] == SDL_PRESSED) { KeyTable[key_f4] = 1; }

				if (keys[SDLK_BACKSPACE] == SDL_PRESSED) { KeyTable[key_a] = 1; }
				if (keys[SDLK_TAB] == SDL_PRESSED) { KeyTable[key_f2] = 1; }

				if ((keys[SDLK_ESCAPE] == SDL_PRESSED) && (keys[SDLK_RETURN] == SDL_PRESSED)) { 
					m_Flag=GF_MAINUI;
				}
				else if (keys[SDLK_RETURN] == SDL_PRESSED) { KeyTable[key_return] = 1; }
				else if (keys[SDLK_ESCAPE] == SDL_PRESSED) { KeyTable[key_f1] = 1; }
				if (event.type == SDL_QUIT) { MODE = GF_QUIT; }
				break;
		}
	}
	SDL_PauseAudio(1);
	SDL_DestroyMutex(sndlock);
	MODFILE_Free(&mod);
	
	// Free memory
	SDL_FreeSurface(layerbackgrey);
	SDL_FreeSurface(layerback);
	SDL_FreeSurface(layer);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(actualScreen);
	
	// Free memory
	SDL_QuitSubSystem(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK);
	
	exit(0);
}
