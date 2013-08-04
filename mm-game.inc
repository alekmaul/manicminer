///////////////////////////////////////////////////////////////
//	Game Stuff
///////////////////////////////////////////////////////////////
void	DoGame(void)
{
	switch(GAMEm)
	{
		case	0://SETUP
			GameSetup();
			break;
		case	1://PLAYING
			PlayGame();
			break;
		case	2://DEATH
			Killed();
			break;
		case	3://NEW LEVEL
			LevelDone();
			break;
		case	4://GAME OVER
			GameOver();
			break;
		case	5://LAST EXIT
			LastExit();
			break;
	}


//	if( KeyTable[key_f12]==1 )
//	{
//		GAMEm=5;
//		LASTm=0;
//		LASTc=0;
//		LASTp=0;
//		TEXTm=0;
//		TEXTink=7;
//		TEXTfade=0;
//	}

}
///////////////////////////////////////////////////////////////
//	Game Fisrt Setup
///////////////////////////////////////////////////////////////
void	GameSetup(void)
{
	int	count;

	for(count=0;count<768;count++)
	{
		PALwhite[count]=63;
		PALblack[count]=0;
		PALfade[count]=PALmain[count];
		PALover[count]=PALmain[count];
	}

	if(TONKS==0)
		LEVEL=0;
	else
		LEVEL=20;

	SCORE=0;
	LIVES=3;

	LIVESf=0;
	LIVESp=0;

	EXTRA=10000;
	//EXTRAdelta=10000;
	EXTRAm=0;
	EXTRAc=0;

	CopyLevelInfo();
	DrawLevel();
	SwapPage();
	DrawLevel();
	PaletteSet(PALmain);

	GAMEm=1;
	OVERm=0;

	CHEATp=0;
	CHEATh=0;

	//MUSICh=0;

	PAUSE=0;

	if(MUSICtype==0)
	{
		if((LEVEL==19)||(LEVEL==39))
			musicLoadXM(FINAL_XMSize, FINAL_XM);
		else
			musicLoadXM(INGAME_XMSize, INGAME_XM);
	}
	else
	{
		musicLoadXM(ORIGINAL_XMSize, ORIGINAL_XM);
	}
}
///////////////////////////////////////////////////////////////
//	Draw Level
///////////////////////////////////////////////////////////////
void	DrawLevel(void)
{
	DrawCurrentLevel();
	DrawConv();
	DrawKeys();
	DrawSwitches();
	DrawExit();
	DrawTPlate();
	DrawAirBG();
	DoWilly();
	DoHRobo();
	DoVRobo();
	DoSpecialRobo();
	DrawExit();
	DrawAir();

	FontPrint(0,18,"                                ");
	FontPrint(0,19,"                                ");
	FontPrint(0,20,"                                ");
	FontPrint(0,21,"                                ");
	FontPrint(0,22,"                                ");
	FontPrint(0,23,"                                ");

	PrintScore();
	PrintHighScore();
	DrawLives();

	NEXTBIT=0;
}
///////////////////////////////////////////////////////////////
//	Play Game
///////////////////////////////////////////////////////////////
void	PlayGame(void)
{
	//int	speed;

	CheckPause();
	CheckMusic();

	//MIDASsetMusicVolume(modon,VOL);

	if(PAUSE==0)
	{
		SwapPage2();
		NEXTBIT=FrCt+SPEED;

		ExtraLife();

		RemoveSun();
		RemoveWilly();
		RemoveSPG();
		RemoveSky();
		RemoveKong();
		RemoveVRobo();
		RemoveHRobo();
		RemoveEugene();

		ClearWillyCol();

		DrawKeys();
		DrawConv();

		DrawSwitches();
		DoCrumb();

		DoHRobo();
		DoVRobo();
		DoSpecialRobo();

		DoWilly();

		DrawExit();
		DrawAir();
		DoSun();

		DrawLives();

		PrintScore();


	}
	else
	{
		WaitVR();
	}

	if(KeyTable[key_esc]==1)
	{
		MODE=0;
		TITLEm=0;
		GAMEm=0;
		SDL_PauseAudio(1);
	}

	if(CHEAT==1)
	{
		DoCheat();
	}
	else
	{
		CheckCheat();
	}

	if((KeyTable[key_f1]==1)&&(KeyTable[key_ctrl]==1))
		SPEED=0;

	if((KeyTable[key_f2]==1)&&(KeyTable[key_ctrl]==1))
		SPEED=1;

	if((KeyTable[key_f3]==1)&&(KeyTable[key_ctrl]==1))
		SPEED=2;

	if((KeyTable[key_f4]==1)&&(KeyTable[key_ctrl]==1))
		SPEED=3;

	if((KeyTable[key_f5]==1)&&(KeyTable[key_ctrl]==1))
		SPEED=4;

}
///////////////////////////////////////////////////////////////
//	Willy Killed
///////////////////////////////////////////////////////////////
void	Killed(void)
{
	int	i;

	WaitVR();

	if(DEATHm==0)
	{
		DEATHc++;
		if(DEATHc==8)
		{
			DEATHm=1;
			LIVES--;
			if(LIVES==0)
			{
				GAMEm=4;
			}

		}
		else
		{
			for(i=0;i<8;i++)
				PaletteFade(PALblack,PALfade);

			PaletteSet(PALfade);

		}
	}
	else
	{
		CopyLevelInfo();
		DrawLevel();
		SwapPage();
		PaletteSet(PALmain);
		DrawLevel();

		GAMEm=1;

		if(MUSICtype==0)
 	  {
		if((LEVEL==19)||(LEVEL==39))
			musicLoadXM(FINAL_XMSize, FINAL_XM);
		else
			musicLoadXM(INGAME_XMSize, INGAME_XM);
	  }
		else
		{
			musicLoadXM(ORIGINAL_XMSize, ORIGINAL_XM);
		}
	}
}
///////////////////////////////////////////////////////////////
//	Level Done
///////////////////////////////////////////////////////////////
void	LevelDone(void)
{
	int	i;

	SDL_PauseAudio(1);

	cEXITm=0;

	LevelDoneExtra();
	SwapPage();
	LevelDoneExtra();

	for(i=0;i<8;i++)
	{
		PaletteSet(PALwhite);
		SwapPage();WaitVR();
		PaletteSet(PALmain);
		SwapPage();WaitVR();
	}

	do
	{
		SwapPage();
		sfxLoadWAV(JUMP_WAVSize,JUMP_WAV, 6000+(cAIR*((old+1)*100)));
		//MIDASplaySample(wav,6,255,6000+(cAIR*((old+1)*100)),64,MIDAS_PAN_MIDDLE);
		//MIDASplaySample(wav,7,255,4000+(cAIR*((old+1)*100)),64,MIDAS_PAN_MIDDLE);
		DrawAir();
		cAIR--;
		SCORE+=9;
		PrintScore();
	}
	while(cAIR>32);

	LEVEL++;
	if(LEVEL==20)
	{
		LEVEL=0;
	}

	if(LEVEL==40)
	{
		LEVEL=20;
	}

	WaitVR();
	CopyLevelInfo();
	DrawLevel();
	SwapPage();
	DrawLevel();

	GAMEm=1;

	if(MUSICtype==0)
	{
		if((LEVEL==19)||(LEVEL==39))
			musicLoadXM(FINAL_XMSize, FINAL_XM);
		else
			musicLoadXM(INGAME_XMSize, INGAME_XM);
	}
	else
	{
		musicLoadXM(ORIGINAL_XMSize, ORIGINAL_XM);
	}
}

