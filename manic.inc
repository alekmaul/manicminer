// declaration
// MANIC
void	TitleSetup(void);
void	DoPiano(void);
void	ClearPiano(void);
void	DrawPiano(void);
void	UpdatePianoKeys(void);
void	DoTitleScroll(void);
void	DoPrefs(void);
void	UpdateScrollBuffer(void);
void	FillPixelBuff(void);
void	TitleSetupExtra(void);
void	DrawTPlate2(void);
void	DrawWilly4(BYTE block);
void	DrawScroll(void);
void	LoadSetup(void);
void	LoadAnim(void);
void	SetupPrefs(void);
void	DoPrefsExtra(void);
void	PrefsUpdate(void);
void	PrintSpeed(void);
void	PrintMaps(void);
void	PrintMusic(void);

// core
void	DrawBGBlock(int xpos,int ypos);
void	DrawBlock(int xpos,int ypos,BYTE block, BYTE ink);
void	DrawFinal(void);
void	ClearWillyCol(void);
void	DoEugene(void);
void	DoLevelSeven(void);
void	DoLevelThirteen(void);
void	DoSPG(void);
void	CheckSPG(void);
void	DoKongStood(void);
void	DoKongFall(void);
void	DrawKONG(int xpos,int ypos,BYTE block, BYTE ink);
int	SPGCheckRobo(WORD x, WORD y);
int	GetWillyInput(void);
int	CheckWillyKillBlock(void);
void	CheckWillyFall(void);
void	CheckCrumb(void);
int	CheckWillyConv(void);
void	DoOnConv(int input);
void	DoWillyLeft(void);
void	DoWillyRight(void);
void	DoWillyJump(void);
void	DoWillyFall(void);
void	DoDeath(void);
void	CheckKeys(void);
void	CheckExit(void);
void	CheckSwitches(void);
void	PutWilly(void);
int	GetBlock(WORD x, WORD y);
void	DoConvLeft(int input);
void	DoConvRight(int input);
void	DoWillyLeftConv(void);
void	DoWillyJumpConv(void);
void	DoWillyRightConv(void);

// game
void	GameSetup(void);
void	PlayGame(void);
void	Killed(void);
void	LevelDone(void);
void	GameOver(void);
void	LastExit(void);
void	DrawLevel(void);
void	DoSun(void);
void	PrintScore(void);
void	PrintHighScore(void);
void	DrawLives(void);
void	CheckPause(void);
void	CheckMusic(void);
void	ExtraLife(void);
void	RemoveSun(void);
void	DoCheat(void);
void	CheckCheat(void);
void	LevelDoneExtra(void);
void	OverSetup(void);
void	DoBoot(void);
void	DoOverText(void);
void	DrawWilly2(void);
void	DrawOver(int xpos,int ypos,BYTE block);
void	RotPal(void);
void	GameText1(void);
void	DrawWilly3(int xpos,int ypos,BYTE block);
void	DoExtra1(void);
void	DoExtra2(void);
void	RotPal2(void);
void	ChangeLevelCheat(void);
void	LastFirst(void);
void	LastFade(void);
void	LastClear(void);
void	LastBit(void);
void	DoText(void);
void	FadeUpText(void);
void	PauseText(void);
void	FadeDownText(void);
void	DrawBoot(int xpos,int ypos);
void	DrawSun(void);

// demo
void	DrawDemoLevel(void);

/* 60 Hz */
#define microsec_per_frame (1000/60)
WORD    UpdateFrCt(void)
{
  static int firsttime = 1;
  static int this_frnum;
  static int last_frnum;

  if (firsttime)
    {
      firsttime = 0;
      last_frnum = 0;
    }

  this_frnum = SDL_GetTicks() / microsec_per_frame;
  FrCt += this_frnum - last_frnum;

  last_frnum = this_frnum;

  return(FrCt);
}


///////////////////////////////////////////////////////////////
// Wait Vertical Retrace
///////////////////////////////////////////////////////////////
void WaitVR( void )
{
  WORD	old;
  old=UpdateFrCt();  
  while(old==UpdateFrCt()) {};
}

void WaitVR2( void )
{
  while(NEXTBIT>=UpdateFrCt()) {};
  FrCt=0;
}


///////////////////////////////////////////////////////////////
//	Pressed any key ?
///////////////////////////////////////////////////////////////
int	AnyKey( void )
{
	int	count;

	for( count=0; count<128; count++ )
	{
		if(KeyTable[count] != 0 )
			return(1);
	}
	return(0);
}

///////////////////////////////////////////////////////////////
//	Pressed any key ?
///////////////////////////////////////////////////////////////
void cls( char inColor)
{
	int	count;

	for( count=0; count<256*192; count++ )
	{
		//screen16[count] = RGB15(PALact[inColor*3],PALact[inColor*3+1],PALact[inColor*3+2]);
		XBuf[count] = inColor;
	}
}

