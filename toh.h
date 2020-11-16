#include<how.h>
#include<about.h>
#include<logo.h>
#include<lvlinfo.h>
#define true 1
#define false 0

/*============================================================================*/
/*============================ FUNCTION PROTOTYPE ============================*/
/*============================================================================*/
void gamemenu();
void playgame();
int calldisk3();
int calldisk4();
void howtoplay();
void tohinfo();
void exitpage();
void clear();
void levelinfo(int l);
void wrong(int mod,int disknum);
void loss(int count);
void color(int a,int b,int c,int d,int e);
int erase(int f,int g,int h,int i);
int mode(int lvl);

//Global Variables
int count,x,y,x1,y1;
int Xpos,Ypos,button,I,p=1,z;
char mod,c;

/*============================================================================*/
/*============================== MOUSE FUNCTION ==============================*/
/*============================================================================*/
/*SHOW MOUSE*/
void showmouse()	{
	union REGS in ,out;		//in values doing into call & out values into return
	in.x.ax=1;				//set BIOS function number
	int86(0x33,&in,&out);	//set video mode and clearscreen
}


/*HIDE MOUSE*/
void hidemouse()	{
	union REGS in ,out;
	in.x.ax=2;
	int86(0x33,&in,&out);
}


/*MOUSE INFORMATION*/
void mouseInfo(int*button,int*Xpos,int*Ypos)	{
	union REGS in ,out;
	in.x.ax=3;
	int86(0x33,&in,&out);
	*Xpos=out.x.cx;			//set video mode number
	*Ypos=out.x.dx;
	*button=out.x.bx;
}

/*============================================================================*/
/*============================= GRAPHICS DRIVER ==============================*/
/*============================================================================*/

/*GRAPHICS DRIVER FUNCTION*/
int graphicsdriver()	{
 	int gd=DETECT,gm,check,graphok=0;
 	initgraph(&gd,&gm,"c://tc//BGI");
 	check=graphresult();
 	
	 if(check != graphok)	{
 		printf("Graphics Error %s",grapherrormsg(check));
 		getch();
 		exit(1);
 	}
 	return 0;
}

/*============================================================================*/
/*================================ GAME MENU =================================*/
/*============================================================================*/
void gamemenu()	{
	cleardevice();
	
 	setcolor(12);
  	settextstyle(DEFAULT_FONT,0,4);
  	outtextxy(75,50,"TOWER OF HANOI ");
  	
  	logo();	//Function call in logo.h
  	
  	setcolor(12);
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  	rectangle(10,120,200,180);
  	outtextxy(60,140,"PLAY");
  	
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  	rectangle(10,200,200,260);
  	outtextxy(19,225,"INSTRUCTION");
  	
 	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	rectangle(10,280,200,340);
  	outtextxy(50,300,"ABOUT");
  	
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  	setcolor(4);
    outtextxy(460,460,"EXIT = [Esc]");
  	
  	showmouse();
	
	c=0;
	while(true)	{
		if(kbhit()){
  			c=getch();
  			if(c==27)	{
				exitpage();
			}
  		}
 		mouseInfo(&button, &Xpos, &Ypos);
 		//Click position for PLAY
		if((Xpos>0 && Xpos<200)&& (Ypos>120 && Ypos<180))	{
			if(1==(button&1))	{
 				cleardevice();
 				playgame();
 				break;
 			}
		}
		//Click position for INSTRUCTION
  		else if((Xpos>0 && Xpos<200)&& (Ypos>200 && Ypos<260))	{
  			if(1==(button&1))	{
  				hidemouse();
 				cleardevice();
 				howtoplay();
 				gamemenu();
 				break;
 			}
		}
		//Click position for ABOUT
  		else if((Xpos>0 && Xpos<200)&& (Ypos>280 && Ypos<340))	{
 			if(1==(button&1))	{
 				hidemouse();
				cleardevice();
 				tohinfo();
 				gamemenu();
 				break;
 			}
		}
 	}
}