///////////////////////////////////////////////////////////////
//	Redraw Stuff for Double Buffer
///////////////////////////////////////////////////////////////
void	LevelDoneExtra(void)
{
	int	i,count;
	BYTE	temp;

	RemoveWilly();
	RemoveSPG();
	RemoveSky();
	RemoveKong();
	RemoveVRobo();
	RemoveHRobo();
	RemoveEugene();
	RemoveSun();

	if(cCONVy!=0)
	{

		for(count=0;count<cCONVl;count++)
		{
			DrawConvBlock(cCONVx+(count*8),cCONVy,cCONVgfx,cCONVf);
		}
	}

	for(i=0;i<4;i++)
	{
		if(cHROBOx[i]!=65535)
		{
			if( cHROBOd[i] )
			{
				DrawHRobo((cHROBOx[i]&248),cHROBOy[i],(cHROBOgfx[i]+((cHROBOx[i]&cHROBOanim[i])>>1))+cHROBOflip[i],cHROBOink[i]);
			}
			else
			{
				DrawHRobo((cHROBOx[i]&248),cHROBOy[i],cHROBOgfx[i]+((cHROBOx[i]&cHROBOanim[i])>>1),cHROBOink[i]);
			}

		}
	}

	for(i=0;i<4;i++)
	{
		if(cVROBOx[i]!=65535)
		{
			DrawVROBO((cVROBOx[i]&248),cVROBOy[i],cVROBOgfx[i]+((cVROBOx[i]&cVROBOanim[i])>>1),cVROBOink[i]);
		}
	}


	if(LEVEL==4)
	{
		DrawEUGENE(EUGENEx,EUGENEy,EUGENEc);
	}

	if((LEVEL==7)||(LEVEL==11))
	{
		DrawKONG(KONGx,KONGy,KONGf,KONGc);
	}

	if(LEVEL==13)
	{
		for(i=0;i<3;i++)
		{
			DrawSky(SKYx[i],SKYy[i],SKYf[i],SKYc[i]);
		}
	}

	if(LEVEL==18)
	{
		for(i=0;i<64;i++)
		{
			if(SPGx[old][i]!=65535)
			{
				DrawSPGBlock(SPGx[old][i],SPGy[old][i]);
			}
		}
	}

	for(i=0;i<5;i++)
	{
		if(cKEYs[i]==1)
		{
			if((cKEYx[i]!=65535)&&(cKEYy[i]!=65535))
			{
				DrawKeyBlock(cKEYx[i],cKEYy[i],cKEYgfx,bright2[cKEYb[i]]);
			}
		}
	}


	PutWilly();
	DrawExit();
	DoSun();

	temp=MUSICon;
	MUSICon=0;
	DrawLives();
	MUSICon=temp;
}
///////////////////////////////////////////////////////////////
//	Game Over
///////////////////////////////////////////////////////////////
void	GameOver(void)
{
	switch(OVERm)
	{
		case	0:
			OverSetup();
			break;
		case	1:
			DoBoot();
			break;
		case	2:
			DoOverText();
			break;

	}
}
///////////////////////////////////////////////////////////////
//	Draw Game Over Screen
///////////////////////////////////////////////////////////////
void	OverSetup(void)
{
	int	i;//,x,y;

	BOOTy=0;

	cls(0);
  
	PAPER=254;
	for(i=0;i<16;i++)
		FontPrint(0,i,"                                ");

	DrawWilly2();

	DrawOver(120,112,0);
	DrawOver(120,BOOTy,1);

	DrawTPlate();
	DrawAirBG();

	PrintScore();
	PrintHighScore();

	SwapPage();

	cls(0);

	PAPER=254;
	for(i=0;i<16;i++)
		FontPrint(0,i,"                                ");

	DrawWilly2();

	DrawOver(120,112,0);
	DrawOver(120,BOOTy,1);

	DrawTPlate();
	DrawAirBG();

	PrintScore();
	PrintHighScore();

	OVERm=1;
	OVERp=0;

	PAPER=0;
}
///////////////////////////////////////////////////////////////
//	Draw GAME OVER Gfx
///////////////////////////////////////////////////////////////
void	DrawOver(int xpos,int ypos,BYTE block)
{
	int	x,y,block2;
	BYTE	data;

	block2=(WORD)block;
	block2*=256;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXover[block2];

			if(data)
			{
				PlotPixel(xpos+x,ypos+y,data);
			}
			else
			{
				PlotPixel(xpos+x,ypos+y,254);
			}
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Boot
///////////////////////////////////////////////////////////////
void	DoBoot(void)
{
	int	i;

	DrawOver(120,BOOTy,1);
	sfxLoadWAV(JUMP_WAVSize, JUMP_WAV,4000+((BOOTy*BOOTy)*(old+1)));
	//MIDASplaySample(wav,6,255,4000+((BOOTy*BOOTy)*(old+1)),64,MIDAS_PAN_MIDDLE);

	BOOTy++;
	if(BOOTy>96)
	{
		OVERm=2;
		OVERink=1;

		for(i=0;i<48;i++)
		{
			PALover[720+i]=0;
		}

	}
	RotPal();

	SwapPage();
	PaletteSet(PALover);

	if(BOOTy>96)
		DrawOver(120,96,1);


}
///////////////////////////////////////////////////////////////
//	Rotate end of palette
///////////////////////////////////////////////////////////////
void	RotPal(void)
{
	BYTE	temp1,temp2,temp3;
	int	i;

	temp1=PALover[720];
	temp2=PALover[721];
	temp3=PALover[722];

	for(i=0;i<42;i++)
	{
		PALover[720+i]=PALover[723+i];
	}

	PALover[762]=temp1;
	PALover[763]=temp2;
	PALover[764]=temp3;
}
///////////////////////////////////////////////////////////////
//	Draw Willy
///////////////////////////////////////////////////////////////
void	DrawWilly2(void)
{
	int	x,y,block2;
	BYTE	data;

	block2=2;
	block2*=256;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXwilly[block2];

			if(data)
			{
				PlotPixel(120+x,96+y,data);
			}
			else
			{
				PlotPixel(120+x,96+y,254);
			}

			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Over Text
///////////////////////////////////////////////////////////////
void	DoOverText(void)
{
	GameText1();
	SwapPage();

	OVERp++;
	if(OVERp>200)
	{
		MODE=0;
		TITLEm=0;
		DEMOm=0;
		GAMEm=0;
		OVERm=0;

		if(SCORE>HISCORE)
		{
			HISCORE=SCORE;
		}
	}


}
///////////////////////////////////////////////////////////////
//	Game Over Text
///////////////////////////////////////////////////////////////
void	GameText1(void)
{

	INK=OVERink;
	FontPrint(10,6,"G");
	OVERink++;
	OVERink&=7;
	INK=OVERink;
	FontPrint(11,6,"a");
	OVERink++;
	OVERink&=7;
	INK=OVERink;
	FontPrint(12,6,"m");
	OVERink++;
	OVERink&=7;
	INK=OVERink;
	FontPrint(13,6,"e");

	OVERink++;
	OVERink&=7;
	INK=OVERink;
	FontPrint(18,6,"O");
	OVERink++;
	OVERink&=7;
	INK=OVERink;
	FontPrint(19,6,"v");
	OVERink++;
	OVERink&=7;
	INK=OVERink;
	FontPrint(20,6,"e");
	OVERink++;
	OVERink&=7;
	INK=OVERink;
	FontPrint(21,6,"r");

}
///////////////////////////////////////////////////////////////
//	Draw Lives
///////////////////////////////////////////////////////////////
void	DrawLives(void)
{
	int	i;
	BYTE	l;

	l=LIVES;
	if(l>8)
		l=8;

	for(i=0;i<(l-1);i++)
	{
		DrawWilly3(i*16,168,LIVESf);
	}

	if(CHEAT==1)
		DrawBoot(i*16,168);


	if(MUSICon==1)
	{
		LIVESp++;
		if(LIVESp>3)
		{
			LIVESp=0;

			LIVESf++;
			LIVESf&=3;
		}
	}
}

///////////////////////////////////////////////////////////////
//	Draw Willy
///////////////////////////////////////////////////////////////
void	DrawWilly3(int xpos,int ypos,BYTE block)
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
					PlotPixel(xpos+x,ypos+y,data);
			}
			else
			{
					PlotPixel(xpos+x,ypos+y,0);
			}
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw GAME OVER Gfx
///////////////////////////////////////////////////////////////
void	DrawBoot(int xpos,int ypos)
{
	int	x,y,block2;
	BYTE	data;

	block2=1;
	block2*=256;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXover[block2];

			if(data)
			{
				PlotPixel(xpos+x,ypos+y,data);
			}

			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Print Score
///////////////////////////////////////////////////////////////
void	PrintScore(void)
{
	INK=6;
	PAPER=0;
	FontPrint(20,19,"Score");
	ShowSix(26,19,SCORE);

	if(SCORE>=EXTRA)
	{
		LIVES++;
		EXTRA+=EXTRAdelta;

		EXTRAc=0;
		EXTRAm=1;
	}


}

///////////////////////////////////////////////////////////////
//	Print High Score
///////////////////////////////////////////////////////////////
void	PrintHighScore(void)
{
	INK=6;
	PAPER=0;
	FontPrint(0,19,"High Score");
	ShowSix(11,19,HISCORE);

}
///////////////////////////////////////////////////////////////
//	Do Extra Life Gained
///////////////////////////////////////////////////////////////
void	ExtraLife(void)
{
	switch(EXTRAm)
	{
		case	1:
			DoExtra1();
			break;
		case	2:
			DoExtra2();
			break;
	}
}
///////////////////////////////////////////////////////////////
//	Do Extra Life
///////////////////////////////////////////////////////////////
void	DoExtra1(void)
{
	RotPal2();
	PaletteSet(PALfade);

	EXTRAc++;
	if(EXTRAc==13)
	{
		EXTRAc=0;
		EXTRAm=2;
	}
}
///////////////////////////////////////////////////////////////
//	Do Extra Life
///////////////////////////////////////////////////////////////
void	DoExtra2(void)
{
	int	count;

	for(count=0;count<768;count++)
	{
		PALfade[count]=PALmain[count];
	}

	EXTRAc=0;
	EXTRAm=0;
	PaletteSet(PALmain);
}
///////////////////////////////////////////////////////////////
//	Rotate end of palette
///////////////////////////////////////////////////////////////
void	RotPal2(void)
{
	BYTE	temp[(16*3)];
	int	i;

	for(i=0;i<(16*3);i++)
	{
		temp[i]=PALfade[(16*3)+i];
	}

	for(i=0;i<672;i++)
	{
		PALfade[(16*3)+i]=PALfade[(32*3)+i];
	}

	for(i=0;i<(16*3);i++)
	{
		PALfade[672+i]=temp[i];
	}

}
///////////////////////////////////////////////////////////////
//	Do Sun
///////////////////////////////////////////////////////////////
void	DoSun(void)
{
	if(SUNm==1)
		DrawSun();
}
///////////////////////////////////////////////////////////////
//	Draw Sun
///////////////////////////////////////////////////////////////
void	DrawSun(void)
{
	//WORD	block;
	int	x,y;
	BYTE	data;

	for(y=0;y<SUNh;y++)
	{
		for(x=0;x<24;x++)
		{

			SUNbuff[old][(y*24)+x]=GetPixel(60+x,SUNy+y);

			data=GFXsun[(y*24)+x];
			if(data!=0)
				PlotPixel(60+x,SUNy+y,data);
		}
	}

	SUNyold[old]=SUNy;
	SUNhold[old]=SUNh;
}

///////////////////////////////////////////////////////////////
//	Remove Sun
///////////////////////////////////////////////////////////////
void	RemoveSun(void)
{
	//WORD	block;
	int	x,y;
	BYTE	data;

	if(SUNyold[old]!=65535)
	{
		for(y=0;y<SUNhold[old];y++)
		{
			for(x=0;x<24;x++)
			{
				data=SUNbuff[old][(y*24)+x];
				PlotPixel(60+x,SUNyold[old]+y,data);
			}
		}
	}

}
///////////////////////////////////////////////////////////////
//	Do Cheat Stuff
///////////////////////////////////////////////////////////////
void	DoCheat(void)
{
	BYTE	lev;

	lev=0;

	if( KeyTable[key_1]==1 )
		lev|=1;

	if( KeyTable[key_2]==1 )
		lev|=2;

	if( KeyTable[key_3]==1 )
		lev|=4;

	if( KeyTable[key_4]==1 )
		lev|=8;

	if( KeyTable[key_5]==1 )
		lev|=16;

	if(lev>19)
		lev=0;

	if(TONKS==1)
		lev+=20;

	if( KeyTable[key_6]==1 )
	{
		SDL_PauseAudio(1);

		LEVEL=lev;
		ChangeLevelCheat();
	}

	if(	(KeyTable[key_7]==1)&&
		(KeyTable[key_8]==1)&&
		(KeyTable[key_0]==1))
	{
		LIVES=12;
	}

}
///////////////////////////////////////////////////////////////
//	Change Level for Cheat
///////////////////////////////////////////////////////////////
void	ChangeLevelCheat(void)
{
	WaitVR();
	CopyLevelInfo();
	DrawLevel();
	SwapPage();
	DrawLevel();

	if(MUSICtype==0)
	{
		if((LEVEL==19)||(LEVEL==39))
			musicLoadXM(FINAL_XMSize, FINAL_XM);
		else
			musicLoadXM(INGAME_XMSize, INGAME_XM);
	}
	else
	{ 
		musicLoadXM(ORIGINAL_XMSize, ORIGINAL_XM);
	}
}
///////////////////////////////////////////////////////////////
//	Check for Cheat
///////////////////////////////////////////////////////////////
void	CheckCheat(void)
{
	if(CHEATh==1)
	{
		if(KeyTable[CHEATkey[CHEATp]]!=1)
		{
			CHEATp++;
			if(CHEATp==6)
				CHEAT=1;
			CHEATh=0;
		}
	}

	if(KeyTable[CHEATkey[CHEATp]]==1)
	{
		CHEATh=1;
	}
	else
	{
		if(AnyKey()==1)
			CHEATp=0;
	}

}
///////////////////////////////////////////////////////////////
//	Check for MUSIC
///////////////////////////////////////////////////////////////
void	CheckMusic(void)
{
	if( 	(KeyTable[key_h]==1)||
		(KeyTable[key_j]==1)||
		(KeyTable[key_k]==1)||
		(KeyTable[key_l]==1))
	{
		MUSICon++;
		MUSICon&=1;

		if(MUSICon==0)
			SDL_PauseAudio(1);
		else
			SDL_PauseAudio(0);

	}

}
///////////////////////////////////////////////////////////////
//	Check for Pause
///////////////////////////////////////////////////////////////
void	CheckPause(void)
{
	if(PAUSE==0)
	{
		if( 	(KeyTable[key_a]==1)||
			(KeyTable[key_s]==1)||
			(KeyTable[key_d]==1)||
			(KeyTable[key_f]==1)||
			(KeyTable[key_g]==1))
		{
			PAUSE=1;
		}
	}
	else
	{
		if( 	((KeyTable[key_a]==0)&&
			(KeyTable[key_s]==0)&&
			(KeyTable[key_d]==0)&&
			(KeyTable[key_f]==0)&&
			(KeyTable[key_g]==0))&&(AnyKey()==1))
		{
			PAUSE=0;
		}
	}

}
///////////////////////////////////////////////////////////////
//	Last Exit
///////////////////////////////////////////////////////////////
void	LastExit(void)
{
	switch(LASTm)
	{
		case	0:
			LastFirst();
			break;
		case	1:
			LastFade();
			break;
		case	2:
			LastClear();
			break;
		case	3:
			LastBit();
			break;
	}
}
///////////////////////////////////////////////////////////////
//	Last Air
///////////////////////////////////////////////////////////////
void	LastFirst(void)
{
	int	i;

	SDL_PauseAudio(1);

	LevelDoneExtra();
	SwapPage();
	LevelDoneExtra();
	SwapPage();

	for(i=0;i<8;i++)
	{
		PaletteSet(PALwhite);
		WaitVR();
		PaletteSet(PALmain);
		WaitVR();
	}

	do
	{
		SwapPage();
		sfxLoadWAV(JUMP_WAVSize, JUMP_WAV,6000+(cAIR*((old+1)*100)));
		//MIDASplaySample(wav,6,255,6000+(cAIR*((old+1)*100)),64,MIDAS_PAN_MIDDLE);
		//MIDASplaySample(wav,7,255,4000+(cAIR*((old+1)*100)),64,MIDAS_PAN_MIDDLE);
		DrawAir();
		cAIR--;
		SCORE+=9;
		PrintScore();
	}
	while(cAIR>32);

	if(SCORE>HISCORE)
	{
		HISCORE=SCORE;
	}

	musicLoadXM(LASTFIRST_XMSize, LASTFIRST_XM);
	LASTm=1;
	LASTp=0;
}
///////////////////////////////////////////////////////////////
//	Fade Down Game
///////////////////////////////////////////////////////////////
void	LastFade(void)
{

	LASTp++;
	if(LASTp==4)
	{
		LASTp=0;

		PaletteFade(PALblack,PALfade);

		LASTc++;
		if(LASTc==4)
		{
			LASTc=0;
			SUNy++;
			SUNh--;
			if(SUNh==0)
				LASTm=2;
		}

		SwapPage();
		PaletteSet(PALfade);
		RemoveSun();
		DoSun();
	}
	else
	{
		SwapPage();
		RemoveSun();
		DoSun();
		DrawAir();
		PrintScore();
	}
}
///////////////////////////////////////////////////////////////
//	Clear Last Screen
///////////////////////////////////////////////////////////////
void	LastClear(void)
{
	cls(0);
  
	SwapPage();
	LASTc++;
	if(LASTc==2)
	{
		LASTm=3;
		PaletteSet(PALmain);
		LASTc=0;
		LASTp=0;

		TEXTm=0;
		TEXTpause=0;
		TEXTpoint=0;
		TEXTink=0;
		TEXTfade=0;

	}
}
///////////////////////////////////////////////////////////////
//	Draw House
///////////////////////////////////////////////////////////////
void	DrawHouse(void)
{
	int	x,y,c;

	c=0;
	for(y=0;y<32;y++)
	{
		for(x=0;x<32;x++)
		{
			PlotPixel(176+x,y,GFXhouse[c]);
			c++;
		}
	}
}

///////////////////////////////////////////////////////////////
//	Draw Window
///////////////////////////////////////////////////////////////
void	DrawWindow(WORD block)
{
	int	x,y;

	block*=256;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			PlotPixel(184+x,8+y,GFXwin[block]);
			block++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Last Bit
///////////////////////////////////////////////////////////////
void	LastBit(void)
{
  if (MODFILE_getplaystatus(&mod) > 14) 
	{
		MODE=0;
		TITLEm=0;
		GAMEm=0;
		SDL_PauseAudio(1);
	}
  
	LASTp++;
	if(LASTp==6)
	{
		LASTp=0;
		LASTc++;
		if(LASTc==16)
			LASTc=0;
	}

	DrawHouse();
	DrawWindow(WINDOW[LASTc]);
	DoText();
	SwapPage();

}
///////////////////////////////////////////////////////////////
//	Do End Text
///////////////////////////////////////////////////////////////
void	DoText(void)
{
	switch(TEXTm)
	{
		case	0:
			FadeUpText();
			break;
		case	1:
			PauseText();
			break;
		case	2:
			FadeDownText();
			break;
	}

}
///////////////////////////////////////////////////////////////
//	Fade Up Text
///////////////////////////////////////////////////////////////
void	FadeUpText(void)
{
	TEXTink++;
	if(TEXTink>=63)
	{
		TEXTpause=0;
		if(TEXTpoint<84)
			TEXTm=1;
		else
			TEXTink=63;
	}
	INK=(127-(TEXTink>>2));

	FontPrint(0,11,EndText[TEXTpoint]);
	FontPrint(0,12,EndText[TEXTpoint+1]);
	FontPrint(0,13,EndText[TEXTpoint+2]);
}

///////////////////////////////////////////////////////////////
//	Fade Down Text
///////////////////////////////////////////////////////////////
void	FadeDownText(void)
{
	TEXTink--;
	if(TEXTink==0)
	{
		TEXTm=0;
		TEXTpoint+=3;

	}
	INK=(127-(TEXTink>>2));

	FontPrint(0,11,EndText[TEXTpoint]);
	FontPrint(0,12,EndText[TEXTpoint+1]);
	FontPrint(0,13,EndText[TEXTpoint+2]);
}
///////////////////////////////////////////////////////////////
//	Text Pause
///////////////////////////////////////////////////////////////
void	PauseText(void)
{
	FontPrint(0,11,EndText[TEXTpoint]);
	FontPrint(0,12,EndText[TEXTpoint+1]);
	FontPrint(0,13,EndText[TEXTpoint+2]);

	TEXTpause++;
	if(TEXTpause==EndPause[TEXTpoint])
	{
		TEXTpause=0;
		TEXTm=2;
	}
}

