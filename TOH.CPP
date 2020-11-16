#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<io.h>
#include<toh.h>


/*MAIN FUNCTION*/
void main()	{
	graphicsdriver();
	
	setcolor(15);
	settextstyle(0,0,1);
	outtextxy(380,130,"BSCS12A: HERNANDEZ & RAMOS ");
	rectangle(375,125,590,140);
				
  	setcolor(12);
  	settextstyle(0,0,5);
  	outtextxy(40,150,"TOWER OF HANOI ");
  	
	settextstyle(1,0,1);
  	setcolor(3);
  	outtextxy(450,190,"PUZZLE GAME");
  	
  	setcolor(3);
  	settextstyle(0,0,2);			
  	outtextxy(280,270,"LOADING...");
  	
	//LOADING BAR
  	int x=180,y=220,x1=200,y1=220;
  	while(x1<=500)	{
  		sound(x1);
  		setcolor(15);
   		delay(50);
   		
		for(int ctr=1;ctr<40;ctr++)	{
   			line(x,y+ctr,x1,y1+ctr);
   		}
   		x+=5,x1+=5;
  	}
  	delay(200);
  	nosound();
  	
  	settextstyle(0,0,1);
  	setcolor(4);
  	outtextxy(460,460,"PRESS ANY KEY.");
	
	getch();
 	gamemenu();	//Funtion Call for toh.h
}

/*HEAD FILES LIST*/
//toh.h
//instruction.h
//about.h
//logo.h
//lvlinfo.h

/*============================================================================*/
/*============================= DSA CASE STUDY ===============================*/
/*============================================================================*/
/*HERNANDEZ
*RAMOS
*TOWER OF HANOI PUZZLE GAME
*USING MERGE ALGORITHM
*/
