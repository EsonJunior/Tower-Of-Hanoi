void levelinfo(int l)	{
	int x,y,x1,y1;
	setcolor(12);
  	settextstyle(DEFAULT_FONT,0,4);
  	outtextxy(75,50,"TOWER OF HANOI ");
	setcolor(3);
 	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  	outtextxy(350,95,"CHOOSE DIFFICULTIES.");
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  	if(l==3)	{
  		rectangle(10,200,200,260);
  		x=11,y=201,x1=201,y1=201;
  		for(y1=201;y1!=260;y1++)	{
  		line(x,y,x1,y1);
  		y++;
  		}
  		setcolor(0);
  		outtextxy(40,225,"3 DISK");
  		setcolor(3);
		rectangle(10,280,200,340);
  		outtextxy(40,300,"4 DISK");
	}
	else if(l==4)	{
		rectangle(10,200,200,260);
  		outtextxy(40,225,"3 DISK");
  		rectangle(10,280,200,340);
  		x=11,y=281,x1=201,y1=281;
  		for(y=281;y1!=340;y1++)	{
  		line(x,y,x1,y1);
  		y++;
  		}
  		setcolor(0);
  		outtextxy(40,300,"4 DISK");
	}
	
	
	
  	
	  //WHITE PANEL
  	setcolor(3);
	rectangle(230,120,625,420);
  	x=231,y=121,x1=624,y1=121;
  	setcolor(15);
	while(y1!=420)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
  	
	setcolor(3);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(260,150,"EASY MODE");	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(330,180,"Maximum of 4 wrong attemp.");
	outtextxy(330,200,"Maximum of 8 wrong attemp.");
	//Light Red Panel
	setcolor(12);
	rectangle(410,140,495,170);
  	x=411,y=141,x1=494,y1=141;
 	while(y1!=170)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
  	outtextxy(260,180,"3 DISK |");
	outtextxy(260,200,"4 DISK |");
  	setcolor(15);
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(425,152,"PRESS E");
  	
  	setcolor(3);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(260,240,"NORMAL MODE");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(330,270,"Maximum of 2 wrong attemp.");
	outtextxy(330,290,"Maximum of 5 wrong attemp.");
	//Light Red Panel
	setcolor(12);
	rectangle(440,230,525,260);
	x=441,y=231,x1=524,y1=231;
 	while(y1!=260)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
  	outtextxy(260,270,"3 DISK |");
	outtextxy(260,290,"4 DISK |");
  	setcolor(15);
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(455,242,"PRESS N");
	
	setcolor(3);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(260,330,"VETERAN MODE");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(330,360,"Maximum of 1 wrong attemp.");
	outtextxy(330,380,"Maximum of 3 wrong attemp.");
	//Light Red Panel
	setcolor(12);
	rectangle(460,320,545,350);
	x=461,y=321,x1=544,y1=321;
 	while(y1!=350)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
  	outtextxy(260,360,"3 DISK |");
	outtextxy(260,380,"4 DISK |");
  	setcolor(15);
  	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(475,332,"PRESS V");
	
	setcolor(4);
   	outtextxy(250,460,"MAIN MENU = [Backspace]");
}

/*============================================================================*/
/*============================= DSA CASE STUDY ===============================*/
/*============================================================================*/
/*HERNANDEZ
*RAMOS
*TOWER OF HANOI PUZZLE GAME
*USING MERGE ALGORITHM
*/
