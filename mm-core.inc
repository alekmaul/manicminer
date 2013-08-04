

///////////////////////////////////////////////////////////////
//	Copy Level to Current Level
///////////////////////////////////////////////////////////////
void	CopyLevelInfo(void)
{
	int	count1;//,count2;

	for(count1=0;count1<512;count1++)
	{
		cMAP[count1]=map[LEVEL][count1];

		if(map[LEVEL][count1]==4)
			cCRUMB[count1]=8;
		else
			cCRUMB[count1]=0;

	}

	for(count1=0;count1<32;count1++)
		cTITLE[count1]=title[LEVEL][count1];

	cBGink=BGink[LEVEL];
	cBGpaper=BGpaper[LEVEL];

	cPLAT1ink=PLAT1ink[LEVEL];
	cPLAT1paper=PLAT1paper[LEVEL];

	cPLAT2ink=PLAT2ink[LEVEL];
	cPLAT2paper=PLAT2paper[LEVEL];

	cWALLink=WALLink[LEVEL];
	cWALLpaper=WALLpaper[LEVEL];

	cCRUMBink=CRUMBink[LEVEL];
	cCRUMBpaper=CRUMBpaper[LEVEL];

	cKILL1ink=KILL1ink[LEVEL];
	cKILL1paper=KILL1paper[LEVEL];

	cKILL2ink=KILL2ink[LEVEL];
	cKILL2paper=KILL2paper[LEVEL];

	cCONVink=CONVink[LEVEL];
	cCONVpaper=CONVpaper[LEVEL];
	cCONVx=CONVx[LEVEL];
	cCONVy=CONVy[LEVEL];
	cCONVd=CONVd[LEVEL];
	cCONVl=CONVl[LEVEL];
	cCONVf=0;
	cCONVm=0;
	cCONV1=0;

	cBORDER=BORDER[LEVEL];

	cPLAT1gfx=PLAT1gfx[LEVEL];
	cPLAT2gfx=PLAT2gfx[LEVEL];
	cWALLgfx=WALLgfx[LEVEL];
	cCRUMBgfx=CRUMBgfx[LEVEL];
	cKILL1gfx=KILL1gfx[LEVEL];
	cKILL2gfx=KILL2gfx[LEVEL];
	cCONVgfx=CONVgfx[LEVEL];
	cEXITgfx=EXITgfx[LEVEL];
	cKEYgfx=KEYgfx[LEVEL];

	cWILLYx=WILLYsx[LEVEL];
	cWILLYy=WILLYsy[LEVEL];
	cWILLYd=WILLYsd[LEVEL];
	cWILLYm=0;
	cWILLYf=0;
	cWILLYfall=0;
	cWILLYj=0;
	cWILLYxold[0]=65535;
	cWILLYyold[0]=65535;
	cWILLYxold[1]=65535;
	cWILLYyold[1]=65535;
	cWILLYjs=0;

	ClearWillyCol();

	for(count1=0;count1<5;count1++)
	{
		cKEYx[count1]=KEYx[LEVEL][count1];
		cKEYy[count1]=KEYy[LEVEL][count1];
		cKEYb[count1]=(count1*2);
		cKEYs[count1]=KEYs[LEVEL][count1];
	}

	for(count1=0;count1<2;count1++)
	{
		cSWITCHx[count1]=SWITCHx[LEVEL][count1];
		cSWITCHy[count1]=SWITCHy[LEVEL][count1];
		cSWITCHs[count1]=SWITCHs[LEVEL][count1];
	}

	cEXITx=EXITx[LEVEL];
	cEXITy=EXITy[LEVEL];
	cEXITb=0;
	cEXITm=0;

	cAIR=AIR[LEVEL]+31;
	cAIRp=8;

	for(count1=0;count1<4;count1++)
	{
		cHROBOink[count1]=HROBOink[LEVEL][count1];
		cHROBOpaper[count1]=HROBOpaper[LEVEL][count1];
		cHROBOx[count1]=HROBOx[LEVEL][count1];
		cHROBOy[count1]=HROBOy[LEVEL][count1];
		cHROBOmin[count1]=HROBOmin[LEVEL][count1];
		cHROBOmax[count1]=HROBOmax[LEVEL][count1];
		cHROBOd[count1]=HROBOd[LEVEL][count1];
		cHROBOs[count1]=HROBOs[LEVEL][count1];
		cHROBOgfx[count1]=HROBOgfx[LEVEL][count1];
		cHROBOflip[count1]=HROBOflip[LEVEL][count1];
		cHROBOanim[count1]=HROBOanim[LEVEL][count1];
		cHROBOxold[count1][0]=65535;
		cHROBOxold[count1][1]=65535;
		cHROBOyold[count1][0]=65535;
		cHROBOyold[count1][1]=65535;
	}

	for(count1=0;count1<4;count1++)
	{
		cVROBOink[count1]=VROBOink[LEVEL][count1];
		cVROBOpaper[count1]=VROBOpaper[LEVEL][count1];
		cVROBOx[count1]=VROBOx[LEVEL][count1];
		cVROBOy[count1]=VROBOy[LEVEL][count1];
		cVROBOmin[count1]=VROBOmin[LEVEL][count1];
		cVROBOmax[count1]=VROBOmax[LEVEL][count1];
		cVROBOd[count1]=VROBOd[LEVEL][count1];
		cVROBOs[count1]=VROBOs[LEVEL][count1];
		cVROBOgfx[count1]=VROBOgfx[LEVEL][count1];
		//cVROBOanim[count1]=VROBOanim[LEVEL][count1];
		cVROBOanim[count1]=count1;
		cVROBOyold[count1][0]=65535;
		cVROBOyold[count1][1]=65535;
		cVROBOxold[count1][0]=65535;
		cVROBOxold[count1][1]=65535;
	}

	EUGENEx=120;
	EUGENEy=1;
	EUGENEd=0;
	EUGENEm=0;
	EUGENEc=7;
	EUGENEmin=1;
	EUGENEmax=87;
	EUGENExold[0]=65535;
	EUGENEyold[0]=65535;
	EUGENExold[1]=65535;
	EUGENEyold[1]=65535;

	SWITCH1m=0;
	SWITCH2m=0;

	HOLEl=2;
	HOLEy=95;

	KONGx=120;
	KONGy=0;
	KONGmax=104;
	KONGm=0;
	KONGc=3;
	KONGf=0;
	KONGp=KONGPAUSE;
	KONGxold[0]=65535;
	KONGyold[0]=65535;
	KONGxold[1]=65535;
	KONGyold[1]=65535;

	SKYp[0]=0;
	SKYp[1]=2;
	SKYp[2]=1;

	SKYs[0]=4;
	SKYs[1]=3;
	SKYs[2]=1;

	SKYc[0]=6;
	SKYc[1]=5;
	SKYc[2]=4;

	SKYmax[0]=72;
	SKYmax[1]=56;
	SKYmax[2]=32;

	SKYxold[0][0]=65535;
	SKYyold[0][0]=65535;


	for(count1=0;count1<3;count1++)
	{
		SKYx[count1]=SKYpx[count1][SKYp[count1]];
		SKYy[count1]=SKYpy[count1][SKYp[count1]];
		SKYm[count1]=0;
		SKYf[count1]=0;
		SKYxold[count1][0]=65535;
		SKYyold[count1][0]=65535;
		SKYxold[count1][1]=65535;
		SKYyold[count1][1]=65535;
	}

	for(count1=0;count1<64;count1++)
	{
		SPGx[0][count1]=65535;
		SPGy[0][count1]=65535;
		SPGx[1][count1]=65535;
		SPGy[1][count1]=65535;
	}

	DEATHm=0;
	DEATHc=0;

	for(count1=0;count1<768;count1++)
	{
		PALfade[count1]=PALmain[count1];
	}

	SUNm=0;
	SUNy=32;
	SUNh=16;
	SUNyold[0]=65535;
	SUNyold[1]=65535;
	SUNhold[0]=255;
	SUNhold[1]=255;
}