///////////////////////////////////////////////////////////////
//	Set palette
///////////////////////////////////////////////////////////////
void PaletteSet( BYTE *pal1 )
{
	int	count;
	//SDL_Color pltTbl[256];

	for (count = 0; count < 3*256; count++) {
		PALact[count] = pal1[count]<<2;
	}
	for (count = 0; count < 256; count++) {
		manic_palette[count] = PIX_TO_RGB(actualScreen->format,PALact[count*3],PALact[count*3+1],PALact[count*3+2]);
	}
}

///////////////////////////////////////////////////////////////
//	Fade Palette
///////////////////////////////////////////////////////////////
int PaletteFade( unsigned char *pal1, unsigned char *pal2 )
{
	int	count,changed;

	changed=0;

	for(count=0;count<768;count++)
	{

		if(*pal1 != *pal2)
		{
			if(*pal1 > *pal2)
			{
				*pal2+=1;
				changed=1;
			}
			else
			{
				*pal2-=1;
				changed=1;
			}
		}

		pal1++;
		pal2++;

	}
	return(changed);
}

///////////////////////////////////////////////////////////////
//	Swap Pages
///////////////////////////////////////////////////////////////
void	SwapPage( void)
{
	page++;	
	page&=1;	
	WaitVR();	
    //if(SDL_MUSTLOCK(video)) SDL_LockSurface(video);
	SDL_ScaleSurface();
    //if (SDL_MUSTLOCK(video)) SDL_UnlockSurface(video);
	//SDL_Flip(video);
}

void	SwapPage2( void)	
{	
	page++;	
	page&=1;	
	WaitVR2();	
    //if(SDL_MUSTLOCK(video)) SDL_LockSurface(video);
	SDL_ScaleSurface();
    //if (SDL_MUSTLOCK(video)) SDL_UnlockSurface(video);
	//SDL_Flip(video);
}	


///////////////////////////////////////////////////////////////
// Get a Pixel from the Screen
///////////////////////////////////////////////////////////////
char GetPixel( int x, int y )
{
//	So there is no fannying about!

	//x+=SCXOFF;
	//y+=SCYOFF;

  //x>>=2;
	//return(XBuf[x+yoff[y]]);
  return(XBuf[x+SYSVID_WIDTH*y]);
}

///////////////////////////////////////////////////////////////
// Plot a Pixel to the Screen
///////////////////////////////////////////////////////////////
void PlotPixel( int x, int y, BYTE colour )
{
	//WORD	palIndex = colour*3;

	//	So there is no fannying about!
	//x+=SCXOFF;
	//y+=SCYOFF;
	//screen16[x+SYSVID_WIDTH*y] = palIndex;
  
	XBuf[x+SYSVID_WIDTH*y] = colour;
}

