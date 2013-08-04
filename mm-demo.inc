

///////////////////////////////////////////////////////////////
//	Setup Demo
///////////////////////////////////////////////////////////////
void	DemoSetup(void)
{
	int	count;

	DEMOm=1;
	DEMOp=0;
	LIVES=3;
	LIVESp=0;
	LIVESf=0;

	for(count=0;count<768;count++)
	{
		PALwhite[count]=63;
		PALblack[count]=0;
		PALfade[count]=PALmain[count];
		PALover[count]=PALmain[count];
	}

	WaitVR();
	CopyLevelInfo();
	DrawDemoLevel();
	SwapPage();
	DrawDemoLevel();
	PaletteSet(PALmain);
	NEXTBIT=0;
}
///////////////////////////////////////////////////////////////
//	Do Demo
///////////////////////////////////////////////////////////////
void	RunDemo(void)
{
	//int	speed,;
  int i;

	cWILLYx=0;
	cWILLYy=128;

	SwapPage2();
	NEXTBIT=FrCt+SPEED;

	RemoveSPG();
	RemoveSky();
	RemoveKong();
	RemoveVRobo();
	RemoveHRobo();
	RemoveEugene();

	DrawKeys();
	DrawConv();

	DrawSwitches();

	DoHRobo();
	DoVRobo();
	DoSpecialRobo();

	DrawExit();
	DrawAir();

	DrawLives();

	DEMOp++;

	if(DEMOp>60)
	{
		DEMOm=2;
		LevelDoneExtra();
		SwapPage();
		LevelDoneExtra();

		for(i=0;i<8;i++)
		{
			PaletteSet(PALwhite);
			SwapPage();WaitVR();WaitVR();WaitVR();
			PaletteSet(PALmain);
			SwapPage();WaitVR();WaitVR();WaitVR();
		}
	}

	if(AnyKey()==1)
	{
		MODE=0;
		TITLEm=0;
		SDL_PauseAudio(1);
	}

}
///////////////////////////////////////////////////////////////
//	Draw Level
///////////////////////////////////////////////////////////////
void	DrawDemoLevel(void)
{
	DrawCurrentLevel();
	DrawConv();
	DrawKeys();
	DrawSwitches();
	DrawExit();
	DrawTPlate();
	DrawAirBG();
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
}
///////////////////////////////////////////////////////////////
//	Next Demo Level
///////////////////////////////////////////////////////////////
void	NextDemo(void)
{
	LEVEL++;
	if(LEVEL==20)
		LEVEL=0;

	if(LEVEL==40)
		LEVEL=20;

	DemoSetup();
}


///////////////////////////////////////////////////////////////
//	Do Demo
///////////////////////////////////////////////////////////////
void	DoDemo(void)
{

	switch(DEMOm)
	{
		case	0:
			if(TONKS==0)
				LEVEL=0;
			else
				LEVEL=20;

			DemoSetup();
			break;
		case	1:
			RunDemo();
			break;
		case	2:
			NextDemo();
			break;
	}
}