///////////////////////////////////////////////////////////////
//	Draw Current Level
///////////////////////////////////////////////////////////////
void	DrawCurrentLevel(void)
{
	int	xpos,ypos;
	BYTE	block;

	cls(cBORDER);

	for(ypos=0;ypos<16;ypos++)
	{
		for(xpos=0;xpos<32;xpos++)
		{
			block=cMAP[(ypos*32)+xpos];

			switch(block)
			{
				case	0:
					DrawBGBlock(xpos,ypos);
					break;
				case	1:
					DrawBlock(xpos,ypos,cPLAT1gfx,cPLAT1ink);
					break;
				case	2:
					DrawBlock(xpos,ypos,cPLAT2gfx,cPLAT2ink);
					break;
				case	3:
					DrawBlock(xpos,ypos,cWALLgfx,cWALLink);
					break;
				case	4:
					DrawBlock(xpos,ypos,cCRUMBgfx,cCRUMBink);
					break;
				case	5:
					DrawBlock(xpos,ypos,cKILL1gfx,cKILL1ink);
					break;
				case	6:
					DrawBlock(xpos,ypos,cKILL2gfx,cKILL2ink);
					break;
			}
		}
	}
	if((LEVEL==19)||(LEVEL==39))
	{
		DrawFinal();
		SUNm=1;
		SUNy=32;
		SUNh=16;
		DoSun();
	}
}

///////////////////////////////////////////////////////////////
//	Draw a BackGround Block
///////////////////////////////////////////////////////////////
void	DrawBGBlock(int xpos,int ypos)
{
	int	x,y;

	xpos*=8;
	ypos*=8;

	for(y=0;y<8;y++)
	{
		for(x=0;x<8;x++)
		{
			PlotPixel(xpos+x,ypos+y,cBGpaper);
		}
	}
}

///////////////////////////////////////////////////////////////
//	Draw a Block
///////////////////////////////////////////////////////////////
void	DrawBlock(int xpos,int ypos,BYTE block, BYTE ink)
{
	int	x,y,block2;
	BYTE	data;

	xpos*=8;
	ypos*=8;

	block2=(WORD)block;
	block2*=64;

	for(y=0;y<8;y++)
	{
		for(x=0;x<8;x++)
		{
			data=GFXblocks[block2];

			if(!data)
				PlotPixel(xpos+x,ypos+y,cBGpaper);
			else
				PlotPixel(xpos+x,ypos+y,data+(ink*16));

			block2++;
		}
	}
}