/*============================================================================*/
/*============================= DISK SELECTION ===============================*/
/*============================================================================*/
 void playgame()	{
 	hidemouse();
 	
	setcolor(12);
  	settextstyle(DEFAULT_FONT,0,4);
  	outtextxy(75,50,"TOWER OF HANOI ");
  	
	setcolor(3);
 	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  	outtextxy(20,190,"SELECT NUMBER OF DISK.");
  	
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  	rectangle(10,200,200,260);
  	outtextxy(40,225,"3 DISK");
	rectangle(10,280,200,340);
  	outtextxy(40,300,"4 DISK");
  	
  	logo();
  	
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  	setcolor(4);
  	outtextxy(300,400,"PRESS ANY KEY TO ENABLE MOUSE");
  	getch();
  	showmouse();
  	//CLEAR "PRESS ANY KEY TO ENABLE MOUSE"
	setcolor(0);
	outtextxy(300,400,"PRESS ANY KEY TO ENABLE MOUSE");
	
	setcolor(4);
   	outtextxy(460,460,"EXIT = [Esc]");
   	outtextxy(250,460,"MAIN MENU = [Backspace]");
	
	c=0;
	while(c!=27)	{
		
		if(kbhit()){
  			c=getch();
  			if(c==27)	{
				exitpage();
			}
			else if(c==8)	{
    			gamemenu();
			}
  		}
  		
 		mouseInfo(&button, &Xpos, &Ypos);
		//Click position for 3 DISK
  		if((Xpos>0 && Xpos<200)&& (Ypos>200 && Ypos<260))	{
  			if(1==(button&1))	{
 				cleardevice();
 				calldisk3();
 				break;
 			}
		}
		
		else if((Xpos>0 && Xpos<200)&& (Ypos>280 && Ypos<340))	{
			if(1==(button&1))	{
 				cleardevice();
 				calldisk4();
 				break;
 			}
 		}
	}
}

/*============================================================================*/
/*================================== LEVEL ===================================*/
/*============================================================================*/
int mode(int lvl){
	hidemouse();
	levelinfo(lvl);	//function call for lvlinfo.h
	
	c=0;
	while(true)	{
 		if(kbhit()){
  			c=getch();
			if(c==8)	{
    			gamemenu();
			}
  		}
  		
 		else if(c == 'v' || c == 'V' || c == 'n' || c == 'N'|| c == 'e' || c == 'E')
 		{
  			break;
 		}
	}

 return c;
}


/*============================================================================*/
/*========================= MOVED DISK FILL & COLOR===========================*/
/*============================================================================*/
void color(int x,int y,int x1,int y1,int n)	{
  	setcolor(n);
  	
  	y1-=1;
	while(x!=(x1+1))	{
   		line(x,y,x,y1);
    	x++;
   	}
}


/*============================================================================*/
/*=========================== ERASE SELECTED DISK ============================*/
/*============================================================================*/
int erase(int x1,int y1,int x2,int y2)	{
 	setcolor(0);
 	y2-=1;
	 while(x1!=(x2+1))	{
 		line(x1,y1,x1,y2);
 		x1++;
  	}
  return 0;
}

/*============================================================================*/
/*========================== CLEAR POPUP MESSAGE =============================*/
/*============================================================================*/
void clear()	{
	//REMOVE FOOTER MESSAGE
  	setcolor(8);
	rectangle(205,440,620,478);
  	x=206,y=441,x1=619,y1=441;
 	while(y1!=478)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
  	//REMOVE WRONG MOVE MESSAGE
  	setcolor(0);
	outtextxy(250,250,"WRONG MOVE!!!");	
}