///////////////////////////////////////////////////////////////
//	Print Text
///////////////////////////////////////////////////////////////
void	FontPrint( int xpos, int ypos, char *text )
{
	int	count,count2,count3;
	int	currentx,currenty;
	int	alpha;
	BYTE	*fonty;

	count=0;

	xpos*=8;
	ypos*=8;

	currentx=xpos;
	currenty=ypos;

	while( *text != 0 )
	{
		alpha=(int)*text;
		text++;

		if(alpha==170)//="|"
		{
			currentx=0;
			currenty+=8;
			alpha=(int)*text;
			text++;
		}


		alpha-=32;

		if(alpha>96)
			alpha-=32;

		alpha*=64;
		count++;
		if(count==33)
			return;

		fonty=(fontb+alpha);

		xpos=currentx;
		ypos=currenty;

		for(count2=0;count2<8;count2++)
		{
			for(count3=0;count3<8;count3++)
			{
				if( (*fonty != 0))
					PlotPixel(xpos,ypos,INK);
				else
					PlotPixel(xpos,ypos,PAPER);

				fonty++;
				xpos++;
			}
			xpos=currentx;
			ypos++;
		}
		currentx+=8;
	}

}
///////////////////////////////////////////////////////////////
//	Print Text
///////////////////////////////////////////////////////////////
void	FontPrint2( int xpos, int ypos, char *text )
{
	int	count,count2,count3;
	int	currentx,currenty;
	int	alpha;
	BYTE	*fonty,*fonty2,data,data2;

	count=0;

	xpos*=8;
	ypos*=8;

	currentx=xpos;
	currenty=ypos;

	while( *text != 0 )
	{
		alpha=(int)*text;
		text++;

		if(alpha==170)//="|"
		{
			currentx=0;
			currenty+=8;
			alpha=(int)*text;
			text++;
		}


		alpha-=32;

		if(alpha>96)
			alpha-=32;

		alpha*=64;
		count++;
		if(count==33)
			return;

		fonty=(fontb+alpha);
		fonty2=(GFXfant+alpha);

		xpos=currentx;
		ypos=currenty;

		for(count2=0;count2<8;count2++)
		{
			for(count3=0;count3<8;count3++)
			{
				if( (*fonty != 0))
					PlotPixel(xpos,ypos,0);
				else
				{
					if(*fonty2==1)
					{
						data=GetPixel(xpos,ypos);
						data2=data&15;
						data2+=3;
						if(data2>15)
							data2=15;
						data&=240;
						data|=data2;
						PlotPixel(xpos,ypos,data);
					}
				}
				fonty++;
				fonty2++;
				xpos++;
			}
			xpos=currentx;
			ypos++;
		}
		currentx+=8;
	}

}
///////////////////////////////////////////////////////////////
//	Show a Long Word
///////////////////////////////////////////////////////////////
void	ShowSix( int xpos, int ypos, unsigned int data )
{
	/*BYTE	convtext[]={"           "};
	BYTE	printtext[]={"      "};
	int	count1,count2;
	BYTE	*pointy;*/
  char	printtext[7];

  sprintf(printtext,"%06d",data);
	/*
  ultoa( data,&convtext,10);

	count2=0;
	for(count1=0;count1<7;count1++)
	{
		if(convtext[count1]!=32)
			count2++;
	}

	pointy=printtext+7;
	pointy-=count2;

	for(count1=0;count1<count2;count1++)
	{
		*pointy=convtext[count1];
		pointy++;
	}


	for(count1=0;count1<6;count1++)
	{
		if(printtext[count1]==32)
			printtext[count1]=48;
	}*/

	FontPrint(xpos,ypos, (char *) &printtext);
}
///////////////////////////////////////////////////////////////
//	Print Text Small
///////////////////////////////////////////////////////////////
void	FontPrintSmall( int xpos, int ypos, char *text )
{
	int	count,count2,count3;
	int	currentx,currenty;
	int	alpha;
	BYTE	*fonty;

	count=0;

	xpos*=4;
	ypos*=6;

	currentx=xpos;
	currenty=ypos;

	while( *text != 0 )
	{
		alpha=(int)*text;
		text++;

		if(alpha==170)//="ª"
		{
			currentx=0;
			currenty+=8;
			alpha=(int)*text;
			text++;
		}

		if(alpha==96)//="`"
		{
			INK=(*text)-96;
			text++;
			alpha=(int)*text;
			text++;
		}

		alpha-=32;

		if(alpha>64)
			alpha-=32;

		alpha*=64;

		fonty=(fonts+alpha);

		xpos=currentx;
		ypos=currenty;

		for(count2=0;count2<6;count2++)
		{
			for(count3=0;count3<4;count3++)
			{
				if( (*fonty != 0))
					PlotPixel(xpos,ypos,INK);
				else
					PlotPixel(xpos,ypos,PAPER);

				fonty++;
				xpos++;
			}
			fonty+=4;
			xpos=currentx;
			ypos++;
		}
		currentx+=4;
	}

}

///////////////////////////////////////////////////////////////
//	Save Stuff on Exit
///////////////////////////////////////////////////////////////
#ifndef O_BINARY 
#define O_BINARY 0
#endif

void	SaveInfo(void)
{
	int	file;

	SDL_PauseAudio(1);

	file=open(current_conf_app, O_CREAT | O_RDWR | O_BINARY | O_TRUNC, S_IREAD | S_IWRITE);
	
	write(file, &GameConf, sizeof(GameConf)); 

	write(file, &HISCORE, sizeof(unsigned int));
	write(file, &SPEED, sizeof(BYTE));
	write(file, &TONKS, sizeof(int));
	write(file, &MUSICtype, sizeof(BYTE));
	close( file );
  
	SDL_PauseAudio(0);
}
///////////////////////////////////////////////////////////////
//	Load Stuff at Start
///////////////////////////////////////////////////////////////
void	LoadInfo(void)
{
	int	file;

	file=open(current_conf_app, O_RDONLY | O_BINARY);
	if(file<0)
	{
		GameConf.sndLevel=40;
		GameConf.m_ScreenRatio=1; // 0 = original show, 1 = full screen
		GameConf.m_DisplayFPS=0;
		GameConf.m_Scanline=0;

		HISCORE=0;
		SPEED=2;
		TONKS=0;
		MUSICtype=0;
	}
  else {
	read(file, &GameConf, sizeof(GameConf));

    read(file, &HISCORE, sizeof(unsigned int) );
    read(file, &SPEED, sizeof(BYTE) );
    read(file, &TONKS, sizeof(int) );
    read(file, &MUSICtype, sizeof(BYTE) );
    close( file );
  }  
}


///////////////////////////////////////////////////////////////
//	Main Code Includes
///////////////////////////////////////////////////////////////
#include	"mm-core.inc"
#include	"mm-game.inc"
#include	"mm-demo.inc"