///////////////////////////////////////////////////////////////
//	Draw a Convayor Block
///////////////////////////////////////////////////////////////
void	DrawConvBlock(int xpos,int ypos,BYTE block,BYTE frame)
{
	int	x,y,block2,frame2;
	BYTE	data;

	block2=(WORD)block;
	block2*=256;

	frame2=(WORD)frame;
	frame2*=64;

	block2+=frame2;

	for(y=0;y<8;y++)
	{
		for(x=0;x<8;x++)
		{
			data=GFXconv[block2];

			if(!data)
				PlotPixel(xpos+x,ypos+y,cBGpaper);
			else
				PlotPixel(xpos+x,ypos+y,data+(cCONVink*16));

			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw Convayor
///////////////////////////////////////////////////////////////
void	DrawConv(void)
{
	int	count;


	if(cCONVy!=0)
	{

		for(count=0;count<cCONVl;count++)
		{
			DrawConvBlock(cCONVx+(count*8),cCONVy,cCONVgfx,cCONVf);
		}


		switch(cCONVd)
		{
			case	0:
				cCONVf++;
				cCONVf&=3;
				break;

			case	1:
				cCONVf--;
				cCONVf&=3;
				break;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw Exit
///////////////////////////////////////////////////////////////
void	DrawExit(void)
{
	int	x,y,block2;
	BYTE	data,temp;
	WORD	xpos,ypos;

	xpos=cEXITx;
	ypos=cEXITy;

	block2=(WORD)cEXITgfx;
	block2*=256;

	switch(cEXITm)
	{
		case	0:
			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					data=GFXexit[block2];

					if(data)
						PlotPixel(xpos+x,ypos+y,data);

					block2++;
				}
			}

			break;

		case	1:

			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					data=GFXexit[block2];

					if(data)
					{
						temp=data&15;
						temp-=bright[cEXITb];

						if(temp>15)
							temp=0;

						data&=240;
						data|=temp;

						PlotPixel(xpos+x,ypos+y,data);
					}
					block2++;
				}
			}

			cEXITb++;
			cEXITb&=15;
			break;
	}

}
///////////////////////////////////////////////////////////////
//	Draw a Key
///////////////////////////////////////////////////////////////
void	DrawKeyBlock(int xpos,int ypos,BYTE block,BYTE shine)
{
	int	x,y,block2;
	BYTE	data,temp;

	block2=(WORD)block;
	block2*=64;

	for(y=0;y<8;y++)
	{
		for(x=0;x<8;x++)
		{
			data=GFXkey[block2];

			if(!data)
				PlotPixel(xpos+x,ypos+y,cBGpaper);
			else
			{
				temp=data&15;
				temp-=shine;

				if(temp>15)
					temp=0;

				data&=240;
				data|=temp;

				PlotPixel(xpos+x,ypos+y,data);
			}
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw Keys
///////////////////////////////////////////////////////////////
void	DrawKeys(void)
{
	int	i,count;

	count=0;

	for(i=0;i<5;i++)
	{
		if(cKEYs[i]==1)
		{
			if((cKEYx[i]!=65535)&&(cKEYy[i]!=65535))
			{
				DrawKeyBlock(cKEYx[i],cKEYy[i],cKEYgfx,bright2[cKEYb[i]]);
				count++;
			}

			cKEYb[i]++;
			cKEYb[i]&=15;
		}
		else
		{
			if((cKEYx[i]!=65535)&&(cKEYy[i]!=65535))
			{
				DrawBGBlock(cKEYx[i]/8,cKEYy[i]/8);
			}
		}
	}

	if(!count)
		cEXITm=1;
}

///////////////////////////////////////////////////////////////
//	Draw Level Title Plate
///////////////////////////////////////////////////////////////
void	DrawTPlate(void)
{
	int	x,y;
//	BYTE	data;

	for(y=0;y<8;y++)
	{
		for(x=0;x<256;x++)
		{
			PlotPixel(x,128+y,GFXtplate[(y*256)+x]);
		}
	}

	FontPrint2(0,16,cTITLE);
}
///////////////////////////////////////////////////////////////
//	Draw Air Background
///////////////////////////////////////////////////////////////
void	DrawAirBG(void)
{
	int	x,y;
//	BYTE	data;

	for(y=0;y<8;y++)
	{
		for(x=0;x<256;x++)
		{
			PlotPixel(x,136+y,GFXair[(y*256)+x]);
		}
	}

	FontPrint2(0,17,"AIR");
}
///////////////////////////////////////////////////////////////
//	Draw Air
///////////////////////////////////////////////////////////////
void	DrawAir(void)
{
	int	x;//,y;

	cAIRp--;
	if(cAIRp==0)
	{
		cAIRp=8;

		cAIR--;

		if(cAIR<=33)
		{
			cAIR=33;
			cWILLYm=6;
		}
	}


	for(x=30;x<256;x++)
	{
		PlotPixel(x,138,GFXair[512+x]);
		PlotPixel(x,139,GFXair[768+x]);
		PlotPixel(x,140,GFXair[1024+x]);
		PlotPixel(x,141,GFXair[1280+x]);
	}

	PlotPixel(32,138,122);
	PlotPixel(32,139,116);
	PlotPixel(32,140,119);
	PlotPixel(32,141,123);

	for(x=33;x<(cAIR-1);x++)
	{
		PlotPixel(x,138,120);
		PlotPixel(x,139,114);
		PlotPixel(x,140,117);
		PlotPixel(x,141,121);
	}

	PlotPixel(cAIR-1,138,122);
	PlotPixel(cAIR-1,139,116);
	PlotPixel(cAIR-1,140,119);
	PlotPixel(cAIR-1,141,123);

}

///////////////////////////////////////////////////////////////
//	Draw a HORIZONTAL Robot
///////////////////////////////////////////////////////////////
void	DrawHRobo(WORD xpos, WORD ypos, WORD sprite, BYTE col)
{
	int	x,y;//,block2,frame2;
	BYTE	data;

	sprite*=256;
	col--;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXhrobo[sprite];

			if(data)
			{
				PlotPixel(xpos+x,ypos+y,data+(col*16));
				cWILLYcol[ypos+y][xpos+x]=1;
			}

			sprite++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Horizontal Robots
///////////////////////////////////////////////////////////////
void	DoHRobo(void)
{
	int	i;


	for(i=0;i<4;i++)
	{
		if(cHROBOx[i]!=65535)
		{
			if( cHROBOd[i] )
			{

				cHROBOx[i]-=(2>>cHROBOs[i]);

				if(cHROBOx[i]<cHROBOmin[i])
				{
					cHROBOd[i]=0;
					cHROBOx[i]+=(2>>cHROBOs[i]);
					DrawHRobo((cHROBOx[i]&248),cHROBOy[i],cHROBOgfx[i]+((cHROBOx[i]&cHROBOanim[i])>>1),cHROBOink[i]);
				}
				else
					DrawHRobo((cHROBOx[i]&248),cHROBOy[i],(cHROBOgfx[i]+((cHROBOx[i]&cHROBOanim[i])>>1))+cHROBOflip[i],cHROBOink[i]);
			}
			else
			{
				cHROBOx[i]+=(2>>cHROBOs[i]);

				if(cHROBOx[i]>(cHROBOmax[i]+6))
				{
					cHROBOd[i]=1;
					cHROBOx[i]-=(2>>cHROBOs[i]);
					DrawHRobo((cHROBOx[i]&248),cHROBOy[i],(cHROBOgfx[i]+((cHROBOx[i]&cHROBOanim[i])>>1))+cHROBOflip[i],cHROBOink[i]);
				}
				else
					DrawHRobo((cHROBOx[i]&248),cHROBOy[i],cHROBOgfx[i]+((cHROBOx[i]&cHROBOanim[i])>>1),cHROBOink[i]);
			}

			cHROBOxold[i][old]=cHROBOx[i]&248;
			cHROBOyold[i][old]=cHROBOy[i];
		}
	}
}
///////////////////////////////////////////////////////////////
//	Remove Horizontal Robots
///////////////////////////////////////////////////////////////
void	RemoveHRobo(void)
{
	int	i,x,y;

	for(i=0;i<4;i++)
	{
		if(cHROBOxold[i][old]!=65535)
		{
			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					PlotPixel(cHROBOxold[i][old]+x,cHROBOyold[i][old]+y,cBGpaper);
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////
//	Draw a VERTICAL Robot
///////////////////////////////////////////////////////////////
void	DrawVROBO(WORD xpos, WORD ypos, WORD sprite, BYTE col)
{
	int	x,y;//,block2,frame2;
	BYTE	data;

	sprite*=256;
	col--;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXvrobo[sprite];

			if(data)
			{
				PlotPixel(xpos+x,ypos+y,data+(col*16));
				cWILLYcol[ypos+y][xpos+x]=1;
			}

			sprite++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Vertical Robots
///////////////////////////////////////////////////////////////
void	DoVRobo(void)
{
	int	i;


	for(i=0;i<4;i++)
	{
		if(cVROBOx[i]!=65535)
		{
			if( cVROBOd[i] )
			{

				cVROBOy[i]-=(cVROBOs[i]);

				if((cVROBOy[i]<cVROBOmin[i])||(cVROBOy[i]>256))
				{
					cVROBOd[i]=0;
					cVROBOy[i]+=(cVROBOs[i]);
					DrawVROBO(cVROBOx[i],cVROBOy[i],(cVROBOgfx[i]+cVROBOanim[i]),cVROBOink[i]);
				}
				else
					DrawVROBO(cVROBOx[i],cVROBOy[i],(cVROBOgfx[i]+cVROBOanim[i]),cVROBOink[i]);
			}
			else
			{
				cVROBOy[i]+=(cVROBOs[i]);

				if(cVROBOy[i]>cVROBOmax[i])
				{
					cVROBOd[i]=1;
					cVROBOy[i]-=(cVROBOs[i]);
					DrawVROBO(cVROBOx[i],cVROBOy[i],(cVROBOgfx[i]+cVROBOanim[i]),cVROBOink[i]);
				}
				else
					DrawVROBO(cVROBOx[i],cVROBOy[i],(cVROBOgfx[i]+cVROBOanim[i]),cVROBOink[i]);
			}
			cVROBOanim[i]++;
			cVROBOanim[i]&=3;

			cVROBOxold[i][old]=cVROBOx[i];
			cVROBOyold[i][old]=cVROBOy[i];
		}
	}
}
///////////////////////////////////////////////////////////////
//	Remove Vertical Robots
///////////////////////////////////////////////////////////////
void	RemoveVRobo(void)
{
	int	i,x,y;

	for(i=0;i<4;i++)
	{
		if(cVROBOxold[i][old]!=65535)
		{
			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					PlotPixel(cVROBOxold[i][old]+x,cVROBOyold[i][old]+y,cBGpaper);
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw Final Screen Background
///////////////////////////////////////////////////////////////
void	DrawFinal(void)
{
	int	x,y;
	BYTE	data;

	for(y=0;y<64;y++)
	{
		for(x=0;x<256;x++)
		{
			data=GFXfinal[(y*256)+x];

			if(!data)
				PlotPixel(x,y,cBGpaper);
			else
				PlotPixel(x,y,data);

		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw a Switch
///////////////////////////////////////////////////////////////
void	DrawSwitchBlock(int xpos,int ypos,BYTE block)
{
	int	x,y,block2;
	BYTE	data;//,temp;

	block2=(WORD)block;
	block2*=64;

	for(y=0;y<8;y++)
	{
		for(x=0;x<8;x++)
		{
			data=GFXswitch[block2];

			if(!data)
				PlotPixel(xpos+x,ypos+y,cBGpaper);
			else
			{
				PlotPixel(xpos+x,ypos+y,data+((cPLAT2ink-1)*16));
			}
			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Draw Switches
///////////////////////////////////////////////////////////////
void	DrawSwitches(void)
{
	int	i;

	for(i=0;i<2;i++)
	{
		if(cSWITCHs[i]!=0)
			DrawSwitchBlock(cSWITCHx[i],cSWITCHy[i],cSWITCHs[i]-1);
	}
}
///////////////////////////////////////////////////////////////
//	Do Special Robo
///////////////////////////////////////////////////////////////
void	DoSpecialRobo(void)
{

	switch(LEVEL)
	{
		case	4:
			DoEugene();
			break;
		case	7:
			DoLevelSeven();
			break;
		case	11:
			DoLevelSeven();
			break;
		case	13:
			DoLevelThirteen();
			break;
		case	18:
			DoSPG();
			CheckSPG();
			break;

		case	24:
			DoEugene();
			break;
		case	27:
			DoLevelSeven();
			break;
		case	31:
			DoLevelSeven();
			break;
		case	33:
			DoLevelThirteen();
			break;
		case	38:
			DoSPG();
			CheckSPG();
			break;
	}
}
///////////////////////////////////////////////////////////////
//	Draw Eugene
///////////////////////////////////////////////////////////////
void	DrawEUGENE(WORD xpos, WORD ypos, BYTE col)
{
	int	x,y;
	BYTE	data;

	col--;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			if(TONKS==0)
				data=GFXeugene[((y*16)+x)];
			else
				data=GFXeugene[256+((y*16)+x)];

			if(data)
			{
				PlotPixel(xpos+x,ypos+y,data+(col*16));
				cWILLYcol[ypos+y][xpos+x]=1;
			}

		}
	}
}
///////////////////////////////////////////////////////////////
//	Remove Eugene
///////////////////////////////////////////////////////////////
void	RemoveEugene(void)
{
	//int	i,
  int x,y;

		if(EUGENExold[old]!=65535)
		{
			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					PlotPixel(EUGENExold[old]+x,EUGENEyold[old]+y,cBGpaper);
				}
			}
		}
}

///////////////////////////////////////////////////////////////
//	Do Eugene
///////////////////////////////////////////////////////////////
void	DoEugene(void)
{

	if(cEXITm==1)
		EUGENEm=1;

	switch(EUGENEm)
	{
		case	0:
			if( EUGENEd )
			{

				EUGENEy--;

				if(EUGENEy<EUGENEmin)
				{
					EUGENEd=0;
					EUGENEy++;
					DrawEUGENE(EUGENEx,EUGENEy,EUGENEc);
				}
				else
					DrawEUGENE(EUGENEx,EUGENEy,EUGENEc);
			}
			else
			{
				EUGENEy++;

				if(EUGENEy>EUGENEmax)
				{
					EUGENEd=1;
					EUGENEy--;
					DrawEUGENE(EUGENEx,EUGENEy,EUGENEc);
				}
				else
					DrawEUGENE(EUGENEx,EUGENEy,EUGENEc);
			}

			EUGENExold[old]=EUGENEx;
			EUGENEyold[old]=EUGENEy;

			break;

		case	1:
			EUGENEc++;
			if(EUGENEc==8)
				EUGENEc=1;

			EUGENEy++;

			if(EUGENEy>EUGENEmax)
			{
				EUGENEy--;
				DrawEUGENE(EUGENEx,EUGENEy,EUGENEc);
			}
			else
				DrawEUGENE(EUGENEx,EUGENEy,EUGENEc);

			EUGENExold[old]=EUGENEx;
			EUGENEyold[old]=EUGENEy;
	}
}

///////////////////////////////////////////////////////////////
//	Do Hole
///////////////////////////////////////////////////////////////
void	DoHole(void)
{
	int	x,y;

	switch(SWITCH1m)
	{
		case	0:
			for(y=0;y<HOLEl;y++)
			{
				for(x=0;x<8;x++)
				{
					PlotPixel(136+x,HOLEy+y,cBGpaper);
				}
			}
			HOLEy--;
			HOLEl+=2;

			if(HOLEy==87)
			{
				SWITCH1m=1;
				cMAP[((88/8)*32)+(136/8)]=0;
				cMAP[((96/8)*32)+(136/8)]=0;
			}
			break;

		case	1:
			for(y=0;y<16;y++)
			{
				for(x=0;x<8;x++)
				{
					PlotPixel(136+x,88+y,cBGpaper);
				}
			}
			SWITCH1m=2;
			cHROBOmax[1]+=24;
			break;
		}
}

///////////////////////////////////////////////////////////////
//	Level 7 "Miner Willy meets the Kong Beast"
///////////////////////////////////////////////////////////////
void	DoLevelSeven(void)
{

	KONGp--;
	if(KONGp==0)
	{
		KONGp=KONGPAUSE;
		KONGf++;
		KONGf&=1;
	}

	if(cSWITCHs[0]==2)
	{
		DoHole();
	}

	if(cSWITCHs[1]==1)
	{
		DoKongStood();
	}

	if(cSWITCHs[1]==2)
	{
		DoKongFall();
	}
}

///////////////////////////////////////////////////////////////
//	Do Kong Stood
///////////////////////////////////////////////////////////////
void	DoKongStood(void)
{
	DrawKONG(KONGx,KONGy,KONGf,KONGc);

	KONGxold[old]=KONGx;
	KONGyold[old]=KONGy;
}

///////////////////////////////////////////////////////////////
//	Do Kong Falling
///////////////////////////////////////////////////////////////
void	DoKongFall(void)
{
	switch(KONGm)
	{
		case	0:
			KONGm=1;

			cMAP[((16/8)*32)+(120/8)]=0;
			cMAP[((16/8)*32)+(128/8)]=0;

			DrawBGBlock(120/8,16/8);
			DrawBGBlock(128/8,16/8);

			DrawKONG(KONGx,KONGy,KONGf,KONGc);
			KONGxold[old]=KONGx;
			KONGyold[old]=KONGy;
			break;

		case	1:
			KONGm=2;

			DrawBGBlock(120/8,16/8);
			DrawBGBlock(128/8,16/8);

			DrawKONG(KONGx,KONGy,KONGf,KONGc);
			KONGxold[old]=KONGx;
			KONGyold[old]=KONGy;

			KONGc=5;

			break;

		case	2:
			KONGy+=4;
			sfxLoadWAV(JUMP_WAVSize,JUMP_WAV,22050-(KONGy*((old+1)*50)));
			//MIDASplaySample(wav,8,255,22050-(KONGy*((old+1)*50)),64,MIDAS_PAN_MIDDLE);

			if(KONGy>=KONGmax)
			{
				//KONGy-=4;
				DrawKONG(KONGx,KONGy,KONGf+2,KONGc);
				KONGm=3;
			}
			else
			{
				DrawKONG(KONGx,KONGy,KONGf+2,KONGc);
				SCORE+=100;
			}
			KONGxold[old]=KONGx;
			KONGyold[old]=KONGy;
			break;
	}
}

///////////////////////////////////////////////////////////////
//	Draw Kong
///////////////////////////////////////////////////////////////
void	DrawKONG(int xpos,int ypos,BYTE block, BYTE ink)
{
	int	x,y,block2;
	BYTE	data;

	block2=(WORD)block;
	block2*=256;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXkong[block2];

			if(data)
			{
				PlotPixel(xpos+x,ypos+y,data+(ink*16));
				cWILLYcol[ypos+y][xpos+x]=1;
			}

			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Remove Kong
///////////////////////////////////////////////////////////////
void	RemoveKong(void)
{
	//int	i,
  int x,y;

		if(KONGxold[old]!=65535)
		{
			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					PlotPixel(KONGxold[old]+x,KONGyold[old]+y,cBGpaper);
				}
			}
		}
}
///////////////////////////////////////////////////////////////
//	Draw Skylab
///////////////////////////////////////////////////////////////
void	DrawSky(int xpos,int ypos,BYTE block, BYTE ink)
{
	int	x,y,block2;
	BYTE	data;

	block2=(WORD)block;
	block2*=256;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXsky[block2];

			if(data)
			{
				PlotPixel(xpos+x,ypos+y,data+(ink*16));
				cWILLYcol[ypos+y][xpos+x]=1;
			}

			block2++;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Remove Skylab
///////////////////////////////////////////////////////////////
void	RemoveSky(void)
{
	int	i,x,y;

	for(i=0;i<3;i++)
	{
		if(SKYxold[i][old]!=65535)
		{
			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					PlotPixel(SKYxold[i][old]+x,SKYyold[i][old]+y,cBGpaper);
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////
//	Level 13 "       Skylab Landing Bay       "
///////////////////////////////////////////////////////////////
void	DoLevelThirteen(void)
{
	int	i;

	for(i=0;i<3;i++)
	{
		switch(SKYm[i])
		{
			case	0:
				SKYy[i]+=SKYs[i];

				if(SKYy[i]>SKYmax[i])
				{
					SKYy[i]=SKYmax[i];
					SKYm[i]=1;
					SKYf[i]++;

					DrawSky(SKYx[i],SKYy[i],SKYf[i],SKYc[i]);
				}

				DrawSky(SKYx[i],SKYy[i],SKYf[i],SKYc[i]);
				break;

			case	1:
				SKYf[i]++;

				if(SKYf[i]==7)
				{
					SKYm[i]=2;
				}
				DrawSky(SKYx[i],SKYy[i],SKYf[i],SKYc[i]);
				break;

			case	2:
				SKYp[i]++;
				SKYp[i]&=3;

				SKYx[i]=SKYpx[i][SKYp[i]];
				SKYy[i]=SKYpy[i][SKYp[i]];

				SKYf[i]=0;
				SKYm[i]=0;

		}

		SKYxold[i][old]=SKYx[i];
		SKYyold[i][old]=SKYy[i];
	}

}
///////////////////////////////////////////////////////////////
//	Draw a SPG Block
///////////////////////////////////////////////////////////////
void	DrawSPGBlock(int x, int y)
{
	int	c1,c2;
	BYTE	data;

	x*=8;
	y*=8;

	for(c1=0;c1<8;c1++)
	{
		for(c2=0;c2<8;c2++)
		{
			data=GetPixel(x+c2,y+c1);

			data&=15;
			data-=4;
			if(data>15)
				data=0;

			data+=96;

			PlotPixel(x+c2,y+c1,data);
		}
	}

}

///////////////////////////////////////////////////////////////
//	Remove SPG
///////////////////////////////////////////////////////////////
void	RemoveSPG(void)
{
	int	i;

	for(i=0;i<64;i++)
	{
		if(SPGx[old][i]!=65535)
			DrawBGBlock(SPGx[old][i],SPGy[old][i]);
		else
			break;
	}
}

///////////////////////////////////////////////////////////////
//	Find Route
///////////////////////////////////////////////////////////////
void	FindSPG(void)
{
	int	x,y,i,done,blockhit,robohit;
	//BYTE	data,
  BYTE dir;


	for(i=0;i<64;i++)
	{
		SPGx[old][i]=65535;
		SPGy[old][i]=65535;
	}

	x=23;
	y=0;
	dir=0;
	done=0;
	i=0;

	do
	{

		blockhit=cMAP[(y*32)+x];
		robohit=SPGCheckRobo(x,y);

//------------------------------------------------------------------------------

		if( (blockhit!=0)&&(robohit!=0) )
		{
			SPGx[old][i]=65535;
			SPGy[old][i]=65535;
			done=1;
		}

//------------------------------------------------------------------------------

		if( (blockhit==0)&&(robohit!=0) )
		{
			if((SPGx[old][i-1]==x)&&(SPGy[old][i-1]==y))
			{
				SPGx[old][i]=65535;
				SPGy[old][i]=65535;
				done=1;
			}

			SPGx[old][i]=x;
			SPGy[old][i]=y;
			i++;

			dir++;
			dir&=1;
		}

//------------------------------------------------------------------------------

		if( (blockhit==0)&&(robohit==0) )
		{
			SPGx[old][i]=x;
			SPGy[old][i]=y;
			i++;
		}

//------------------------------------------------------------------------------

		if( (blockhit!=0)&&(robohit==0) )
		{
			if((SPGx[old][i-1]==x)&&(SPGy[old][i-1]==y))
			{
				SPGx[old][i]=65535;
				SPGy[old][i]=65535;
				done=1;
			}
			dir++;
			dir&=1;
		}

//------------------------------------------------------------------------------

		if(blockhit==0)
		{
			if(dir==0)
			{
				y++;
				blockhit=cMAP[(y*32)+x];

				if((y==15)||(blockhit!=0))
				{
					SPGx[old][i]=65535;
					SPGy[old][i]=65535;
					done=1;
				}
			}
			else
			{
				x--;
				blockhit=cMAP[(y*32)+x];

				if((x==0)||(blockhit!=0))
				{
					SPGx[old][i]=65535;
					SPGy[old][i]=65535;
					done=1;
				}
			}
		}
		else
		{
			if(dir==0)
			{
				x--;
				if(x==0)
				{
					SPGx[old][i]=65535;
					SPGy[old][i]=65535;
					done=1;
				}
			}
			else
			{
				y++;
				if(y==15)
				{
					SPGx[old][i]=65535;
					SPGy[old][i]=65535;
					done=1;
				}
			}
		}

//------------------------------------------------------------------------------
	}while(done==0);


	SPGx[old][i]=65535;
	SPGy[old][i]=65535;

}

///////////////////////////////////////////////////////////////
//	Check if hit Robo
///////////////////////////////////////////////////////////////
int	SPGCheckRobo(WORD x, WORD y)
{
	int	i;
	int	hit;

	x*=8;
	y*=8;

	hit=0;

	for(i=0;i<4;i++)
	{
		if(cHROBOx[i]!=65535)
		{
			if( ((x+7)>=cHROBOx[i]) && (x<=(cHROBOx[i]+15)) &&
				((y+7)>=cHROBOy[i]) && (y<=(cHROBOy[i]+15)))
			{
				hit++;
			}
		}

		if(cVROBOx[i]!=65535)
		{
			if( ((x+7)>=cVROBOx[i]) && (x<=(cVROBOx[i]+15)) &&
				((y+7)>=cVROBOy[i]) && (y<=(cVROBOy[i]+15)))
			{
				hit++;
			}
		}
	}


	return(hit);
}
///////////////////////////////////////////////////////////////
//	Do the Solar Power Generator
///////////////////////////////////////////////////////////////
void	DoSPG(void)
{
	int	i;

	FindSPG();

	for(i=0;i<64;i++)
	{
		if(SPGx[old][i]!=65535)
		{
			DrawSPGBlock(SPGx[old][i],SPGy[old][i]);
		}

	}

}
///////////////////////////////////////////////////////////////
//	Check SPG
///////////////////////////////////////////////////////////////
void	CheckSPG(void)
{
	int	i,hit;

	for(i=0;i<64;i++)
	{
		if(SPGx[old][i]!=65535)
		{
			hit=0;

			if(((SPGx[old][i]*8)>=cWILLYx)&&((SPGy[old][i]*8)>=cWILLYy))
			{
				if( ((SPGx[old][i]*8)<(cWILLYx+8))&&((SPGy[old][i]*8)<(cWILLYy+16)) )
				{
					hit=1;
				}
			}

			if((((SPGx[old][i]*8)+7)>=cWILLYx)&&((SPGy[old][i]*8)>=cWILLYy))
			{
				if( (((SPGx[old][i]*8)+7)<(cWILLYx+8))&&((SPGy[old][i]*8)<(cWILLYy+16)) )
				{
					hit=1;
				}
			}

			if(((SPGx[old][i]*8)>=cWILLYx)&&(((SPGy[old][i]*8)+7)>=cWILLYy))
			{
				if( ((SPGx[old][i]*8)<(cWILLYx+8))&&(((SPGy[old][i]*8)+7)<(cWILLYy+16)) )
				{
					hit=1;
				}
			}

			if((((SPGx[old][i]*8)+7)>=cWILLYx)&&(((SPGy[old][i]*8)+7)>=cWILLYy))
			{
				if( (((SPGx[old][i]*8)+7)<(cWILLYx+8))&&(((SPGy[old][i]*8)+7)<(cWILLYy+16)) )
				{
						hit=1;
				}
			}

		}
	}
	if(hit==1)
		cAIRp/=2;
}


///////////////////////////////////////////////////////////////
//	Draw Willy
///////////////////////////////////////////////////////////////
int	DrawWILLY(int xpos,int ypos,BYTE block)
{
	int	x,y,block2,hit;
	BYTE	data;

	block2=(WORD)block;
	block2*=256;

	hit=0;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			data=GFXwilly[block2];

			if(data)
			{
				if(GetPixel(xpos+x,ypos+y)==cBGpaper)
					PlotPixel(xpos+x,ypos+y,data);

				if(cWILLYcol[ypos+y][xpos+x]!=0)
					hit=1;
			}
			block2++;
		}
	}

	return(hit);
}
///////////////////////////////////////////////////////////////
//	Get Willy Background
///////////////////////////////////////////////////////////////
void	GetWillyBG(int xpos, int ypos)
{
	int	x,y;
	//BYTE	data;

	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			cWILLYbuff[old][(y*16)+x]=GetPixel(xpos+x,ypos+y);
		}
	}
}
///////////////////////////////////////////////////////////////
//	Remove Willy
///////////////////////////////////////////////////////////////
void	RemoveWilly(void)
{
	int	x,y;

	if(cWILLYxold[old]!=65535)
	{
		for(y=0;y<16;y++)
		{
			for(x=0;x<16;x++)
			{
				PlotPixel(cWILLYxold[old]+x,cWILLYyold[old]+y,cWILLYbuff[old][(y*16)+x]);
			}
		}
	}

}
///////////////////////////////////////////////////////////////
//	Do Willy Stuff
//
//	Modes:-
//	0=Walking Left\Right
//	1=Jump Up
//	2=Jump Left
//	3=jump Right
//	4=Fall
//	5=On Conv
//	6=Death
//
///////////////////////////////////////////////////////////////
void	DoWilly(void)
{
	int	input;//,block1,block2;

	input=GetWillyInput();

//------------------------------------------------------------------------------
	if(CheckWillyKillBlock()!=0)
		cWILLYm=6;
//------------------------------------------------------------------------------
	if(cWILLYm==0)
	{
		CheckWillyFall();
	}
//------------------------------------------------------------------------------
	switch( cWILLYm)
	{
//------------------------------------------------------------------------------
		case	0:
			CheckCrumb();

			if(input==1)
			{
				if((CheckWillyConv()==1)&&(cCONVd==0))
				{
					cWILLYm=5;
					cCONVm=0;
					DoOnConv(input);
				}
				else
				{
					DoWillyLeft();
					cWILLYfall=0;
				}
			}
			else
			{
				if(input==2)
				{
					if((CheckWillyConv()==1)&&(cCONVd==1))
					{
						cWILLYm=5;
						cCONVm=0;
						DoOnConv(input);
					}
					else
					{
						DoWillyRight();
						cWILLYfall=0;
					}

				}
				else
				{
					if(input==4)
					{
						cWILLYm=1;
						cWILLYj=0;
						cWILLYfall=0;
						cWILLYjs=0;

						if(CheckWillyConv()==1)
						{
							cWILLYm=5;
							if(cWILLYm==cCONVd)
							{
								cCONVm=2;
							}
							else
							{
								cWILLYd++;
								cWILLYd&=1;
								cCONVm=1;
							}
						}
						else
						{
							DoWillyJump();
						}
					}
					else
					{
						if(input==5)
						{
							if(cWILLYd==0)
							{
								cWILLYd=1;
								cWILLYm=1;
								cWILLYj=0;
								cWILLYfall=0;
								cWILLYjs=0;

								if((CheckWillyConv()==1)&&(cCONVd==0))
								{
									cWILLYm=5;
									cCONVm=1;
								}

								DoWillyJump();
							}
							else
							{
								cWILLYm=2;
								cWILLYj=0;

								if((CheckWillyConv()==1)&&(cCONVd==0))
								{
									cWILLYm=5;
									cCONVm=1;
								}
								else
								{
									DoWillyLeft();
									DoWillyJump();
								}

								cWILLYfall=0;
								cWILLYjs=0;
							}
						}
						else
						{
							if(input==6)
							{
								if(cWILLYd==1)
								{
									cWILLYd=0;
									cWILLYm=1;
									cWILLYj=0;
									cWILLYfall=0;
									cWILLYjs=0;

									if((CheckWillyConv()==1)&&(cCONVd==1))
									{
										cWILLYm=5;
										cCONVm=1;
									}

									DoWillyJump();
								}
								else
								{
									cWILLYm=3;
									cWILLYj=0;


									if((CheckWillyConv()==1)&&(cCONVd==1))
									{
										cWILLYm=5;
										cCONVm=1;
									}
									else
									{
										DoWillyRight();
										DoWillyJump();
									}
									cWILLYfall=0;
									cWILLYjs=0;
								}
							}
							else
							{
								cWILLYfall=0;
								cWILLYjs=0;

								if(CheckWillyConv()!=0)
								{
									cWILLYm=5;
									cCONVm=0;
									DoOnConv(input);
								}
							}

						}
					}
				}
			}
			break;
//------------------------------------------------------------------------------
		case	1:
			DoWillyJump();
			break;
//------------------------------------------------------------------------------
		case	2:
			DoWillyLeft();
			DoWillyJump();
			break;
//------------------------------------------------------------------------------
		case	3:
			DoWillyRight();
			DoWillyJump();
			break;
//------------------------------------------------------------------------------
		case	4:
			DoWillyFall();
			break;
//------------------------------------------------------------------------------
		case	5:
			DoOnConv(input);
			break;
//------------------------------------------------------------------------------
		case	6:
			DoDeath();
			break;
	}
//------------------------------------------------------------------------------
	CheckKeys();
	CheckExit();
	CheckSwitches();
//------------------------------------------------------------------------------
	PutWilly();
	cWILLYxold[old]=cWILLYx&248;
	cWILLYyold[old]=cWILLYy;

}

///////////////////////////////////////////////////////////////
//	Do Willy Left
///////////////////////////////////////////////////////////////
void	DoWillyLeft(void)
{
	int	block1,block2,block3;

	if(cWILLYd==0)
	{
		cWILLYd=1;
	}
	else
	{
		cWILLYx-=2;

		block1=GetBlock(cWILLYx,cWILLYy);
		block2=GetBlock(cWILLYx,cWILLYy+8);
		block3=GetBlock(cWILLYx,cWILLYy+12);
		if((block1==3)||(block2==3)||(block3==3))
		{
			cWILLYx+=2;
		}

	}
}
///////////////////////////////////////////////////////////////
//	Do Willy Right
///////////////////////////////////////////////////////////////
void	DoWillyRight(void)
{
	int	block1,block2,block3;

	if(cWILLYd==1)
	{
		cWILLYd=0;
	}
	else
	{
		cWILLYx+=2;

		block1=GetBlock(cWILLYx+8,cWILLYy);
		block2=GetBlock(cWILLYx+8,cWILLYy+8);
		block3=GetBlock(cWILLYx+8,cWILLYy+12);
		if((block1==3)||(block2==3)||(block3==3))
		{
			cWILLYx-=2;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Willy Jump
///////////////////////////////////////////////////////////////
void	DoWillyJump(void)
{
	int	block1,block2;

	if(cWILLYj<8)
	{
		cWILLYy-=cWILLYjp[cWILLYj];

		block1=GetBlock(cWILLYx,cWILLYy);
		block2=GetBlock(cWILLYx+8,cWILLYy);
		if((block1==3)||(block2==3))
		{
			cWILLYjs=0;
			cWILLYm=4;
			//DoWillyFall();
			cWILLYy+=cWILLYjp[cWILLYj];
		}

	}
	else
	{
		if(cWILLYj>11)
		{
			if((cWILLYy&7)==0)
			{
				block1=GetBlock(cWILLYx,cWILLYy+16);
				block2=GetBlock(cWILLYx+8,cWILLYy+16);
				if((block1!=0)||(block2!=0))
				{
					cWILLYm=0;
					cWILLYy&=248;
					if((block1==7)||(block2==7))
					{
						if(cCONVd!=cWILLYd)
						{
							cWILLYm=5;
							cCONVm=0;
							cWILLYfall=0;
						}
					}
				}
				else
				{
					cWILLYy+=cWILLYjp[cWILLYj];
				}
			}
			else
			{
				cWILLYy+=cWILLYjp[cWILLYj];
			}

		}
		else
		{
			cWILLYy+=cWILLYjp[cWILLYj];
		}


		if(cWILLYj>12)
		{
			cWILLYfall+=cWILLYjp[cWILLYj];
		}
	}


	cWILLYj++;
	if(cWILLYj==18)
	{
		cWILLYm=0;
	}

	if(cWILLYj<11)
	{
		cWILLYjs++;
	}

	if(cWILLYj>10)
	{
		cWILLYjs--;
	}

	if(cWILLYy>104)
	{
		//cWILLYy=104;
		cWILLYm=4;
		DoWillyFall();
	}
	sfxLoadWAV(JUMP_WAVSize, JUMP_WAV,16384+(cWILLYjs*1500));
	//MIDASplaySample(wav,6,255,16384+(cWILLYjs*1500),64,MIDAS_PAN_MIDDLE);
}
///////////////////////////////////////////////////////////////
//	Check Fall
///////////////////////////////////////////////////////////////
void	CheckWillyFall(void)
{
	int	block1,block2;

	block1=GetBlock(cWILLYx,cWILLYy+16);
	block2=GetBlock(cWILLYx+8,cWILLYy+16);
	if((block1==0)&&(block2==0))
	{
		cWILLYjs=0;
		cWILLYm=4;
	}
	else
	{
		if((block1==5)||(block2==5)||(block1==6)||(block2==6))
		{
			cWILLYm=6;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Willy Fall
///////////////////////////////////////////////////////////////
void	DoWillyFall(void)
{
	int	block1,block2;

	cWILLYy+=4;
	cWILLYjs++;
	if(cWILLYjs>11)
		cWILLYjs=0;
	sfxLoadWAV(JUMP_WAVSize, JUMP_WAV,16384-(cWILLYjs*1000));
	//MIDASplaySample(wav,6,255,16384-(cWILLYjs*1000),64,MIDAS_PAN_MIDDLE);

	block1=GetBlock(cWILLYx,cWILLYy+16);
	block2=GetBlock(cWILLYx+8,cWILLYy+16);
	if((block1!=0)||(block2!=0))
	{
		cWILLYm=0;
		cWILLYy&=248;

		if(CheckWillyConv()==1)
		{
			cWILLYm=5;
			cCONVm=0;
		}
		if(cWILLYfall>=32)
			cWILLYm=6;
		else
			cWILLYfall=0;
	}
	else
	{
		cWILLYfall+=4;
	}

}
///////////////////////////////////////////////////////////////
//	Do Willy Normal
///////////////////////////////////////////////////////////////
void	PutWilly(void)
{
	if( cWILLYd )
	{
		GetWillyBG((cWILLYx&248),cWILLYy);
		if(DrawWILLY((cWILLYx&248),cWILLYy,((cWILLYx&15)>>1)+8)!=0)
			cWILLYm=6;
	}
	else
	{
		GetWillyBG((cWILLYx&248),cWILLYy);
		if(DrawWILLY((cWILLYx&248),cWILLYy,((cWILLYx&15)>>1)))
			cWILLYm=6;
	}


}
///////////////////////////////////////////////////////////////
//	Get Willy Input
///////////////////////////////////////////////////////////////
int	GetWillyInput(void)
{
	int	left=0;
	int	right=0;
	int	jump=0;

	if(	(KeyTable[key_q]==1) ||
		(KeyTable[key_e]==1) ||
		(KeyTable[key_t]==1) ||
		(KeyTable[key_u]==1) ||
		(KeyTable[key_o]==1) ||
		(KeyTable[key_n4]==1) ||
		(KeyTable[key_opensqu]==1) )
	{
		left=1;
	}

	if(	(KeyTable[key_tab]==1) ||
		(KeyTable[key_w]==1) ||
		(KeyTable[key_r]==1) ||
		(KeyTable[key_y]==1) ||
		(KeyTable[key_i]==1) ||
		(KeyTable[key_p]==1) ||
		(KeyTable[key_n6]==1) ||
		(KeyTable[key_closedsqu]==1) )
	{
		right=2;
	}

	if(	(KeyTable[key_leftshift]==1) ||
		(KeyTable[key_backslash]==1) ||
		(KeyTable[key_z]==1) ||
		(KeyTable[key_x]==1) ||
		(KeyTable[key_c]==1) ||
		(KeyTable[key_v]==1) ||
		(KeyTable[key_b]==1) ||
		(KeyTable[key_n]==1) ||
		(KeyTable[key_m]==1) ||
		(KeyTable[key_n8]==1) ||
		(KeyTable[key_comma]==1) ||
		(KeyTable[key_stop]==1) ||
		(KeyTable[key_fwdslash]==1) ||
		(KeyTable[key_rightshift]==1) ||
		(KeyTable[key_space]==1) )
	{
		jump=4;
	}


	return(left|right|jump);
}
///////////////////////////////////////////////////////////////
//	Get Block
///////////////////////////////////////////////////////////////
int	GetBlock(WORD x, WORD y)
{
	BYTE	data;

	data=cMAP[ (((y/8)*32)+(x/8)) ];
	return((int)data);
}
///////////////////////////////////////////////////////////////
//	Check Willy Against Kill Blocks
///////////////////////////////////////////////////////////////
int	CheckWillyKillBlock(void)
{
	int	block1,block2;
	int	block3,block4;
	int	block5,block6;
	int	hit;

	hit=0;

	block1=GetBlock(cWILLYx,cWILLYy);
	block2=GetBlock(cWILLYx+8,cWILLYy+8);
	block3=GetBlock(cWILLYx,cWILLYy+8);
	block4=GetBlock(cWILLYx+8,cWILLYy);
	block5=GetBlock(cWILLYx,cWILLYy+14);
	block6=GetBlock(cWILLYx+8,cWILLYy+14);

	if((block1==5)||(block2==5)||
		(block3==5)||(block4==5)||
		(block5==5)||(block6==5))
	{
		hit=1;
	}

	if((block1==6)||(block2==6)||
		(block3==6)||(block4==6)||
		(block5==6)||(block6==6))
	{
		hit=1;
	}

	return(hit);
}
///////////////////////////////////////////////////////////////
//	Check Keys
///////////////////////////////////////////////////////////////
void	CheckKeys(void)
{
	int	i,hit;

	hit=0;

	for(i=0;i<5;i++)
	{
		if(cKEYs[i]==1)
		{
			if((cKEYx[i]>=cWILLYx)&&(cKEYy[i]>=cWILLYy))
			{
				if( (cKEYx[i]<(cWILLYx+10))&&(cKEYy[i]<(cWILLYy+18)) )
				{
					cKEYs[i]=0;
					hit=1;
					SCORE+=100;
				}
			}

			if(((cKEYx[i]+7)>=cWILLYx)&&(cKEYy[i]>=cWILLYy))
			{
				if( ((cKEYx[i]+7)<(cWILLYx+10))&&(cKEYy[i]<(cWILLYy+18)) )
				{
					if(hit==0)
					{
						cKEYs[i]=0;
						SCORE+=100;
						hit=1;
					}
				}
			}

			if((cKEYx[i]>=cWILLYx)&&((cKEYy[i]+7)>=cWILLYy))
			{
				if( (cKEYx[i]<(cWILLYx+10))&&((cKEYy[i]+7)<(cWILLYy+18)) )
				{
					if(hit==0)
					{
						cKEYs[i]=0;
						SCORE+=100;
						hit=1;
					}
				}
			}

			if(((cKEYx[i]+7)>=cWILLYx)&&((cKEYy[i]+7)>=cWILLYy))
			{
				if( ((cKEYx[i]+7)<(cWILLYx+10))&&((cKEYy[i]+7)<(cWILLYy+18)) )
				{
					if(hit==0)
					{
						cKEYs[i]=0;
						SCORE+=100;
						hit=1;
					}
				}
			}

		}

	}

	if(hit==1) {
		sfxLoadWAV(PICK_WAVSize, PICK_WAV,22050);
		//MIDASplaySample(pick,8,300,22050,64,MIDAS_PAN_MIDDLE);
  }

}
///////////////////////////////////////////////////////////////
//	Check Switches
///////////////////////////////////////////////////////////////
void	CheckSwitches(void)
{
	int	i;

	for(i=0;i<2;i++)
	{
		if(cSWITCHs[i]==1)
		{
			if((cSWITCHx[i]+7>=cWILLYx)&&(cSWITCHy[i]+7>=cWILLYy)&&
				(cSWITCHx[i]<cWILLYx+8)&&(cSWITCHy[i]<cWILLYy+16))
			{
				cSWITCHs[i]=2;
			}
		}
	}

}
///////////////////////////////////////////////////////////////
//	Check Crumb
///////////////////////////////////////////////////////////////
void	CheckCrumb(void)
{
	int	block1;//,block2;

	block1=GetBlock(cWILLYx,cWILLYy+16);
	if(block1==4)
	{

		cCRUMB[(((cWILLYy+16)/8)*32)+(cWILLYx/8)]&=31;
		cCRUMB[(((cWILLYy+16)/8)*32)+(cWILLYx/8)]--;
		cCRUMB[(((cWILLYy+16)/8)*32)+(cWILLYx/8)]|=128;

		if(cCRUMB[(((cWILLYy+16)/8)*32)+(cWILLYx/8)]==128)
		{
			cMAP[(((cWILLYy+16)/8)*32)+(cWILLYx/8)]=0;
		}
		else
		{
		}

	}


	block1=GetBlock(cWILLYx+8,cWILLYy+16);
	if(block1==4)
	{
		cCRUMB[(((cWILLYy+16)/8)*32)+((cWILLYx+8)/8)]&=31;
		cCRUMB[(((cWILLYy+16)/8)*32)+((cWILLYx+8)/8)]--;
		cCRUMB[(((cWILLYy+16)/8)*32)+((cWILLYx+8)/8)]|=128;

		if(cCRUMB[(((cWILLYy+16)/8)*32)+((cWILLYx+8)/8)]==128)
		{
			cMAP[(((cWILLYy+16)/8)*32)+((cWILLYx+8)/8)]=0;
		}
		else
		{
		}

	}

}
///////////////////////////////////////////////////////////////
//	Do Crumb
///////////////////////////////////////////////////////////////
void	DoCrumb(void)
{
	int	x,y,dx,dy,doff;
	int	cx,cy;
	WORD	block2;
	BYTE	data,data2;

	for(y=0;y<16;y++)
	{
		for(x=0;x<32;x++)
		{
			data=cCRUMB[(y*32)+x];

			if(((data&128)==128)||((data&64)==64))
			{
				for(dy=0;dy<(8-(data&31));dy++)
				{
					for(dx=0;dx<8;dx++)
					{
						PlotPixel((x*8)+dx,(y*8)+dy,cBGpaper);
					}
				}

				dx=x*8;
				dy=y*8;

				block2=(WORD)cCRUMBgfx;
				block2*=64;
				doff=8-(data&31);

				for(cy=0;cy<(data&31);cy++)
				{
					for(cx=0;cx<8;cx++)
					{
						data2=GFXblocks[block2];

						if(!data2)
							PlotPixel(dx+cx,(dy+doff)+cy,cBGpaper);
						else
							PlotPixel(dx+cx,(dy+doff)+cy,data2+(cCRUMBink*16));

						block2++;
					}
				}
				if((data&128)==128)
				{
					cCRUMB[(y*32)+x]&=31;
					cCRUMB[(y*32)+x]|=64;
				}
				else
				{
					if((data&64)==64)
					{
						cCRUMB[(y*32)+x]&=31;
					}
				}

			}
			else
			{
			}
		}
	}
}
///////////////////////////////////////////////////////////////
//	Check Exit
///////////////////////////////////////////////////////////////
void	CheckExit(void)
{


	if(cEXITm==1)
	{
		if(((cWILLYx+4)>cEXITx)&&((cWILLYy+8)>cEXITy))
		{
			if( ((cWILLYx+4)<(cEXITx+16))&&((cWILLYy+8)<(cEXITy+16)) )
			{
				GAMEm=3;
			}
		}


		if( ((cWILLYx+5)>cEXITx)&&((cWILLYy+8)>cEXITy) )
		{
			if(((cWILLYx+5)<(cEXITx+16))&&((cWILLYy+8)<(cEXITy+16)))
			{
				GAMEm=3;
			}
		}


		if( ((cWILLYx+4)>cEXITx)&&((cWILLYy+9)>cEXITy) )
		{
			if(((cWILLYx+4)<(cEXITx+16))&&((cWILLYy+9)<(cEXITy+16)))
			{
				GAMEm=3;
			}
		}

		if(((cWILLYx+5)>cEXITx)&&((cWILLYy+9)>cEXITy))
		{
			if(((cWILLYx+5)<(cEXITx+16))&&((cWILLYy+9)<(cEXITy+16)))
			{
				GAMEm=3;
			}
		}

	}

	if(((LEVEL==19)||(LEVEL==39))&&(GAMEm==3))
	{
		if(CHEAT!=1)
		{
			GAMEm=5;
			LASTm=0;
			LASTc=0;
			LASTp=0;
			TEXTm=0;
			TEXTink=7;
			TEXTfade=0;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Check if on CONV
///////////////////////////////////////////////////////////////
int	CheckWillyConv(void)
{
	int	block1,block2;

	block1=GetBlock(cWILLYx,cWILLYy+16);
	block2=GetBlock(cWILLYx+8,cWILLYy+16);
	if((block1==7)||(block2==7))
	{
		return(1);
	}

	return(0);
}

///////////////////////////////////////////////////////////////
//	Do On Conv
///////////////////////////////////////////////////////////////
void	DoOnConv(int input)
{
	switch(cCONVd)
	{
		case	0:
			DoConvLeft(input);
			break;
		case	1:
			DoConvRight(input);
			break;
	}

}
///////////////////////////////////////////////////////////////
//	On Convayor going Left
//
//	0=walking/check input
//	1=jump up
//	2=jump left
//
///////////////////////////////////////////////////////////////
void	DoConvLeft(int input)
{
	switch( cCONVm)
	{
//------------------------------------------------------------------------------
		case	0:
			if(input==4)
			{
				cCONVm=2;
				cWILLYj=0;
				cWILLYfall=0;
				cWILLYjs=0;
				DoWillyLeftConv();
				DoWillyJumpConv();
			}
			else
			{
				if(input==5)
				{
					cCONVm=2;
					cWILLYj=0;
					cWILLYjs=0;
					DoWillyLeftConv();
					DoWillyJumpConv();
					cWILLYfall=0;
				}
				else
				{
					if(input==6)
					{
						cCONVm=2;
						cWILLYj=0;
						cWILLYjs=0;
						DoWillyLeftConv();
						DoWillyJumpConv();
						cWILLYfall=0;
					}
					else
					{
						cWILLYfall=0;
						cWILLYjs=0;
						if(CheckWillyConv()==0)
						{
							cWILLYm=0;
						}
						else
						{
							DoWillyLeftConv();
							if(CheckWillyConv()==0)
								cWILLYm=0;
						}
					}
				}
			}
			break;
//------------------------------------------------------------------------------
		case	1:
			DoWillyJumpConv();
			break;
//------------------------------------------------------------------------------
		case	2:
			DoWillyLeftConv();
			DoWillyJumpConv();
			break;

		}
}

///////////////////////////////////////////////////////////////
//	On Convayor going Right
//
//	0=walking/check input
//	1=jump up
//	2=jump right
//
///////////////////////////////////////////////////////////////
void	DoConvRight(int input)
{
	switch( cCONVm)
	{
//------------------------------------------------------------------------------
		case	0:
			if(input==4)
			{
				cCONVm=2;
				cWILLYj=0;
				cWILLYjs=0;
				cWILLYfall=0;
				DoWillyRightConv();
				DoWillyJumpConv();
			}
			else
			{
				if(input==5)
				{
					cCONVm=2;
					cWILLYj=0;
					DoWillyRightConv();
					DoWillyJumpConv();
					cWILLYfall=0;
				}
				else
				{
					if(input==6)
					{
						cCONVm=2;
						cWILLYj=0;
						cWILLYjs=0;
						DoWillyRightConv();
						DoWillyJumpConv();
						cWILLYfall=0;
					}
					else
					{
						cWILLYfall=0;
						if(CheckWillyConv()==0)
						{
							cWILLYm=0;
						}
						else
						{
							DoWillyRightConv();
							if(CheckWillyConv()==0)
								cWILLYm=0;
						}
					}
				}
			}
			break;
//------------------------------------------------------------------------------
		case	1:
			DoWillyJumpConv();
			break;
//------------------------------------------------------------------------------
		case	2:
			DoWillyRightConv();
			DoWillyJumpConv();
			break;

		}
}
///////////////////////////////////////////////////////////////
//	Do Willy Left
///////////////////////////////////////////////////////////////
void	DoWillyLeftConv(void)
{
	int	block1,block2,block3;

	if(cWILLYd==0)
	{
		cWILLYd=1;
	}
	else
	{
		cWILLYx-=2;

		block1=GetBlock(cWILLYx,cWILLYy);
		block2=GetBlock(cWILLYx,cWILLYy+8);
		block3=GetBlock(cWILLYx,cWILLYy+12);
		if((block1==3)||(block2==3)||(block3==3))
		{
			cWILLYx+=2;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Willy Right
///////////////////////////////////////////////////////////////
void	DoWillyRightConv(void)
{
	int	block1,block2,block3;

	if(cWILLYd==1)
	{
		cWILLYd=0;
	}
	else
	{
		cWILLYx+=2;

		block1=GetBlock(cWILLYx+8,cWILLYy);
		block2=GetBlock(cWILLYx+8,cWILLYy+8);
		block3=GetBlock(cWILLYx+8,cWILLYy+12);
		if((block1==3)||(block2==3)||(block3==3))
		{
			cWILLYx-=2;
		}
	}
}
///////////////////////////////////////////////////////////////
//	Do Willy Jump
///////////////////////////////////////////////////////////////
void	DoWillyJumpConv(void)
{
	int	block1,block2;

	if(cWILLYj<8)
	{
		cWILLYy-=cWILLYjp[cWILLYj];

		block1=GetBlock(cWILLYx,cWILLYy);
		block2=GetBlock(cWILLYx+8,cWILLYy);
		if((block1==3)||(block2==3))
		{
			cWILLYjs=0;
			cWILLYm=4;
			//DoWillyFall();
			cWILLYy+=cWILLYjp[cWILLYj];
		}
	}
	else
	{

		if(cWILLYj>11)
		{
			if((cWILLYy&7)==0)
			{
				block1=GetBlock(cWILLYx,cWILLYy+16);
				block2=GetBlock(cWILLYx+8,cWILLYy+16);
				if((block1!=0)||(block2!=0))
				{
					cWILLYm=0;
					cWILLYy&=248;

					if((block1==7)||(block2==7))
					{
						cWILLYm=5;
						cCONVm=0;
						cWILLYy&=248;
					}
				}
				else
				{
					cWILLYy+=cWILLYjp[cWILLYj];
				}
			}
			else
			{
				cWILLYy+=cWILLYjp[cWILLYj];
			}

		}
		else
		{
			cWILLYy+=cWILLYjp[cWILLYj];
		}


		if(cWILLYj>12)
		{
			cWILLYfall+=cWILLYjp[cWILLYj];
		}
	}

	cWILLYj++;
	if(cWILLYj==18)
	{
		if(CheckWillyConv()==0)
		{
			cWILLYm=0;
		}
		else
		{
			cCONVm=0;
		}

       }

	if(cWILLYj<11)
	{
		cWILLYjs++;
	}

	if(cWILLYj>10)
	{
		cWILLYjs--;
	}

	if(cWILLYy>104)
	{
		//cWILLYy=104;
		cWILLYm=4;
		DoWillyFall();
	}
	sfxLoadWAV(JUMP_WAVSize, JUMP_WAV,16384+(cWILLYjs*1500));
	//MIDASplaySample(wav,6,255,16384+(cWILLYjs*1500),64,MIDAS_PAN_MIDDLE);

}


///////////////////////////////////////////////////////////////
//	Do Death
///////////////////////////////////////////////////////////////
void	DoDeath(void)
{
	GAMEm=2;
	DEATHm=0;
	DEATHc=0;

	sfxLoadWAV(DIE_WAVSize, DIE_WAV,22050);
	//MIDASplaySample(die,7,512,22050,64,MIDAS_PAN_MIDDLE);
}

///////////////////////////////////////////////////////////////
//	Clear Willy Collision
///////////////////////////////////////////////////////////////
void	ClearWillyCol(void)
{
	int	count1,count2;

	for(count1=0;count1<128;count1++)
	{
		for(count2=0;count2<256;count2++)
		{
			cWILLYcol[count1][count2]=0;
		}
	}
}