/*============================================================================*/
/*============================== WRONG ATTEMPt ================================*/
/*============================================================================*/
void wrong(int mod,int disknum)	{
		
		setcolor(4);
	    sound(200);
	    outtextxy(250,250,"WRONG MOVE!!!");
	    //CLEAR COUNTS
		setcolor(12);
		rectangle(130,440,150,478);
  		x=131,y=441,x1=149,y1=441;
 		while(y1!=478)	{
  			line(x,y,x1,y1);
  			y++,y1++;
  		}
	    count++;
	    //REPLACE WRONG ATTEMPT COUNT
	    char cnt[10];
	    sprintf(cnt,"%d",count);
	    setcolor(15);
  		moveto(130,460);
		outtext(cnt);
	    nosound();
	    //Condition for loss Function in 3 DISK 	
	    if(disknum==3)	{
		 	if(mod=='v' || mod=='V')	{
		 		if(count>=1)	{
		 			clear();
		 			setcolor(4);
  					rectangle(190,245,420,265);
					outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
					getch();
		 			loss(count);
				 }	
			 }
	      	else if(mod=='n' || mod=='N')	{
	      		if(count>=2)	{
	      			clear();
	      			setcolor(4);
  					rectangle(190,245,420,265);
					outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
					getch();
	      			loss(count);
				  }
			  }
	     	else if(mod=='e' || mod=='E')	{
	     		if(count>=4)	{
	     			clear();
	     			setcolor(4);
  					rectangle(190,245,420,265);
					outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
					getch();
	     			loss(count);
				 }
			 }
		}
		//Condition for loss Function in 4 DISK
		else if(disknum==4)	{
		 	if(mod=='v' || mod=='V')	{
		 		if(count>=3)	{
		 			clear();
		 			setcolor(4);
  					rectangle(190,245,420,265);
					outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
					getch();
		 			loss(count);
				 }	
			 }
	      	else if(mod=='n' || mod=='N')	{
	      		if(count>=5)	{
	      			clear();
	      			setcolor(4);
  					rectangle(190,245,420,265);
					outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
					getch();
	      			loss(count);
				  }
			  }
	     	else if(mod=='e' || mod=='E')	{
	     		if(count>=8)	{
	     			clear();
	     			setcolor(4);
  					rectangle(190,245,420,265);
					outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
					getch();
	     			loss(count);
				 }
			 }
		}
}

 
/*============================================================================*/
/*=========================== WIN & LOSE DISPLAY =============================*/
/*============================================================================*/
void winpanel()	{
	logo();	//Function call for logo.h
	
  	//LIGHT RED PANEL
	setcolor(12);
	rectangle(20,120,200,180);
  	x=21,y=121,x1=199,y1=121;
 	while(y1!=180)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(15);
  	settextstyle(0,0,3);
  	outtextxy(40,140,"RESULT");
  	
  	//GRAY PANEL
  	setcolor(8);
	rectangle(20,180,200,330);
  	x=21,y=181,x1=199,y1=181;
 	while(y1!=330)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	
  	settextstyle(0,0,1);
  	setcolor(12);
  	outtextxy(50,200,"WRONG ATTEMPTS");
  	
  	
  	settextstyle(0,0,1);
  	setcolor(4);
  	outtextxy(50,350,"PRESS ANY KEY");
}

char cnt[10];
void perfectwin(int count)	{
	cleardevice();
	winpanel();
	
	setcolor(14);
	rectangle(250,40,600,100);
	settextstyle(DEFAULT_FONT,0,6);
  	outtextxy(262,50,"PERFECT");
	
	setcolor(4);
	settextstyle(0,0,5);
	sprintf(cnt,"%d",count);
  	moveto(90,220);
	outtext(cnt);
  	
	setcolor(14);
  	settextstyle(1,0,1);
  	outtextxy(30,280,"CONGRATULATIONS!");
	
	getch();
	gamemenu();
}


/*WIN*/
void win(int count)	{
	cleardevice();
	winpanel();
	
	setcolor(14);
	rectangle(250,40,600,100);
	settextstyle(DEFAULT_FONT,0,6);
  	outtextxy(262,50,"YOU WIN");
  	
  	setcolor(4);
	settextstyle(0,0,5);
	sprintf(cnt,"%d",count);
  	moveto(90,220);
	outtext(cnt);
  	
	setcolor(14);
  	settextstyle(1,0,1);
  	outtextxy(60,280,"GOOD GAME !");
  	
  	getch();
  	gamemenu();
}


/*LOST*/
void loss(int count)	{
	cleardevice();
	winpanel();

	setcolor(4);
	rectangle(250,40,600,100);
	settextstyle(DEFAULT_FONT,0,4);
  	outtextxy(280,55,"GAME OVER");
  	
	sprintf(cnt,"%d",count);
  	moveto(90,220);
	outtext(cnt);
  	
	setcolor(2);
	settextstyle(0,0,1);
  	outtextxy(30,280,"  TOO MANY WRONG");
	outtextxy(30,300,"ATTEMPTS,TRY AGAIN!");
  	
  	getch();
  	gamemenu();
}

/*============================================================================*/
/*================================ EXIT GAME =================================*/
/*============================================================================*/
void exitpage()		{
	cleardevice();
	
	setcolor(8);
	rectangle(160,80,520,160);
	settextstyle(0,0,6);
  	outtextxy(180,100,"LEAVING");
	
	setcolor(15);
	settextstyle(0,0,1);
	outtextxy(305,70,"BSCS12A: HERNANDEZ & RAMOS ");
	
	//LOADING BAR
  	int x=180,y=220,x1=200,y1=220;
  	while(x1<=500)	{
  		sound(x1);
   		delay(50);
   		settextstyle(0,0,2);
		for(int ctr=1;ctr<40;ctr++)	{
   			setcolor(15);
			line(x,y+ctr,x1,y1+ctr);
			setcolor(0);	
  			outtextxy(250,230,"THANK YOU !!!");
   		}
   		x+=5,x1+=5;
  	}
  	delay(200);
  	nosound(); 
	getch();
  	closegraph();
  	clrscr();
	exit(true);
}


