#include <dirent.h>

#include "shared.h"

#include "./data/manic_background.h"
#include "./data/manic_skin.h"

extern unsigned int m_Flag;

bool gameMenu;

#define COLOR_BG            PIX_TO_RGB(layer->format,05, 03, 02)
#define COLOR_HELP_TEXT		PIX_TO_RGB(layer->format,64, 240, 96)
#define COLOR_OK			PIX_TO_RGB(layer->format,0,0,255)
#define COLOR_KO			PIX_TO_RGB(layer->format,255,0,0)
#define COLOR_INFO			PIX_TO_RGB(layer->format,0,255,0)
#define COLOR_LIGHT			PIX_TO_RGB(layer->format,255,255,0)
#define COLOR_ACTIVE_ITEM   PIX_TO_RGB(layer->format,232, 253, 77)
#define COLOR_INACTIVE_ITEM PIX_TO_RGB(layer->format,67,89,153)

// Font: THIN8X8.pf : Exported from PixelFontEdit 2.7.0
static const unsigned char fontdata8x8[2048] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 000 (.)
	0x7E, 0x81, 0xA5, 0x81, 0xBD, 0x99, 0x81, 0x7E,	// Char 001 (.)
	0x7E, 0xFF, 0xDB, 0xFF, 0xC3, 0xE7, 0xFF, 0x7E,	// Char 002 (.)
	0x6C, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00,	// Char 003 (.)
	0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00,	// Char 004 (.)
	0x38, 0x7C, 0x38, 0xFE, 0xFE, 0x7C, 0x38, 0x7C,	// Char 005 (.)
	0x10, 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x7C,	// Char 006 (.)
	0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00,	// Char 007 (.)
	0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF,	// Char 008 (.)
	0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00,	// Char 009 (.)
	0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF,	// Char 010 (.)
	0x0F, 0x07, 0x0F, 0x7D, 0xCC, 0xCC, 0xCC, 0x78,	// Char 011 (.)
	0x3C, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x18,	// Char 012 (.)
	0x3F, 0x33, 0x3F, 0x30, 0x30, 0x70, 0xF0, 0xE0,	// Char 013 (.)
	0x7F, 0x63, 0x7F, 0x63, 0x63, 0x67, 0xE6, 0xC0,	// Char 014 (.)
	0x99, 0x5A, 0x3C, 0xE7, 0xE7, 0x3C, 0x5A, 0x99,	// Char 015 (.)
	0x80, 0xE0, 0xF8, 0xFE, 0xF8, 0xE0, 0x80, 0x00,	// Char 016 (.)
	0x02, 0x0E, 0x3E, 0xFE, 0x3E, 0x0E, 0x02, 0x00,	// Char 017 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x18, 0x7E, 0x3C, 0x18,	// Char 018 (.)
	0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00,	// Char 019 (.)
	0x7F, 0xDB, 0xDB, 0x7B, 0x1B, 0x1B, 0x1B, 0x00,	// Char 020 (.)
	0x3E, 0x63, 0x38, 0x6C, 0x6C, 0x38, 0xCC, 0x78,	// Char 021 (.)
	0x00, 0x00, 0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x00,	// Char 022 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x7E, 0x3C, 0x18, 0xFF,	// Char 023 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00,	// Char 024 (.)
	0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00,	// Char 025 (.)
	0x00, 0x18, 0x0C, 0xFE, 0x0C, 0x18, 0x00, 0x00,	// Char 026 (.) right arrow
	0x00, 0x30, 0x60, 0xFE, 0x60, 0x30, 0x00, 0x00,	// Char 027 (.)
	0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xFE, 0x00, 0x00,	// Char 028 (.)
	0x00, 0x24, 0x66, 0xFF, 0x66, 0x24, 0x00, 0x00,	// Char 029 (.)
	0x00, 0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x00, 0x00,	// Char 030 (.)
	0x00, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x00,	// Char 031 (.)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 032 ( )
	0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x40, 0x00,	// Char 033 (!)
	0x90, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 034 (")
	0x50, 0x50, 0xF8, 0x50, 0xF8, 0x50, 0x50, 0x00,	// Char 035 (#)
	0x20, 0x78, 0xA0, 0x70, 0x28, 0xF0, 0x20, 0x00,	// Char 036 ($)
	0xC8, 0xC8, 0x10, 0x20, 0x40, 0x98, 0x98, 0x00,	// Char 037 (%)
	0x70, 0x88, 0x50, 0x20, 0x54, 0x88, 0x74, 0x00,	// Char 038 (&)
	0x60, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 039 (')
	0x20, 0x40, 0x80, 0x80, 0x80, 0x40, 0x20, 0x00,	// Char 040 (()
	0x20, 0x10, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00,	// Char 041 ())
	0x00, 0x20, 0xA8, 0x70, 0x70, 0xA8, 0x20, 0x00,	// Char 042 (*)
	0x00, 0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x00,	// Char 043 (+)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x20, 0x40,	// Char 044 (,)
	0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,	// Char 045 (-)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00,	// Char 046 (.)
	0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00,	// Char 047 (/)
	0x70, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x70, 0x00,	// Char 048 (0)
	0x40, 0xC0, 0x40, 0x40, 0x40, 0x40, 0xE0, 0x00,	// Char 049 (1)
	0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0xF8, 0x00,	// Char 050 (2)
	0x70, 0x88, 0x08, 0x10, 0x08, 0x88, 0x70, 0x00,	// Char 051 (3)
	0x08, 0x18, 0x28, 0x48, 0xFC, 0x08, 0x08, 0x00,	// Char 052 (4)
	0xF8, 0x80, 0x80, 0xF0, 0x08, 0x88, 0x70, 0x00,	// Char 053 (5)
	0x20, 0x40, 0x80, 0xF0, 0x88, 0x88, 0x70, 0x00,	// Char 054 (6)
	0xF8, 0x08, 0x10, 0x20, 0x40, 0x40, 0x40, 0x00,	// Char 055 (7)
	0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00,	// Char 056 (8)
	0x70, 0x88, 0x88, 0x78, 0x08, 0x08, 0x70, 0x00,	// Char 057 (9)
	0x00, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00,	// Char 058 (:)
	0x00, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x20,	// Char 059 (;)
	0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10, 0x00,	// Char 060 (<)
	0x00, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0x00, 0x00,	// Char 061 (=)
	0x80, 0x40, 0x20, 0x10, 0x20, 0x40, 0x80, 0x00,	// Char 062 (>)
	0x78, 0x84, 0x04, 0x08, 0x10, 0x00, 0x10, 0x00,	// Char 063 (?)
	0x70, 0x88, 0x88, 0xA8, 0xB8, 0x80, 0x78, 0x00,	// Char 064 (@)
	0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x00,	// Char 065 (A)
	0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0, 0x00,	// Char 066 (B)
	0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00,	// Char 067 (C)
	0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF0, 0x00,	// Char 068 (D)
	0xF8, 0x80, 0x80, 0xE0, 0x80, 0x80, 0xF8, 0x00,	// Char 069 (E)
	0xF8, 0x80, 0x80, 0xE0, 0x80, 0x80, 0x80, 0x00,	// Char 070 (F)
	0x70, 0x88, 0x80, 0x80, 0x98, 0x88, 0x78, 0x00,	// Char 071 (G)
	0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x00,	// Char 072 (H)
	0xE0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, 0x00,	// Char 073 (I)
	0x38, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60, 0x00,	// Char 074 (J)
	0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88, 0x00,	// Char 075 (K)
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xF8, 0x00,	// Char 076 (L)
	0x82, 0xC6, 0xAA, 0x92, 0x82, 0x82, 0x82, 0x00,	// Char 077 (M)
	0x84, 0xC4, 0xA4, 0x94, 0x8C, 0x84, 0x84, 0x00,	// Char 078 (N)
	0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00,	// Char 079 (O)
	0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80, 0x00,	// Char 080 (P)
	0x70, 0x88, 0x88, 0x88, 0xA8, 0x90, 0x68, 0x00,	// Char 081 (Q)
	0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, 0x00,	// Char 082 (R)
	0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x00,	// Char 083 (S)
	0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,	// Char 084 (T)
	0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00,	// Char 085 (U)
	0x88, 0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x00,	// Char 086 (V)
	0x82, 0x82, 0x82, 0x82, 0x92, 0x92, 0x6C, 0x00,	// Char 087 (W)
	0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00,	// Char 088 (X)
	0x88, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x00,	// Char 089 (Y)
	0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, 0x00,	// Char 090 (Z)
	0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0x00,	// Char 091 ([)
	0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00,	// Char 092 (\)
	0xE0, 0x20, 0x20, 0x20, 0x20, 0x20, 0xE0, 0x00,	// Char 093 (])
	0x20, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 094 (^)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00,	// Char 095 (_)
	0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 096 (`)
	0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x74, 0x00,	// Char 097 (a)
	0x80, 0x80, 0xB0, 0xC8, 0x88, 0xC8, 0xB0, 0x00,	// Char 098 (b)
	0x00, 0x00, 0x70, 0x88, 0x80, 0x88, 0x70, 0x00,	// Char 099 (c)
	0x08, 0x08, 0x68, 0x98, 0x88, 0x98, 0x68, 0x00,	// Char 100 (d)
	0x00, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x70, 0x00,	// Char 101 (e)
	0x30, 0x48, 0x40, 0xE0, 0x40, 0x40, 0x40, 0x00,	// Char 102 (f)
	0x00, 0x00, 0x34, 0x48, 0x48, 0x38, 0x08, 0x30,	// Char 103 (g)
	0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x00,	// Char 104 (h)
	0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x70, 0x00,	// Char 105 (i)
	0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x90, 0x60,	// Char 106 (j)
	0x80, 0x80, 0x88, 0x90, 0xA0, 0xD0, 0x88, 0x00,	// Char 107 (k)
	0xC0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, 0x00,	// Char 108 (l)
	0x00, 0x00, 0xEC, 0x92, 0x92, 0x92, 0x92, 0x00,	// Char 109 (m)
	0x00, 0x00, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x00,	// Char 110 (n)
	0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00,	// Char 111 (o)
	0x00, 0x00, 0xB0, 0xC8, 0xC8, 0xB0, 0x80, 0x80,	// Char 112 (p)
	0x00, 0x00, 0x68, 0x98, 0x98, 0x68, 0x08, 0x08,	// Char 113 (q)
	0x00, 0x00, 0xB0, 0xC8, 0x80, 0x80, 0x80, 0x00,	// Char 114 (r)
	0x00, 0x00, 0x78, 0x80, 0x70, 0x08, 0xF0, 0x00,	// Char 115 (s)
	0x40, 0x40, 0xE0, 0x40, 0x40, 0x50, 0x20, 0x00,	// Char 116 (t)
	0x00, 0x00, 0x88, 0x88, 0x88, 0x98, 0x68, 0x00,	// Char 117 (u)
	0x00, 0x00, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00,	// Char 118 (v)
	0x00, 0x00, 0x82, 0x82, 0x92, 0x92, 0x6C, 0x00,	// Char 119 (w)
	0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00,	// Char 120 (x)
	0x00, 0x00, 0x88, 0x88, 0x98, 0x68, 0x08, 0x70,	// Char 121 (y)
	0x00, 0x00, 0xF8, 0x10, 0x20, 0x40, 0xF8, 0x00,	// Char 122 (z)
	0x10, 0x20, 0x20, 0x40, 0x20, 0x20, 0x10, 0x00,	// Char 123 ({)
	0x40, 0x40, 0x40, 0x00, 0x40, 0x40, 0x40, 0x00,	// Char 124 (|)
	0x40, 0x20, 0x20, 0x10, 0x20, 0x20, 0x40, 0x00,	// Char 125 (})
	0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 126 (~)
	0x00, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0x00	// Char 127 (.)
};

//---------------------------------------------------------------------------------------
char szFile[MAX__PATH], szFile1[MAX__PATH];
	

void menuReset(void);
void menuQuit(void);
void menuContinue(void);
void menuFileBrowse(void);
void menuSaveBmp(void);
void menuSaveState(void);
void menuLoadState(void);
void screen_showkeymenu(void);
void menuReturn(void);

//---------------------------------------------------------------------------------------
typedef struct {
	char itemName[16];
	int *itemPar;
	int itemParMaxValue;
	char *itemParName;
	void (*itemOnA)();
} MENUITEM;

typedef struct {
	int itemNum; // number of items
	int itemCur; // current item
	MENUITEM *m; // array of items
} MENU;

char mnuYesNo[2][16] = {"no", "yes"};
char mnuRatio[2][16] = { "Original show","Full screen"};
char mnuLevels[2][16] = { "Original","Blood!"};

MENUITEM MainMenuItems[] = {
	{"Continue", NULL, 0, NULL, &menuContinue},
	{"Reset", NULL, 0, NULL, &menuReset},
	{"Levels: ", (int *) &TONKS, 1,(char *) &mnuLevels, NULL},
	{"Ratio: ", (int *) &GameConf.m_ScreenRatio, 1, (char *) &mnuRatio, NULL},
	{"Scanline: ", (int *) &GameConf.m_Scanline, 1,(char *) &mnuYesNo, NULL},
	{"Take Screenshot", NULL, 0, NULL, &menuSaveBmp},
	{"Load State", NULL, 0, NULL, &menuLoadState},
	{"Save State", NULL, 0, NULL, &menuSaveState},
	{"Exit", NULL, 0, NULL, &menuQuit}
};
MENU mnuMainMenu = { 9, 0, (MENUITEM *) &MainMenuItems };

//----------------------------------------------------------------------------------------------------
// Prints char on a given surface
void screen_showchar32(SDL_Surface *s, int x, int y, unsigned char a, int fg_color, int bg_color) {
	unsigned int *dst;
	int w, h;

	for(h = 8; h; h--) {
		dst = (unsigned int *)s->pixels + (y+8-h)*s->w + x;
		for(w = 8; w; w--) {
			unsigned int color = *dst; // background
			if((fontdata8x8[a*8 + (8-h)] >> w) & 1) color = fg_color;
			*dst++ = color;
		}
	}
}

void screen_showchar(SDL_Surface *s, int x, int y, unsigned char a, int fg_color, int bg_color) {
	unsigned short *dst;
	int w, h;

	for(h = 8; h; h--) {
		dst = (unsigned short *)s->pixels + (y+8-h)*s->w + x;
		for(w = 8; w; w--) {
			unsigned short color = *dst; // background
			if((fontdata8x8[a*8 + (8-h)] >> w) & 1) color = fg_color;
			*dst++ = color;
		}
	}
}

// copy-pasted mostly from gpsp emulator by Exophaze. 	thanks for it
void print_string(const char *s, unsigned short fg_color, unsigned short bg_color, int x, int y) {
	int i, j = strlen(s);
	for(i = 0; i < j; i++, x += 6) screen_showchar(layer, x, y, s[i], fg_color, bg_color);
}

void print_string_video(int x, int y, const char *s) {
	int i, j = strlen(s);
#ifdef _VIDOD32_
	for(i = 0; i < j; i++, x += 8) screen_showchar32(actualScreen, x, y, s[i], ((255<<16)|(0<<8) | 0), 0);
#else
	for(i = 0; i < j; i++, x += 8) screen_showchar(actualScreen, x, y, s[i], PIX_TO_RGB(actualScreen->format, 255, 0, 0), 0);
#endif
}

void screen_showitem(int x, int y, MENUITEM *m, int fg_color) {
	static char i_str[24];

	// if no parameters, show simple menu item
	if(m->itemPar == NULL) print_string(m->itemName, fg_color, COLOR_BG, x, y);
	else {
		if(m->itemParName == NULL) {
			// if parameter is a digit
			sprintf(i_str, "%s%i", m->itemName, *m->itemPar);
		} else {
			// if parameter is a name in array
			sprintf(i_str, "%s%s", m->itemName, m->itemParName+(*m->itemPar)*16);
		}
		print_string(i_str, fg_color, COLOR_BG, x, y);
	}
}

// Shows menu items and pointing arrow
#define SPRX (16)
void screen_showmenu(MENU *menu) {
	int i;
	MENUITEM *mi = menu->m;
	
	// clear buffer
	SDL_BlitSurface(layerbackgrey, 0, layer, 0);

	// show menu lines
	for(i = 0; i < menu->itemNum; i++, mi++) {
		int fg_color;

		if(menu->itemCur == i) fg_color = COLOR_ACTIVE_ITEM; else fg_color = COLOR_INACTIVE_ITEM;
		screen_showitem(SPRX+10, 59+i*15, mi, fg_color);
		if(menu->itemCur == i) print_string("-", fg_color, COLOR_BG, SPRX+10-12, 59+i*15);
	}
}

// draw default emulator design
void screen_prepback(SDL_Surface *s, unsigned char *bmpBuf, unsigned int bmpSize) {
	// load logo, Convert the image to optimal display format and Free the temporary surface
	SDL_RWops *rw = SDL_RWFromMem(bmpBuf, bmpSize);
	SDL_Surface *temp = SDL_LoadBMP_RW(rw, 1);
	SDL_Surface *image;
	image = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	// Display image
 	SDL_BlitSurface(image, 0, s, 0);
	SDL_FreeSurface(image);
}

// draw main emulator design
void screen_prepbackground(void) {
	// draw default background
	screen_prepback(layerbackgrey, MANIC_BACKGROUND, MANIC_BACKGROUND_SIZE);
}

// wait for a key
void screen_waitkey(void) {
	bool akey=false;
		
	while (!akey) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_KEYDOWN)
				akey = true;
		}
	}
}

void screen_waitkeyarelease(void) {
	unsigned char *keys;
		
	// wait key release and go in menu
	while (1) {
		SDL_PollEvent(&event);
		keys = SDL_GetKeyState(NULL);
		if (keys[SDLK_LCTRL] != SDL_PRESSED) break;
	}
}

// flip the layer to screen
void screen_flip(void) {
	SDL_BlitSurface(layer, 0, actualScreen, 0);
	SDL_Flip(actualScreen);
}

// Main function that runs all the stuff
void screen_showmainmenu(MENU *menu) {
	unsigned char *keys;
	MENUITEM *mi;
	unsigned int keya=0, keyb=0, keyup=0, keydown=0, keyleft=0, keyright=0;

	gameMenu=true;

	while(gameMenu) {
		SDL_PollEvent(&event);
		keys = SDL_GetKeyState(NULL);
		
		mi = menu->m + menu->itemCur; // pointer to highlit menu option

		// A - apply parameter or enter submenu
		if (keys[SDLK_LCTRL] == SDL_PRESSED) { 
			if (!keya) {
				keya = 1; 
				screen_waitkeyarelease();
				if (mi->itemOnA != NULL) (*mi->itemOnA)();
			}
		}
		else keya=0;

		// B - exit or back to previous menu
		if (keys[SDLK_LALT] == SDL_PRESSED) { 
			if (!keyb) {
				keyb = 1; if (menu != &mnuMainMenu) gameMenu = false;
			}
		}
		else keyb=0;

		// UP - arrow up
		if (keys[SDLK_UP] == SDL_PRESSED) { 
			if (!keyup) {
				keyup = 1; if(--menu->itemCur < 0) menu->itemCur = menu->itemNum - 1;
			}
			else {
				keyup++; if (keyup>12) keyup=0;
			}
		}
		else keyup=0;

		//DOWN - arrow down
		if (keys[SDLK_DOWN] == SDL_PRESSED) { 
			if (!keydown) {
				keydown = 1; if(++menu->itemCur == menu->itemNum) menu->itemCur = 0;
			}
			else {
				keydown++; if (keydown>12) keydown=0;
			}
		}
		else keydown=0;

		// LEFT - decrease parameter value
		if (keys[SDLK_LEFT] == SDL_PRESSED) { 
			if (!keyleft) {
				keyleft = 1; if(mi->itemPar != NULL && *mi->itemPar > 0) *mi->itemPar -= 1;
			}
			else {
				keyleft++; if (keyleft>12) keyleft=0;
			}
		}
		else keyleft=0;

		// RIGHT - increase parameter value
		if (keys[SDLK_RIGHT] == SDL_PRESSED) { 
			if (!keyright) {
				keyright = 1; if(mi->itemPar != NULL && *mi->itemPar < mi->itemParMaxValue) *mi->itemPar += 1;
			}
			else {
				keyright++; if (keyright>12) keyright=0;
			}
		}
		else keyright=0;

		if (gameMenu) {
			screen_showmenu(menu); // show menu items
			if (menu == &mnuMainMenu) {
				print_string("V1.0", COLOR_LIGHT,COLOR_BG, 294,29);
			}
		}
		SDL_Delay(16);
		screen_flip();
	}
}

// Menu function that runs main top menu
void screen_showtopmenu(void) {
	// Save screen in layer
	SDL_BlitSurface(actualScreen, 0, layerback, 0);
	screen_prepbackground();

	// Display and manage main menu
	screen_showmainmenu(&mnuMainMenu);

	// save actual config
	SaveInfo();

	// if no ratio, put skin
	if (!GameConf.m_ScreenRatio) {
		screen_prepback(actualScreen, MANIC_SKIN, MANIC_SKIN_SIZE);
		SDL_Flip(actualScreen);
		screen_prepback(actualScreen, MANIC_SKIN, MANIC_SKIN_SIZE);
		SDL_Flip(actualScreen);
	}
}

//----------------------------------------------------------------------
// find a filename for bmp or state saving 
void findNextFilename(char *szFileFormat, char *szFilename) {
	uint32_t uBcl;
	int fp;
  
	for (uBcl = 0; uBcl<999; uBcl++) {
		sprintf(szFilename,szFileFormat,uBcl);
		fp = open(szFilename,O_RDONLY | O_BINARY);
		if (fp <0) break;
		close(fp);
	}
	if (uBcl == 1000)
		strcpy(szFilename,"NOSLOT");
	if (fp>=0) close(fp);
}

// Reset current game
void menuReset(void) {
	SCORE = 0;
	EXTRA = 0;
	LOADm=0;
	page = 0;
	FrCt = 0;
	MODE = GF_LOADING;
	GAMEm=0;
	DEMOm=0;
	TITLEm = 0;
	OVERm=0;
	INK=7;
	PAPER=0;
	gameMenu=false;
	m_Flag = GF_GAMERUNNING;
}

// Quit oswan emulator (oh noooo :P)
void menuQuit(void) {
	gameMenu=false;
	m_Flag = GF_GAMEQUIT;
}

// Return to game if loaded
void menuContinue(void) {
	gameMenu=false;
	m_Flag = GF_GAMERUNNING;
}

// Take a screenshot of current game
void menuSaveBmp(void) {
	sprintf(szFile,"%s//manicminer.xxx",current_conf_app);

	szFile[strlen(szFile)-8] = '%';
	szFile[strlen(szFile)-7] = '0';
	szFile[strlen(szFile)-6] = '3';
	szFile[strlen(szFile)-5] = 'd';
	szFile[strlen(szFile)-4] = '.';
	szFile[strlen(szFile)-3] = 'b';
	szFile[strlen(szFile)-2] = 'm';
	szFile[strlen(szFile)-1] = 'p';

	print_string("Saving...", COLOR_OK, COLOR_BG, 8,240-5 -10*3);
	screen_flip();
	findNextFilename(szFile,szFile1);
	SDL_SaveBMP(layerback, szFile1);
	print_string("Screen saved !", COLOR_OK, COLOR_BG, 8+10*8,240-5 -10*3);
	screen_flip();
	screen_waitkey();
}

void menuSaveState(void) {
	int	file;

	SDL_PauseAudio(1);

	sprintf(szFile,"%s//manicminer.sta",current_conf_app);

	print_string("Saving state ...", COLOR_OK, COLOR_BG, 8,240-5 -10*3);
	screen_flip();

	file=open(szFile, O_CREAT | O_RDWR | O_BINARY | O_TRUNC, S_IREAD | S_IWRITE);

	write(file, &SCORE, sizeof(DWORD));
	write(file, &EXTRA, sizeof(DWORD));
	write(file, &MODE, sizeof(BYTE));
	write(file, &LOADm, sizeof(BYTE));
	write(file, &GAMEm, sizeof(BYTE));
	write(file, &DEMOm, sizeof(BYTE));
	write(file, &TITLEm, sizeof(BYTE));
	write(file, &OVERm, sizeof(BYTE));
	write(file, &INK, sizeof(BYTE));
	write(file, &PAPER, sizeof(BYTE));
	write(file, &TONKS,sizeof(int));
	write(file, PALact, sizeof(PALact));
	write(file, cMAP, sizeof(cMAP));
	write(file, cCRUMB, sizeof(cCRUMB));
	write(file, cTITLE, sizeof(cTITLE));
	write(file, &cBGink, sizeof(BYTE));
	write(file, &cBGpaper, sizeof(BYTE));
	write(file, &cPLAT1ink, sizeof(BYTE));
	write(file, &cPLAT1paper, sizeof(BYTE));
	write(file, &cPLAT2ink, sizeof(BYTE));
	write(file, &cPLAT2paper, sizeof(BYTE));
	write(file, &cWALLink, sizeof(BYTE));
	write(file, &cWALLpaper, sizeof(BYTE));
	write(file, &cCRUMBink, sizeof(BYTE));
	write(file, &cCRUMBpaper, sizeof(BYTE));
	write(file, &cKILL1ink, sizeof(BYTE));
	write(file, &cKILL1paper, sizeof(BYTE));
	write(file, &cKILL2ink, sizeof(BYTE));
	write(file, &cKILL2paper, sizeof(BYTE));
	write(file, &cCONVink, sizeof(BYTE));
	write(file, &cCONVpaper, sizeof(BYTE));
	write(file, &cBORDER, sizeof(BYTE));
	write(file, &cPLAT1gfx, sizeof(BYTE));
	write(file, &cPLAT2gfx, sizeof(BYTE));
	write(file, &cWALLgfx, sizeof(BYTE));
	write(file, &cCRUMBgfx, sizeof(BYTE));
	write(file, &cKILL1gfx, sizeof(BYTE));
	write(file, &cKILL2gfx, sizeof(BYTE));
	write(file, &cCONVgfx, sizeof(BYTE));
	write(file, &cEXITgfx, sizeof(BYTE));
	write(file, &cKEYgfx, sizeof(BYTE));
	write(file, &cWILLYx,sizeof(WORD));
	write(file, &cWILLYy,sizeof(WORD));
	write(file, cWILLYxold, sizeof(cWILLYxold));
	write(file, cWILLYyold, sizeof(cWILLYyold));
	write(file, &cWILLYf,sizeof(WORD));
	write(file, &cWILLYd, sizeof(BYTE));
	write(file, &cWILLYm, sizeof(BYTE));
	write(file, &cWILLYj, sizeof(BYTE));
	write(file, cWILLYbuff, sizeof(cWILLYbuff));
	write(file, &cWILLYfall,sizeof(WORD));
	write(file, &cWILLYjs,sizeof(WORD));
	write(file, cWILLYcol,sizeof(cWILLYcol));
	write(file, &cCONVx,sizeof(WORD));
	write(file, &cCONVy,sizeof(WORD));
	write(file, &cCONVd, sizeof(BYTE));
	write(file, &cCONVl, sizeof(BYTE));
	write(file, &cCONVf, sizeof(BYTE));
	write(file, &cCONVm, sizeof(BYTE));
	write(file, &cCONV1, sizeof(BYTE));
	write(file, cKEYx,sizeof(cKEYx));
	write(file, cKEYy,sizeof(cKEYy));
	write(file, cKEYb,sizeof(cKEYb));
	write(file, cKEYs,sizeof(cKEYs));
	write(file, cSWITCHx,sizeof(cSWITCHx));
	write(file, cSWITCHy,sizeof(cSWITCHy));
	write(file, cSWITCHs,sizeof(cSWITCHs));
	write(file, &cEXITx,sizeof(WORD));
	write(file, &cEXITy,sizeof(WORD));
	write(file, &cEXITb, sizeof(BYTE));
	write(file, &cEXITm, sizeof(BYTE));
	write(file, &cAIR, sizeof(BYTE));
	write(file, &cAIRp, sizeof(BYTE));
	write(file, cHROBOink,sizeof(cHROBOink));
	write(file, cHROBOpaper,sizeof(cHROBOpaper));
	write(file, cHROBOx,sizeof(cHROBOx));
	write(file, cHROBOy,sizeof(cHROBOy));
	write(file, cHROBOmin,sizeof(cHROBOmin));
	write(file, cHROBOmax,sizeof(cHROBOmax));
	write(file, cHROBOd,sizeof(cHROBOd));
	write(file, cHROBOs,sizeof(cHROBOs));
	write(file, cHROBOgfx,sizeof(cHROBOgfx));
	write(file, cHROBOflip,sizeof(cHROBOflip));
	write(file, cHROBOanim,sizeof(cHROBOanim));
	write(file, cHROBOxold,sizeof(cHROBOxold));
	write(file, cHROBOyold,sizeof(cHROBOyold));
	write(file, cVROBOink,sizeof(cVROBOink));
	write(file, cVROBOpaper,sizeof(cVROBOpaper));
	write(file, cVROBOx,sizeof(cVROBOx));
	write(file, cVROBOy,sizeof(cVROBOy));
	write(file, cVROBOmin,sizeof(cVROBOmin));
	write(file, cVROBOmax,sizeof(cVROBOmax));
	write(file, cVROBOd,sizeof(cVROBOd));
	write(file, cVROBOs,sizeof(cVROBOs));
	write(file, cVROBOgfx,sizeof(cVROBOgfx));
	write(file, cVROBOanim,sizeof(cVROBOanim));
	write(file, cVROBOxold,sizeof(cVROBOxold));
	write(file, cVROBOyold,sizeof(cVROBOyold));
	write(file, &EUGENEx,sizeof(WORD));
	write(file, &EUGENEy,sizeof(WORD));
	write(file, &EUGENEmin,sizeof(WORD));
	write(file, &EUGENEmax,sizeof(WORD));
	write(file, &EUGENEd, sizeof(BYTE));
	write(file, &EUGENEm, sizeof(BYTE));
	write(file, &EUGENEc, sizeof(BYTE));
	write(file, EUGENExold, sizeof(EUGENExold));
	write(file, EUGENEyold, sizeof(EUGENEyold));
	write(file, &SWITCH1m, sizeof(BYTE));
	write(file, &SWITCH2m, sizeof(BYTE));
	write(file, &HOLEy,sizeof(WORD));
	write(file, &HOLEl, sizeof(BYTE));
	write(file, &KONGx,sizeof(WORD));
	write(file, &KONGy,sizeof(WORD));
	write(file, KONGxold,sizeof(KONGxold));
	write(file, KONGyold,sizeof(KONGyold));
	write(file, &KONGmax,sizeof(WORD));
	write(file, &KONGm, sizeof(BYTE));
	write(file, &KONGc, sizeof(BYTE));
	write(file, &KONGf, sizeof(BYTE));
	write(file, &KONGp, sizeof(BYTE));
	write(file, SKYx,sizeof(SKYx));
	write(file, SKYy,sizeof(SKYy));
	write(file, SKYmax,sizeof(SKYmax));
	write(file, SKYxold,sizeof(SKYxold));
	write(file, SKYyold,sizeof(SKYyold));
	write(file, SKYs,sizeof(SKYs));
	write(file, SKYf,sizeof(SKYf));
	write(file, SKYm,sizeof(SKYm));
	write(file, SKYc,sizeof(SKYc));
	write(file, SKYp,sizeof(SKYp));
	write(file, &DEATHm, sizeof(BYTE));
	write(file, &DEATHc,sizeof(WORD));
	write(file, &BOOTy,sizeof(WORD));
	write(file, &SUNy,sizeof(WORD));
	write(file, &SUNm, sizeof(BYTE));
	write(file, &SUNh, sizeof(BYTE));
	write(file, SUNbuff, sizeof(SUNbuff));
	write(file, SUNyold, sizeof(SUNyold));
	write(file, SUNhold, sizeof(SUNhold));
	write(file, SPGx, sizeof(SPGx));
	write(file, SPGy, sizeof(SPGy));
	write(file, &HISCORE,sizeof(DWORD));
	write(file, &EXTRAm, sizeof(BYTE));
	write(file, &EXTRAc, sizeof(BYTE));
	write(file, &LIVES,sizeof(WORD));
	write(file, &LIVESf, sizeof(BYTE));
	write(file, &LIVESp, sizeof(BYTE));
	write(file, &LEVEL, sizeof(BYTE));
	write(file, &MUSICon, sizeof(BYTE));
	write(file, &old, sizeof(BYTE));
	write(file, &SPEED, sizeof(BYTE));
	write(file, &DEMOp, sizeof(BYTE));
	write(file, &TITLEwf, sizeof(BYTE));
	write(file, &TITLEwp, sizeof(BYTE));
	write(file, &OVERink, sizeof(BYTE));
	write(file, &OVERp, sizeof(BYTE));
	write(file, &CHEAT, sizeof(BYTE));
	write(file, &CHEATp, sizeof(BYTE));
	write(file, &CHEATh, sizeof(BYTE));
	write(file, &LOADp, sizeof(DWORD));
	write(file, &PREFSm, sizeof(BYTE));
	write(file, &PREFSh1, sizeof(BYTE));
	write(file, &PREFSh2, sizeof(BYTE));
	write(file, &PREFSh3, sizeof(BYTE));

	close( file );
  
	print_string("State saved !", COLOR_OK, COLOR_BG, 8+10*8,240-5 -10*3);
	screen_flip();
	screen_waitkey();

	SDL_PauseAudio(0);
};

void menuLoadState(void) {
	int	file;

	SDL_PauseAudio(1);

	sprintf(szFile,"%s//manicminer.sta",current_conf_app);

	print_string("Loading state ...", COLOR_OK, COLOR_BG, 8,240-5 -10*3);
	screen_flip();

	file=open(szFile, O_RDONLY | O_BINARY);
	if(file<0) {
		print_string("Can't load state !", COLOR_KO, COLOR_BG, 8+10*8,240-5 -10*3);
	}
	else {
		read(file, &SCORE, sizeof(DWORD));
		read(file, &EXTRA, sizeof(DWORD));
		read(file, &MODE, sizeof(BYTE));
		read(file, &LOADm, sizeof(BYTE));
		read(file, &GAMEm, sizeof(BYTE));
		read(file, &DEMOm, sizeof(BYTE));
		read(file, &TITLEm, sizeof(BYTE));
		read(file, &OVERm, sizeof(BYTE));
		read(file, &INK, sizeof(BYTE));
		read(file, &PAPER, sizeof(BYTE));
		read(file, &TONKS,sizeof(int));
		read(file, PALact, sizeof(PALact));
		read(file, cMAP, sizeof(cMAP));
		read(file, cCRUMB, sizeof(cCRUMB));
		read(file, cTITLE, sizeof(cTITLE));
		read(file, &cBGink, sizeof(BYTE));
		read(file, &cBGpaper, sizeof(BYTE));
		read(file, &cPLAT1ink, sizeof(BYTE));
		read(file, &cPLAT1paper, sizeof(BYTE));
		read(file, &cPLAT2ink, sizeof(BYTE));
		read(file, &cPLAT2paper, sizeof(BYTE));
		read(file, &cWALLink, sizeof(BYTE));
		read(file, &cWALLpaper, sizeof(BYTE));
		read(file, &cCRUMBink, sizeof(BYTE));
		read(file, &cCRUMBpaper, sizeof(BYTE));
		read(file, &cKILL1ink, sizeof(BYTE));
		read(file, &cKILL1paper, sizeof(BYTE));
		read(file, &cKILL2ink, sizeof(BYTE));
		read(file, &cKILL2paper, sizeof(BYTE));
		read(file, &cCONVink, sizeof(BYTE));
		read(file, &cCONVpaper, sizeof(BYTE));
		read(file, &cBORDER, sizeof(BYTE));
		read(file, &cPLAT1gfx, sizeof(BYTE));
		read(file, &cPLAT2gfx, sizeof(BYTE));
		read(file, &cWALLgfx, sizeof(BYTE));
		read(file, &cCRUMBgfx, sizeof(BYTE));
		read(file, &cKILL1gfx, sizeof(BYTE));
		read(file, &cKILL2gfx, sizeof(BYTE));
		read(file, &cCONVgfx, sizeof(BYTE));
		read(file, &cEXITgfx, sizeof(BYTE));
		read(file, &cKEYgfx, sizeof(BYTE));
		read(file, &cWILLYx,sizeof(WORD));
		read(file, &cWILLYy,sizeof(WORD));
		read(file, cWILLYxold, sizeof(cWILLYxold));
		read(file, cWILLYyold, sizeof(cWILLYyold));
		read(file, &cWILLYf,sizeof(WORD));
		read(file, &cWILLYd, sizeof(BYTE));
		read(file, &cWILLYm, sizeof(BYTE));
		read(file, &cWILLYj, sizeof(BYTE));
		read(file, cWILLYbuff, sizeof(cWILLYbuff));
		read(file, &cWILLYfall,sizeof(WORD));
		read(file, &cWILLYjs,sizeof(WORD));
		read(file, cWILLYcol,sizeof(cWILLYcol));
		read(file, &cCONVx,sizeof(WORD));
		read(file, &cCONVy,sizeof(WORD));
		read(file, &cCONVd, sizeof(BYTE));
		read(file, &cCONVl, sizeof(BYTE));
		read(file, &cCONVf, sizeof(BYTE));
		read(file, &cCONVm, sizeof(BYTE));
		read(file, &cCONV1, sizeof(BYTE));
		read(file, cKEYx,sizeof(cKEYx));
		read(file, cKEYy,sizeof(cKEYy));
		read(file, cKEYb,sizeof(cKEYb));
		read(file, cKEYs,sizeof(cKEYs));
		read(file, cSWITCHx,sizeof(cSWITCHx));
		read(file, cSWITCHy,sizeof(cSWITCHy));
		read(file, cSWITCHs,sizeof(cSWITCHs));
		read(file, &cEXITx,sizeof(WORD));
		read(file, &cEXITy,sizeof(WORD));
		read(file, &cEXITb, sizeof(BYTE));
		read(file, &cEXITm, sizeof(BYTE));
		read(file, &cAIR, sizeof(BYTE));
		read(file, &cAIRp, sizeof(BYTE));
		read(file, cHROBOink,sizeof(cHROBOink));
		read(file, cHROBOpaper,sizeof(cHROBOpaper));
		read(file, cHROBOx,sizeof(cHROBOx));
		read(file, cHROBOy,sizeof(cHROBOy));
		read(file, cHROBOmin,sizeof(cHROBOmin));
		read(file, cHROBOmax,sizeof(cHROBOmax));
		read(file, cHROBOd,sizeof(cHROBOd));
		read(file, cHROBOs,sizeof(cHROBOs));
		read(file, cHROBOgfx,sizeof(cHROBOgfx));
		read(file, cHROBOflip,sizeof(cHROBOflip));
		read(file, cHROBOanim,sizeof(cHROBOanim));
		read(file, cHROBOxold,sizeof(cHROBOxold));
		read(file, cHROBOyold,sizeof(cHROBOyold));
		read(file, cVROBOink,sizeof(cVROBOink));
		read(file, cVROBOpaper,sizeof(cVROBOpaper));
		read(file, cVROBOx,sizeof(cVROBOx));
		read(file, cVROBOy,sizeof(cVROBOy));
		read(file, cVROBOmin,sizeof(cVROBOmin));
		read(file, cVROBOmax,sizeof(cVROBOmax));
		read(file, cVROBOd,sizeof(cVROBOd));
		read(file, cVROBOs,sizeof(cVROBOs));
		read(file, cVROBOgfx,sizeof(cVROBOgfx));
		read(file, cVROBOanim,sizeof(cVROBOanim));
		read(file, cVROBOxold,sizeof(cVROBOxold));
		read(file, cVROBOyold,sizeof(cVROBOyold));
		read(file, &EUGENEx,sizeof(WORD));
		read(file, &EUGENEy,sizeof(WORD));
		read(file, &EUGENEmin,sizeof(WORD));
		read(file, &EUGENEmax,sizeof(WORD));
		read(file, &EUGENEd, sizeof(BYTE));
		read(file, &EUGENEm, sizeof(BYTE));
		read(file, &EUGENEc, sizeof(BYTE));
		read(file, EUGENExold, sizeof(EUGENExold));
		read(file, EUGENEyold, sizeof(EUGENEyold));
		read(file, &SWITCH1m, sizeof(BYTE));
		read(file, &SWITCH2m, sizeof(BYTE));
		read(file, &HOLEy,sizeof(WORD));
		read(file, &HOLEl, sizeof(BYTE));
		read(file, &KONGx,sizeof(WORD));
		read(file, &KONGy,sizeof(WORD));
		read(file, KONGxold,sizeof(KONGxold));
		read(file, KONGyold,sizeof(KONGyold));
		read(file, &KONGmax,sizeof(WORD));
		read(file, &KONGm, sizeof(BYTE));
		read(file, &KONGc, sizeof(BYTE));
		read(file, &KONGf, sizeof(BYTE));
		read(file, &KONGp, sizeof(BYTE));
		read(file, SKYx,sizeof(SKYx));
		read(file, SKYy,sizeof(SKYy));
		read(file, SKYmax,sizeof(SKYmax));
		read(file, SKYxold,sizeof(SKYxold));
		read(file, SKYyold,sizeof(SKYyold));
		read(file, SKYs,sizeof(SKYs));
		read(file, SKYf,sizeof(SKYf));
		read(file, SKYm,sizeof(SKYm));
		read(file, SKYc,sizeof(SKYc));
		read(file, SKYp,sizeof(SKYp));
		read(file, &DEATHm, sizeof(BYTE));
		read(file, &DEATHc,sizeof(WORD));
		read(file, &BOOTy,sizeof(WORD));
		read(file, &SUNy,sizeof(WORD));
		read(file, &SUNm, sizeof(BYTE));
		read(file, &SUNh, sizeof(BYTE));
		read(file, SUNbuff, sizeof(SUNbuff));
		read(file, SUNyold, sizeof(SUNyold));
		read(file, SUNhold, sizeof(SUNhold));
		read(file, SPGx, sizeof(SPGx));
		read(file, SPGy, sizeof(SPGy));
		read(file, &HISCORE,sizeof(DWORD));
		read(file, &EXTRAm, sizeof(BYTE));
		read(file, &EXTRAc, sizeof(BYTE));
		read(file, &LIVES,sizeof(WORD));
		read(file, &LIVESf, sizeof(BYTE));
		read(file, &LIVESp, sizeof(BYTE));
		read(file, &LEVEL, sizeof(BYTE));
		read(file, &MUSICon, sizeof(BYTE));
		read(file, &old, sizeof(BYTE));
		read(file, &SPEED, sizeof(BYTE));
		read(file, &DEMOp, sizeof(BYTE));
		read(file, &TITLEwf, sizeof(BYTE));
		read(file, &TITLEwp, sizeof(BYTE));
		read(file, &OVERink, sizeof(BYTE));
		read(file, &OVERp, sizeof(BYTE));
		read(file, &CHEAT, sizeof(BYTE));
		read(file, &CHEATp, sizeof(BYTE));
		read(file, &CHEATh, sizeof(BYTE));
		read(file, &LOADp, sizeof(DWORD));
		read(file, &PREFSm, sizeof(BYTE));
		read(file, &PREFSh1, sizeof(BYTE));
		read(file, &PREFSh2, sizeof(BYTE));
		read(file, &PREFSh3, sizeof(BYTE));

		print_string("State loaded !", COLOR_OK, COLOR_BG, 8+10*8,240-5 -10*3);
		close( file );

		gameMenu=false;
		m_Flag = GF_GAMERUNNING;
	}

	screen_flip();
	screen_waitkey();

	SDL_PauseAudio(0);
};

void gethomedir(char *dir, char* name) {
#ifdef _OPENDINGUX_
	strcpy(dir, getenv("HOME"));
	if (strlen(dir) == 0) {
		getcwd(dir, 256);
	}
	sprintf(dir,"%s//.%s//",dir, name);
	mkdir(dir,S_IRWXU | S_IRWXG | S_IRWXO); // create $HOME/.config/program if it doesn't exist
#else
	getcwd(dir, 256);
#endif
}