///////////////////////////////////////////////////////////////
//	Titles
///////////////////////////////////////////////////////////////
void	Titles(void)
{
	switch(TITLEm)
	{
		case	0:
			TitleSetup();
			break;
		case	1:
			DoPiano();
			break;
		case	2:
			SDL_PauseAudio(1);
			ClearPiano();
			break;
		case	3:
			DoTitleScroll();
			break;
		case	4:
			DoPrefs();
			break;

	}
}
///////////////////////////////////////////////////////////////
//	Do Background Fill 1
///////////////////////////////////////////////////////////////
void	Fill1(void)
{
	int	x,y,block2;
	BYTE	data;

	block2=0;

	for(y=0;y<24;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXfill[block2];
			PlotPixel(152+x,40+y,data);
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Background Fill 2
///////////////////////////////////////////////////////////////
void	Fill2(void)
{
	int	x,y,block2;
	BYTE	data;

	block2=384;

	for(y=0;y<24;y++)
	{
		for(x=0;x<72;x++)
		{
			data=GFXfill[block2];
			PlotPixel(176+x,40+y,data);
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Setup Tiltes
///////////////////////////////////////////////////////////////
void	TitleSetup(void)
{
	int	i;

	for(i=0;i<768;i++)
	{
		PALover[i]=PALmain[i];
	}

	PIANOc=0;
	for(i=0;i<32;i++)
		PIANOkhit[i]=0;

	TITLEwf=2;
	TITLEwp=0;
	SCROLLpos=0;
	PIXELoff=0;

	UpdateScrollBuffer();
	FillPixelBuff();

	TITLEm=1;

	musicLoadXM(TITLE_XMSize,TITLE_XM);
	
	TitleSetupExtra();	
	SwapPage();	
	PaletteSet(PALmain);	
	TitleSetupExtra();	
	SwapPage();	
}
///////////////////////////////////////////////////////////////
//	Setup Extra Bits
///////////////////////////////////////////////////////////////
void	TitleSetupExtra(void)
{
	int	i;

	cls(240);

	PAPER=0;
	for(i=0;i<24;i++)
	{
		FontPrint(0,i,"                                ");
	}
	DrawFinal();

	SUNm=1;
	SUNy=32;
	SUNh=16;
	DoSun();

	Fill1();
	Fill2();

	DrawPiano();
	DrawWilly4(TITLEwf);

	DrawTPlate2();
	DrawAirBG();

}
///////////////////////////////////////////////////////////////
//	Draw Piano
///////////////////////////////////////////////////////////////
void	DrawPiano(void)
{
	int	x,y,block2;
	BYTE	data;

	block2=0;

	for(y=0;y<64;y++)
	{
		for(x=0;x<256;x++)
		{
			data=GFXpiano[block2];
			PlotPixel(x,64+y,data);
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw Level Title Plate
///////////////////////////////////////////////////////////////
void	DrawTPlate2(void)
{
	int	x,y;
	//BYTE	data;

	for(y=0;y<8;y++)
	{
		for(x=0;x<256;x++)
		{
			PlotPixel(x,128+y,GFXtplate[(y*256)+x]);
		}
	}
	FontPrint2(7,16,"(c)1997 Andy Noble");
  INK=244;
  FontPrint( 0,18,"OpenDingux port (c)2013 Alekmaul");
}
///////////////////////////////////////////////////////////////
//	Play The Piano
///////////////////////////////////////////////////////////////
void	DoPiano(void)
{
	int	i;//,j;
	//BYTE	key1,key2,key3,key4;
	//MIDASplayStatus	stat;

	for(i=0;i<32;i++)
		PIANOkhit[i]=0;


  //MIDASgetPlayStatus(modon,&stat);

	//if(stat.pattern==14)
  if (MODFILE_getplaystatus(&mod) > 14) 
	{
		TITLEm=2;
		SDL_PauseAudio(1);
	}

	UpdatePianoKeys();
	SwapPage();

	if(KeyTable[key_f1]==1)
	{
		TITLEm=4;
		PREFSm=0;
		SDL_PauseAudio(1);
	}

	if( KeyTable[key_return]==1 )
	{

		TITLEm=0;
		DEMOm=0;
		MODE=GF_GAME;
		SDL_PauseAudio(1);
	}
/*
	if(KeyTable[key_esc]==1)
	{
		MODE=GF_QUIT;
		SDL_PauseAudio(1);
		SaveInfo();
	}
*/
}

///////////////////////////////////////////////////////////////
//	Draw Piano Key
///////////////////////////////////////////////////////////////
void	DrawKey(int xpos,int ypos,BYTE block)
{
	int	x,y,block2;
	BYTE	data;

	xpos*=8;
	ypos*=8;

	block2=(WORD)block;
	block2*=128;

	for(y=0;y<16;y++)
	{
		for(x=0;x<8;x++)
		{
			data=GFXpkeys[block2];
			PlotPixel(xpos+x,ypos+y,data);
			block2++;
		}
	}

}
///////////////////////////////////////////////////////////////
//	Hit Piano Keys
///////////////////////////////////////////////////////////////
DWORD	HitPianoKeys(void)
{
# define KEYS4(A,B,C,D) (1<<(A) | 1<<(B) | 1<<(C) | 1<<(D))
# define KEYS3(A,B,C)   (1<<(A) | 1<<(B) | 1<<(C))
# define KEYS2(A,B)     (1<<(A) | 1<<(B))
# define KEYS1(A)       (1<<(A))

	static const DWORD keyhit[] ={
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(19,19),
		KEYS2(19,19),
		KEYS2(21,21),
		KEYS2(21,21),
		KEYS3(21,21,3),
		KEYS3(21,21,3),
		KEYS2(14,19),
		KEYS2(14,19),
		KEYS4(26,28,14,19),
		KEYS4(26,28,14,19),
		KEYS3(26,28,0),
		KEYS3(26,28,0),
		KEYS2(14,19),
		KEYS2(14,19),
		KEYS4(24,26,14,19),
		KEYS4(24,26,14,19),
		KEYS3(24,26,3),
		KEYS3(24,26,3),
		0,
		0,
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(19,19),
		KEYS2(19,19),
		KEYS2(21,21),
		KEYS2(21,21),
		KEYS3(21,21,0),
		KEYS3(21,21,0),
		KEYS2(14,16),
		KEYS2(14,16),
		KEYS4(25,28,14,16),
		KEYS4(25,28,14,16),
		KEYS3(25,28,4),
		KEYS3(25,28,4),
		KEYS2(14,16),
		KEYS2(14,16),
		KEYS4(23,27,14,16),
		KEYS4(23,27,14,16),
		KEYS3(23,27,0),
		KEYS3(23,27,0),
		0,
		0,
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(20,20),
		KEYS2(20,20),
		KEYS2(22,22),
		KEYS2(22,22),
		KEYS3(22,22,0),
		KEYS3(22,22,0),
		KEYS2(14,16),
		KEYS2(14,16),
		KEYS4(27,29,14,16),
		KEYS4(27,29,14,16),
		KEYS3(27,29,4),
		KEYS3(27,29,4),
		KEYS2(14,16),
		KEYS2(14,16),
		KEYS4(25,27,14,16),
		KEYS4(25,27,14,16),
		KEYS3(25,27,0),
		KEYS3(25,27,0),
		0,
		0,
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(20,20),
		KEYS2(20,20),
		KEYS2(22,22),
		KEYS2(22,22),
		KEYS3(22,22,3),
		KEYS3(22,22,3),
		KEYS2(14,17),
		KEYS2(14,17),
		KEYS4(26,29,14,17),
		KEYS4(26,29,14,17),
		KEYS3(26,29,0),
		KEYS3(26,29,0),
		KEYS2(14,17),
		KEYS2(14,17),
		KEYS4(24,26,14,17),
		KEYS4(24,26,14,17),
		KEYS3(24,26,3),
		KEYS3(24,26,3),
		0,
		0,
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(19,19),
		KEYS2(19,19),
		KEYS2(21,21),
		KEYS2(21,21),
		KEYS3(24,24,3),
		KEYS3(24,24,3),
		KEYS2(14,19),
		KEYS2(14,19),
		KEYS4(28,31,14,19),
		KEYS4(28,31,14,19),
		KEYS3(28,31,0),
		KEYS3(28,31,0),
		KEYS2(14,19),
		KEYS2(14,19),
		KEYS4(26,28,14,19),
		KEYS4(26,28,14,19),
		KEYS3(26,28,3),
		KEYS3(26,28,3),
		0,
		0,
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(17,17),
		KEYS2(19,19),
		KEYS2(19,19),
		KEYS2(21,21),
		KEYS2(21,21),
		KEYS3(24,24,6),
		KEYS3(24,24,6),
		KEYS2(15,17),
		KEYS2(15,17),
		KEYS4(29,31,15,17),
		KEYS4(29,31,15,17),
		KEYS3(29,31,10),
		KEYS3(29,31,10),
		KEYS2(15,17),
		KEYS2(15,17),
		KEYS4(27,29,15,17),
		KEYS4(27,29,15,17),
		KEYS3(27,29,6),
		KEYS3(27,29,6),
		0,
		0,
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(18,18),
		KEYS2(20,20),
		KEYS2(20,20),
		KEYS2(22,22),
		KEYS2(22,22),
		KEYS3(22,22,0),
		KEYS3(22,22,0),
		KEYS4(22,22,14,16),
		KEYS4(22,22,14,16),
		KEYS4(22,22,14,16),
		KEYS4(22,22,14,16),
		KEYS3(22,22,4),
		KEYS3(21,21,4),
		KEYS4(20,20,14,16),
		KEYS4(20,20,14,16),
		KEYS4(21,21,14,16),
		KEYS4(21,21,14,16),
		KEYS4(26,26,3,16),
		KEYS4(26,26,3,16),
		KEYS4(26,26,14,17),
		KEYS4(26,26,14,17),
		KEYS4(26,26,14,17),
		KEYS4(26,26,14,17),
		KEYS3(26,26,0),
		KEYS3(26,26,0),
		KEYS4(24,22,14,17),
		KEYS4(24,22,14,17),
		KEYS4(22,20,14,17),
		KEYS4(22,20,14,17),
		KEYS3(20,18,15),
		KEYS3(20,18,15),
		KEYS2(20,18),
		KEYS2(20,18),
		KEYS2(19,17),
		KEYS2(19,17),
		KEYS4(22,20,0,16),
		KEYS4(22,20,0,16),
		KEYS2(22,20),
		KEYS2(22,20),
		KEYS2(21,19),
		KEYS2(21,19),
		KEYS4(17,14,3,12),
		KEYS2(17,14),
		KEYS2(17,14),
		KEYS3(17,14,3),
		KEYS3(17,14,3),
		KEYS3(17,14,3),
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	unsigned int position = MODFILE_getofsstatus(&mod) + 64 * MODFILE_getplaystatus(&mod) -11*64 -57;
	if (MODFILE_getplaystatus(&mod) == 10)
		position += 57;
	return position < (sizeof(keyhit) / sizeof(unsigned int)) ?
	       keyhit[position] : 0;
}

///////////////////////////////////////////////////////////////
//	Update Piano Keys
///////////////////////////////////////////////////////////////
void	UpdatePianoKeys(void)
{
	int	i;
	DWORD	newkhit = HitPianoKeys();
  
	for(i=0;i<32;i++)
	{
		//if(PIANOkhit[i]==1)
    if (!(newkhit & 1 << i))
		{
			DrawKey(i,14,PIANOkey[i]+4);
		}
		else
		{
			DrawKey(i,14,PIANOkey[i]);
		}
	}
}
///////////////////////////////////////////////////////////////
//	Clear Piano
///////////////////////////////////////////////////////////////
void	ClearPiano(void)
{
	int	i;

	for(i=0;i<32;i++)
		PIANOkhit[i]=0;

	UpdatePianoKeys();
	SwapPage();
	UpdatePianoKeys();
	SwapPage();

	TITLEm=3;
	SCROLLpos=0;
}
///////////////////////////////////////////////////////////////
//	Draw Willy
///////////////////////////////////////////////////////////////
void	DrawWilly4(BYTE block)
{
	int	x,y,block2;
	BYTE	data;

	block2=(WORD)block;
	block2*=256;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXwilly[block2];

			if(data)
			{
					PlotPixel(232+x,72+y,data);
			}
			else
			{
					PlotPixel(232+x,72+y,39);
			}
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Title Scroll
///////////////////////////////////////////////////////////////
void	DoTitleScroll(void)
{
	SwapPage();

	TITLEwp++;
	if(TITLEwp==16)
	{
		TITLEwp=0;
		TITLEwf+=2;
		TITLEwf&=7;
	}
	DrawWilly4(TITLEwf+4);

	DrawScroll();

	PIXELoff++;
	if(PIXELoff==8)
	{
		PIXELoff=0;
		SCROLLpos++;
		if(SCROLLpos==290)
		{
			TITLEm=0;
			DEMOm=0;
			MODE=GF_DEMO;
			if(MUSICtype==0)
				musicLoadXM(INGAME_XMSize, INGAME_XM);
			else
				musicLoadXM(ORIGINAL_XMSize, ORIGINAL_XM);
		}
		else
		{
			UpdateScrollBuffer();
			FillPixelBuff();
		}
	}

	if(KeyTable[key_f1]==1)
	{
		TITLEm=4;
		PREFSm=0;
	}

	if( KeyTable[key_return]==1 )
	{

		TITLEm=0;
		DEMOm=0;
		MODE=GF_GAME;
	}
}
///////////////////////////////////////////////////////////////
//	Update Scroll Buffer
///////////////////////////////////////////////////////////////
void	UpdateScrollBuffer(void)
{
	int	i;

	for(i=0;i<33;i++)
	{
		SCROLLbuff[i]=SCROLLtext[SCROLLpos+i];
	}
}
///////////////////////////////////////////////////////////////
//	Fill Pixel buffer with text
///////////////////////////////////////////////////////////////
void	FillPixelBuff(void)
{
	int	i,x,y,dx,dy;
	WORD	alpha;
	//WORD	point;
	BYTE	*font,*alias,data,data2;

	dx=0;dy=0;

	for(i=0;i<33;i++)
	{
		alpha=(WORD)SCROLLbuff[i];
		alpha-=32;
		alpha*=64;

		font=(fontb+alpha);
		alias=(GFXfant+alpha);

		for(y=0;y<8;y++)
		{
			for(x=0;x<8;x++)
			{
				data=*font;
				if(data!=0)
					PIXELbuff[((dy+y)*264)+(dx+x)]=102;
				else
					PIXELbuff[((dy+y)*264)+(dx+x)]=PAPER;

				data2=*alias;
				if(data2!=0)
					PIXELbuff[((dy+y)*264)+(dx+x)]=107;

				font++;
				alias++;

			}
		}
		dx+=8;
	}
}
///////////////////////////////////////////////////////////////
//	Draw Scroll
///////////////////////////////////////////////////////////////
void	DrawScroll(void)
{
	int	x,y;

	for(y=0;y<8;y++)
	{
		for(x=0;x<256;x++)
		{
			PlotPixel(x,152+y,PIXELbuff[(y*264)+(PIXELoff+x)]);
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Loading Screen
///////////////////////////////////////////////////////////////
void	DoLoading(void) {
	switch(LOADm) {
		case	0:
			LoadSetup();
			break;
		case	1:
			LoadAnim();
			break;
	}
}

///////////////////////////////////////////////////////////////
//	Setup Loading Screen
///////////////////////////////////////////////////////////////
void	LoadSetup(void) {
	int x,y;
	BYTE	data;
	static int whichPage=0;

	cls(0);
	
	switch (whichPage) {
		case 0:
			for(y=0;y<8;y++) {
				for(x=0;x<32;x++) {
					data=GFXload[(y*32)+x];
					PAPER=data;
					FontPrint(x,9+y," ");
				}
			}
			whichPage=1;
			break;
		case 1:
			for(y=0;y<8;y++) {
				for(x=0;x<32;x++) {
					data=GFXload[256+((y*32)+x)];
					PAPER=data;
					FontPrint(x,9+y," ");
				}
			}
			whichPage=0;
			break;
	}
	PAPER=0;
	INK=124;
	FontPrint(27,23,VERSION);
	SwapPage();

	LOADm=1;
}

///////////////////////////////////////////////////////////////
//	Animate Loading Screen
///////////////////////////////////////////////////////////////
void	LoadAnim(void) {
	LOADp++;
	if(LOADp==60) {
		LOADp=0;
		//SwapPage();
		LOADm=0;
	}
	else {
		WaitVR();
	}

	if(AnyKey()==1) {
		MODE=GF_TITLES;
	}
}

///////////////////////////////////////////////////////////////
//	Preferences Screen
///////////////////////////////////////////////////////////////
void	DoPrefs(void)
{
	switch(PREFSm)
	{
		case	0:
			SetupPrefs();
			break;
		case	1:
			PrefsUpdate();
			break;
	}
}
///////////////////////////////////////////////////////////////
//	Setup Prefs
///////////////////////////////////////////////////////////////
void	SetupPrefs(void)
{
	int	count;

	for(count=0;count<768;count++)
	{
		PALover[count]=PALmain[count];
	}

	DoPrefsExtra();
	SwapPage();

	PaletteSet(PALover);
	DoPrefsExtra();

	PREFSh1=0;
	PREFSh2=0;
	PREFSh3=0;
	PREFSm=1;

	musicLoadXM(OPTIONS_XMSize, OPTIONS_XM);
}
///////////////////////////////////////////////////////////////
//	Prefs Screen Setup
///////////////////////////////////////////////////////////////
void	DoPrefsExtra(void)
{
	int	x,y,i;

	i=240;

	cls(0);

	for(x=0;x<32;x++)
	{
		PAPER=i;
		FontPrint(x,0," ");
		i++;
		if(i>254)
			i=240;
	}

	for(y=1;y<24;y++)
	{
		PAPER=i;
		FontPrint(31,y," ");
		i++;
		if(i>254)
			i=240;
	}

	for(x=1;x<32;x++)
	{
		PAPER=i;
		FontPrint(31-x,23," ");
		i++;
		if(i>254)
			i=240;
	}

	for(y=1;y<23;y++)
	{
		PAPER=i;
		FontPrint(0,23-y," ");
		i++;
		if(i>254)
			i=240;
	}


	PAPER=0;
	INK=7;

	FontPrintSmall(24,2, "`fManic Miner PC");

	FontPrintSmall(23,3, "`g(C)`e1997 `gAndy Noble");
	FontPrintSmall(10,4, "`gBased on an original game by `eMatthew Smith`g.");
	FontPrintSmall(7,5,  "`g(C) `e1983 `fBUG-BYTE`g Ltd. And `fSoftware Projects`g Ltd.");
	FontPrintSmall(18,6,  "`g(C) `e1997 `fAlchemist Research`g.");

	FontPrintSmall(7,8, "`dProgramming`g, `dGraphics`e...............`fAndy Noble`e.");
	FontPrintSmall(7,9, "`dMUSIC ARRANGED BY`e.................`fMatt Simmonds`e.");
	FontPrintSmall(7,10,"`dExtra Levels`e.................`fLee `d'`gBLOOD!`d' `fTonks`e.");
	FontPrintSmall(7,11,"`dTesting and Ideas`e.................`fEwan Christie`e.");
	FontPrintSmall(2,12, "`dOpenDingux version by `fAlekmaul`d (2013) (www.portabledev.com)");

	FontPrintSmall(3,14, "`dI would just like to say ThankYou to the following people");

	FontPrintSmall(3,15, "`fSahara Surfers`d..............`eFor MIDAS Digital Audio System");
	FontPrintSmall(3,16, "`fCharles Scheffold and Thomas Pytel`d.....`eFor the fab PMODE/W");
	FontPrintSmall(3,17, "`fTyrone L. Cartwright`d............`eFor help with the bad guys");

	FontPrintSmall(3,19, "`fDavid H. Tolley`d.................`eFor the constant slaggings");
	FontPrintSmall(3,20, "`fGerton Lunter`d........................`eFor the excellent Z80");
	FontPrintSmall(3,21, "`fJames McKay`d.................`eFor the equally excellent X128");

	FontPrintSmall(5,22, "`cEverybody who e-mailed me with words of encouragement.");

	FontPrintSmall(13,24,"`fAnd all the Guys on COMP.SYS.SINCLAIR");
	FontPrintSmall(4,25, "`eWho keep me informed and amused about all things Speccy.");

	FontPrintSmall(15,27,"`f    F2          F3          F4");
	FontPrintSmall(15,28,"`bGame Speed    Levels      Melody");
	FontPrintSmall(15,29,"`c ORIGINAL    ORIGINAL    ORIGINAL");

	PrintSpeed();
	PrintMaps();
	PrintMusic();

}
///////////////////////////////////////////////////////////////
//	Update setup screen
///////////////////////////////////////////////////////////////
void	PrefsUpdate(void)
{
	RotPal();
	SwapPage();
	PaletteSet(PALover);

	if(PREFSh1==1)
	{
		if(KeyTable[key_f2]!=1)
		{
			SPEED++;
			if(SPEED==5)
				SPEED=0;
		}
		PREFSh1=0;
	}

	if(KeyTable[key_f2]==1)
	{
		PREFSh1=1;
	}

	if(PREFSh2==1)
	{
		if(KeyTable[key_f3]!=1)
		{
			TONKS++;
			TONKS&=1;
		}
		PREFSh2=0;
	}

	if(KeyTable[key_f3]==1)
	{
		PREFSh2=1;
	}

	if(PREFSh3==1)
	{
		if(KeyTable[key_f4]!=1)
		{
			MUSICtype++;
			MUSICtype&=1;
		}
		PREFSh3=0;
	}

	if(KeyTable[key_f4]==1)
	{
		PREFSh3=1;
	}

	if(KeyTable[key_esc]==1)
	{
		MODE=0;
		TITLEm=0;
		SDL_PauseAudio(1);
	}

	PrintSpeed();
	PrintMaps();
	PrintMusic();

}

///////////////////////////////////////////////////////////////
//	Display Game Speed
///////////////////////////////////////////////////////////////
void	PrintSpeed(void)
{
	switch(SPEED)
	{
		case	0:
			INK=1;
			FontPrintSmall(16,29," SILLY! ");
			break;
		case	1:
			INK=3;
			FontPrintSmall(16,29,"  HARD  ");
			break;
		case	2:
			INK=4;
			FontPrintSmall(16,29,"  1997  ");
			break;
		case	3:
			INK=7;
			FontPrintSmall(16,29,"ORIGINAL");
			break;
		case	4:
			INK=5;
			FontPrintSmall(16,29," BORING ");
			break;
	}
}
///////////////////////////////////////////////////////////////
//	Display Game Maps
///////////////////////////////////////////////////////////////
void	PrintMaps(void)
{
	switch(TONKS)
	{
		case	0:
			INK=7;
			FontPrintSmall(28,29,"ORIGINAL");
			break;
		case	1:
			INK=4;
			FontPrintSmall(28,29," BLOOD! ");
			break;
	}
}
///////////////////////////////////////////////////////////////
//	Display Game Music
///////////////////////////////////////////////////////////////
void	PrintMusic(void)
{
	switch(MUSICtype)
	{
		case	0:
			INK=4;
			FontPrintSmall(40,29,"  1997  ");
			break;
		case	1:
			INK=7;
			FontPrintSmall(40,29,"ORIGINAL");
			break;
	}
}