/*============================================================================*/
/*============================ IN GAME FUNCTION ==============================*/
/*============================================================================*/


int calldisk3()	{
	short int mod;
	mod=mode(3);
	cleardevice();
	
	int x,y,x1,y1,m,disknum=3;
	//HEADER
	setcolor(8);
	rectangle(115,30,500,80);
  	x=116,y=31,x1=499,y1=31;
 	while(y1!=80)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	
	setcolor(12);
  	settextstyle(0,0,3);
  	outtextxy(140,45,"TOWER OF HANOI ");
   	
	settextstyle(0,0,1);
   	setcolor(8);
	if(mod=='v' || mod=='V')	{
		m=1;
		outtextxy(400,90,"VETERAN MODE");
	}
   	else if(mod=='E' || mod=='e')	{
   		m=4;
		outtextxy(400,90,"EASY MODE");
	   }
   	else if(mod=='n' || mod=='N')	{
   		m=2;
		outtextxy(400,90,"NORMAL MODE");
	   }
   	
	//BASE A or SOURCE
  	setcolor(15);
  	//rod
	rectangle(67,100,77,220);
	x=68,y=101,x1=76,y1=101;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
	//base
	rectangle(0,200,140,220);
	x=1,y=201,x1=139,y1=201;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(3);
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(68,207,"A");
  	
  	//BASE B or TEMPORARY
  	setcolor(15);
  	//rod
	rectangle(538,100,548,220);
	x=539,y=101,x1=547,y1=101;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
	//base
	rectangle(470,200,610,220);
	x=471,y=201,x1=609,y1=201;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(3);
  	outtextxy(540,207,"B");
  	
  	//BASE C or DESTINATION
	setcolor(15);
  	//rod
	rectangle(293,300,303,420);
	x=294,y=301,x1=302,y1=301;
  	while(y1!=420)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
	//base
	rectangle(225,400,370,420);
	x=226,y=401,x1=369,y1=401;
  	while(y1!=420)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(3);
  	outtextxy(295,405,"C");
	
	//RED DISK
	setcolor(12);
	rectangle(10,190,130,199);
   	x=11,y=191,x1=130,y1=191;///x1 will be constant
  	while(y1!=199)	{
   		line(x,y,x1,y1);
   		y++,y1++;
   	}
   	//GREEN DISK
	setcolor(10);
	rectangle(20,180,125,189);
  	x=21,y=181,x1=125,y1=181;
	while(y1!=189)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	//BLUE DISK
	setcolor(3);
	rectangle(30,170,115,179);
  	x=31,y=171,x1=115,y1=171;
  	while(y1!=179)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	
  	//FOOTER
	setcolor(12);
	rectangle(0,440,150,478);
  	x=0,y=441,x1=149,y1=441;
 	while(y1!=478)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(8);
	rectangle(150,440,620,478);
  	x=151,y=441,x1=619,y1=441;
 	while(y1!=478)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	
  	count=0;
  	setcolor(15);
  	moveto(20,460);
	outtext("WRONG ATTEMPT:");
	outtextxy(170,460,"TIP:");
	showmouse();

/*=========1st MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
		mouseInfo(&button, &Xpos, &Ypos);
		 
 		if((Xpos>30 && Xpos<115)&& (Ypos>170 && Ypos<180))if(1==(button&1))	{
 			clear();
 			setcolor(15);
 			outtextxy(205,460,"NOW CLICK ON BASE.");
  			break;
 		}
	}
	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		 if((Xpos>258 && Xpos<342)&&(Ypos>390 && Ypos<400))	{
		 	if(1==(button&1))	{
	  			hidemouse();
				color(258,390,342,400,3);
		  		erase(30,170,115,180);
				//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,180);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=180)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		  	}
	 	}
	   
		//WRONG ATTEMPT
	 	if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			if(1==(button&1))	{
		    	delay(200);
		    	wrong(mod,disknum);
		 	}
		}
  	}
	clear();
	showmouse();

/*=========2nd MOVE=========*/
	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");
   	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
 
 		if((Xpos>20 && Xpos<125)&& (Ypos>180 && Ypos<190))if(1==(button&1))	{
			clear();
 			setcolor(15);
 			outtextxy(205,460,"NOW CLICK ON BASE.");
  			break;
 		}
  	}
  	
  	while(count!=m)	{
		mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>488 && Xpos<592)&&(Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(488,190,592,200,10);
		  		erase(20,180,125,190);
		  		//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,190);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=190)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		 	 	break;
		 	}
	 	}
	 	
	 	//WRONG ATTEMPT
		if((Xpos>238 && Xpos<362)&&(Ypos>300 && Ypos<400))	{
			if(1==(button&1))	{
		    	delay(200);
		    	wrong(mod,disknum);
		  	}
		}
  	}
  	clear();
	showmouse();

/*=========3rd MOVE=========*/
	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
 		
		if((Xpos>256 && Xpos<342)&& (Ypos>390 && Ypos<400))	{
			if(1==(button&1))	{
 				clear();
 				setcolor(15);
 				outtextxy(205,460,"NOW CLICK ON BASE.");
  				break;
 			}
 		}
  	}
  	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>498 && Xpos<582)&&(Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(498,180,582,190,3);
		  		erase(258,390,342,400);
	  			//BASE C rod
				setcolor(15);
				rectangle(293,300,303,400);
				x=294,y=301,x1=302,y1=301;
	  			while(y1!=400)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
	 	}
	 	
	 	//WRONG ATTEMPT
	 	if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))	{
			 if(1==(button&1))	{
				delay(200);
		   		wrong(mod,disknum);
		 	}
		}
  	}
	clear();
	showmouse();

/*=========4th MOVE=========*/
	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");

	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    	
 		if((Xpos>10 && Xpos<130)&& (Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
	 			clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  		break;
	 		}
	 	}
  	}
  	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>238 && Xpos<362)&&(Ypos>390 && Ypos<400))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(238,390,362,400,12);
		  		erase(10,130,190,200);
		   		//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,200);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	  	
	  	//WRONG ATTEMPT
 		if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			 if(1==(button&1))	{
				delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
  	clear();
	showmouse();

/*=========5th MOVE=========*/
 	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    	
		if((Xpos>498 && Xpos<582)&& (Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  		break;
	 		}
	  	}
	}
  	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
	 	if((Xpos>30 && Xpos<115)&&(Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(30,190,115,200,3);
		  		erase(498,180,582,190);
				//BASE B rod
				setcolor(15);
				rectangle(538,100,548,190);
				x=539,y=101,x1=547,y1=101;
	  			while(y1!=190)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
		
	 	//WRONG ATTEMPT
		if((Xpos>238 && Xpos<362)&&(Ypos>300 && Ypos<400))	{
			if(1==(button&1))	{
		      	delay(200);
		     	wrong(mod,disknum);
		  }
	  	}
	}
  	clear();
	showmouse();

/*=========6th MOVE=========*/
	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");
   	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
 
 		if((Xpos>488 && Xpos<592)&& (Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
	 			clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
	 	}
	}
 	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    	
    	if((Xpos>248 && Xpos<352)&&(Ypos>380 && Ypos<390))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(248,380,352,390,10);
				erase(488,190,592,200);
		 		///BASE B rod
				setcolor(15);
				rectangle(538,100,548,200);
				x=539,y=101,x1=547,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
			}
		}
	
		//WRONG ATTEMPT
		if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))	{
			if(1==(button&1))	{
				delay(200);
		   		wrong(mod,disknum);
			}
	  	}
	}
  clear();
  showmouse();

/*=========7th MOVE=========*/
	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    	
		if((Xpos>30 && Xpos<115)&& (Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
	  	}
	}
  	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>258 && Xpos<342)&&(Ypos>370 && Ypos<380))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(258,370,342,380,3);
		  		erase(30,190,115,200);
		  		//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,200);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}

	  	//WRONG ATTEMPT
		if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			if(1==(button&1))	{
				delay(200);
		   		wrong(mod,disknum);
			}
	  	}
	}
  	
  	setcolor(4);
  	rectangle(190,245,420,265);
	outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
	int ctr=1;
	getch();
  	if(ctr==1)	{
  		if(count==0)	{
  			perfectwin(count);
		  }
  		else if(count<m)	{
  			win(count);
		  }
	  }
   
   return 0;
  }





///page for 4 disc////
int calldisk4(){
	short int mod;
	mod=mode(4);
	cleardevice();
	
	int x,y,x1,y1,m,disknum=4;
	//HEADER
	setcolor(8);
	rectangle(115,30,500,80);
  	x=116,y=31,x1=499,y1=31;
 	while(y1!=80)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	
	setcolor(12);
  	settextstyle(0,0,3);
  	outtextxy(140,45,"TOWER OF HANOI ");
   	
	settextstyle(0,0,1);
   	setcolor(8);
	if(mod=='v' || mod=='V')	{
		m=3;
		outtextxy(400,90,"VETERAN MODE");
	}
   	else if(mod=='E' || mod=='e')	{
   		m=8;
		outtextxy(400,90,"EASY MODE");
	   }
   	else if(mod=='n' || mod=='N')	{
   		m=5;
		outtextxy(400,90,"NORMAL MODE");
	   }
   	
	//BASE A or SOURCE
  	setcolor(15);
  	//rod
	rectangle(67,100,77,220);
	x=68,y=101,x1=76,y1=101;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
	//base
	rectangle(0,200,140,220);
	x=1,y=201,x1=139,y1=201;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(3);
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(68,207,"A");
  	
  	//BASE B or TEMPORARY
  	setcolor(15);
  	//rod
	rectangle(538,100,548,220);
	x=539,y=101,x1=547,y1=101;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
	//base
	rectangle(470,200,610,220);
	x=471,y=201,x1=609,y1=201;
  	while(y1!=220)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(3);
  	outtextxy(540,207,"B");
  	
  	//BASE C or DESTINATION
	setcolor(15);
  	//rod
	rectangle(293,300,303,420);
	x=294,y=301,x1=302,y1=301;
  	while(y1!=420)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
	//base
	rectangle(225,400,370,420);
	x=226,y=401,x1=369,y1=401;
  	while(y1!=420)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(3);
  	outtextxy(295,405,"C");
	
	//RED DISK
	setcolor(12);
	rectangle(10,190,130,199);
   	x=11,y=191,x1=130,y1=191;
  	while(y1!=199)	{
   		line(x,y,x1,y1);
   		y++,y1++;
   	}
   	//GREEN DISK
	setcolor(10);
	rectangle(20,180,125,189);
  	x=21,y=181,x1=125,y1=181;
	while(y1!=189)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	//BLUE DISK
	setcolor(3);
	rectangle(30,170,115,179);
  	x=31,y=171,x1=115,y1=171;
  	while(y1!=179)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	//YELLOW DISK
	setcolor(14);
	rectangle(40,160,105,169);
  	x=41,y=161,x1=105,y1=161;
  	while(y1!=169)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	//FOOTER
	setcolor(12);
	rectangle(0,440,150,478);
  	x=0,y=441,x1=149,y1=441;
 	while(y1!=478)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
  	setcolor(8);
	rectangle(150,440,620,478);
  	x=151,y=441,x1=619,y1=441;
 	while(y1!=478)	{
  		line(x,y,x1,y1);
  		y++,y1++;
  	}
	
	count=0;
  	setcolor(15);
  	moveto(20,460);
	outtext("WRONG ATTEMPT:");
	outtextxy(170,460,"TIP:");
	showmouse();


/*=========1st MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);

		if((Xpos>40 && Xpos<160)&& (Ypos>105 && Ypos<170))	{
			if(1==(button&1))	{
	 			clear();
				setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
	  	}
	}
	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    	
    	if((Xpos>508 && Xpos<572)&&(Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
				hidemouse();
				color(500,190,580,200,14);
				erase(40,160,105,170);
	  			//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,170);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=170)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	
	 	//WRONG ATTEMPT
	  	if((Xpos>238 && Xpos<362)&&(Ypos>300 && Ypos<400))	{
			if(1==(button&1))	{
		      	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();



/*=========2nd MOVE=========*/
	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    
 		if((Xpos>30 && Xpos<115)&& (Ypos>170 && Ypos<180))	{
			if(1==(button&1))	{
			 	clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
	  	}
	}
	  	
  	
  	while(count!=m)	{
    mouseInfo(&button, &Xpos, &Ypos);
     	if((Xpos>258 && Xpos<342)&&(Ypos>390 && Ypos<400))	{
			if(1==(button&1))	{
			hidemouse();
				color(258,390,342,400,3);
		  		erase(30,170,115,180);
				//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,180);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=180)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}

		//WRONG ATTEMPT
	 	if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			if(1==(button&1))	{
		    	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();

/*=========3rd MOVE=========*/
	setcolor(15);
  	outtextxy(205,460,"NEXT MOVE");
  
	while(count!=m)	{
		mouseInfo(&button, &Xpos, &Ypos);
 		if((Xpos>498 && Xpos<582)&& (Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
	  	}
	}
  	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	x=getmaxx()/2-52,x1=getmaxx()/2-20+32,y=380,y1=390;
		if((Xpos>268 && Xpos<332)&&(Ypos>380 && Ypos<390))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(268,380,332,390,14);
				erase(498,190,582,200);
				//BASE B rod
				setcolor(15);
				rectangle(538,100,548,200);
				x=539,y=101,x1=547,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}

	 	//WRONG ATTEMPT
		if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))	{
			if(1==(button&1))	{
			    delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========4th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
	    mouseInfo(&button, &Xpos, &Ypos);
		if((Xpos>20 && Xpos<125)&& (Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	 x=540-52,x1=540+52,y=190,y1=200;
		 if((Xpos>488 && Xpos<592)&&(Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(488,190,592,200,10);
				erase(20,180,125,190);
				//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,188);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=188)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
	  	if((Xpos>238 && Xpos<362)&&(Ypos>300 && Ypos<400))	{
			if(1==(button&1)){
		    	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();

/*=========5th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
   	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     
 		if((Xpos>268 && Xpos<332)&& (Ypos>380 && Ypos<390))	{
			if(1==(button&1))	{
				 clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>40 && Xpos<100)&&(Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
				hidemouse();
				color(40,180,100,190,14);
			  	erase(268,380,332,390);
				//BASE C rod
				setcolor(15);
				rectangle(293,300,303,390);
				x=294,y=301,x1=302,y1=301;
	  			while(y1!=390)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
 		if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			if(1==(button&1))	{
		     	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========6th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
		mouseInfo(&button, &Xpos, &Ypos);
 		
		if((Xpos>258 && Xpos<342)&& (Ypos>390 && Ypos<400))	{
			if(1==(button&1)){
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}
	
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	if((Xpos>498 && Xpos<582)&&(Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
		  		hidemouse();
				color(498,180,582,190,3);
		  		erase(258,390,342,400);
				//BASE C rod
				setcolor(15);
				rectangle(293,300,303,400);
				x=294,y=301,x1=302,y1=301;
	  			while(y1!=400)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
	 	if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))	{
			if(1==(button&1))	{
		   		delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========7th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
		
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>40 && Xpos<100)&& (Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
				 clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);

		if((Xpos>508 && Xpos<572)&&(Ypos>170 && Ypos<180))	{
			if(1==(button&1))	{
				  	hidemouse();
					color(508,170,572,180,14);
					erase(40,180,100,190);
					//BASE A rod
	  				setcolor(15);
					rectangle(67,100,77,190);
					x=68,y=101,x1=76,y1=101;
	  				while(y1!=190)	{
	  					line(x,y,x1,y1);
	  					y++,y1++;
	  				}
		  			break;
		 		}
		 	}
	   
			//WRONG ATTEMPT
	  		if((Xpos>238 && Xpos<362)&&(Ypos>300 && Ypos<400))	{
				if(1==(button&1)){
			    delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========8th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
    
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     
 		if((Xpos>5 && Xpos<135)&& (Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>238 && Xpos<362)&&(Ypos>390 && Ypos<400))	{
			if(1==(button&1))	{
				hidemouse();
				color(238,390,362,400,12);
				erase(5,190,135,200);
				//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,200);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
	 	if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			if(1==(button&1))	{
		    	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========9th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
 	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     
 		if((Xpos>508 && Xpos<572)&& (Ypos>170 && Ypos<180))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    	
     	if((Xpos>278 && Xpos<322)&&(Ypos>380 && Ypos<390))	{
			if(1==(button&1))	{
				hidemouse();
				color(278,380,322,390,14);
				erase(508,170,572,180);
				//BASE B rod
				setcolor(15);
				rectangle(538,100,548,180);
				x=539,y=101,x1=547,y1=101;
	  			while(y1!=180)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
	 	if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))	{
			if(1==(button&1))	{
			   	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========10th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	if((Xpos>498 && Xpos<582)&& (Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>30 && Xpos<115)&&(Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
				hidemouse();
				color(30,190,115,200,3);
				erase(498,180,582,190);
				//BASE B rod
				setcolor(15);
				rectangle(538,100,548,190);
				x=539,y=101,x1=547,y1=101;
	  			while(y1!=190)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
	  	if((Xpos>238 && Xpos<362)&&(Ypos>300 && Ypos<400))	{
			if(1==(button&1))	{
			    delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========11th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
  	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    
 		if((Xpos>278 && Xpos<322)&& (Ypos>380 && Ypos<390))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>50 && Xpos<95)&&(Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
				hidemouse();
				color(50,180,95,190,14);
				erase(278,380,322,390);
				//BASE C rod
				setcolor(15);
				rectangle(293,300,303,388);
				x=294,y=301,x1=302,y1=301;
	  			while(y1!=388)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
 		if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			if(1==(button&1)){
			    delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========12th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
	    
		if((Xpos>488 && Xpos<592)&& (Ypos>190 && Ypos<200))	{
			if(1==(button&1)){
				 clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

 	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    	
     	if((Xpos>258 && Xpos<342)&&(Ypos>380 && Ypos<390))	{
			if(1==(button&1))	{
				hidemouse();
				color(258,380,342,390,10);
				erase(298,190,592,200);
				//BASE B rod
				setcolor(15);
				rectangle(538,100,548,200);
				x=539,y=101,x1=547,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
		if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))	{
			if(1==(button&1))	{
			   	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========13th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
    
 		if((Xpos>50 && Xpos<95)&& (Ypos>180 && Ypos<190))	{
			if(1==(button&1))	{
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		if((Xpos>508 && Xpos<572)&&(Ypos>190 && Ypos<200))	{
			if(1==(button&1))	{
			  	hidemouse();
				color(508,190,572,200,14);
		   		erase(50,180,95,190);
				//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,190);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=190)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
	  	if((Xpos>238 && Xpos<362)&&(Ypos>300 && Ypos<400))	{
			if(1==(button&1))	{
			    delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========14th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     
 		if((Xpos>30 && Xpos<115)&& (Ypos>190 && Ypos<200))	{
			if(1==(button&1)){
				clear();
	 			setcolor(15);
	 			outtextxy(205,460,"NOW CLICK ON BASE.");
	  			break;
	 		}
		}
	}

  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	if((Xpos>265 && Xpos<335)&&(Ypos>370 && Ypos<380))	{
			if(1==(button&1))	{
				hidemouse();
				color(265,370,335,380,3);
				erase(30,190,115,200);
				//BASE A rod
	  			setcolor(15);
				rectangle(67,100,77,200);
				x=68,y=101,x1=76,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}
	   
		//WRONG ATTEMPT
	 	if((Xpos>439 && Xpos<639)&&(Ypos>10 && Ypos<230))	{
			if(1==(button&1))	{
		    	delay(200);
		    	wrong(mod,disknum);
		 	}
	  	}
	}
	clear();
	showmouse();


/*=========15th MOVE=========*/
	setcolor(15);
	outtextxy(205,460,"SELECT DISC.");
	
	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     
 		if((Xpos>508 && Xpos<572)&& (Ypos>190 && Ypos<200))if(1==(button&1))	{
			clear();
 			setcolor(15);
 			outtextxy(205,460,"NOW CLICK ON BASE.");
  			break;
 		}
	}
  
  	while(count!=m)	{
    	mouseInfo(&button, &Xpos, &Ypos);
     	
		 if((Xpos>280 && Xpos<320)&&(Ypos>360 && Ypos<370))	{
			if(1==(button&1))	{
				hidemouse();
				color(280,360,320,370,14);
				erase(508,190,572,200);
				//BASE B rod
				setcolor(15);
				rectangle(538,100,548,200);
				x=539,y=101,x1=547,y1=101;
	  			while(y1!=200)	{
	  				line(x,y,x1,y1);
	  				y++,y1++;
	  			}
		  		break;
		 	}
		}

	 	//WRONG ATTEMPT
	 	if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))	{
				if(1==(button&1))	{
	   				delay(200);
	    			wrong(mod,disknum);
	    	}
	 	}
  	}
  	
	setcolor(4);
  	rectangle(190,245,420,265);
	outtextxy(200,250,"PRESS ANY KEY TO SEE RESULT");
	int ctr=1;
	getch();
  	if(ctr==1)	{
  		if(count==0)	{
  			perfectwin(count);
		  }
  		else if(count<m)	{
  			win(count);
		  }
	  }
	

 return 0;
}

/*============================================================================*/
/*============================= DSA CASE STUDY ===============================*/
/*============================================================================*/
/*HERNANDEZ
*RAMOS
*TOWER OF HANOI PUZZLE GAME
*USING MERGE ALGORITHM
*/
