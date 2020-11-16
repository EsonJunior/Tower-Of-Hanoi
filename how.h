void howtoplay()	{
	
	setcolor(15);
  	settextstyle(0,0,4);
  	outtextxy(10,10,"TOWER OF HANOI ");
  	
  	setcolor(8);
  	line(15,45,500,45);
  	
  	//GRAY PANEL
	rectangle(15,80,620,450);
  	int x=16,y=81,x1=619,y1=81;
 	while(y1!=450)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
  	
  	setcolor(15);
  	settextstyle(0,0,2);
	outtextxy(15,50,"HOW TO PLAY ?");
	
	settextstyle(0,0,1);
	outtextxy(60,90,"Tower of Hanoi is played with 3 stack and any number of differently");
	outtextxy(30,100,"sized disks. At the start, all the disk are in the source stack, with");
	outtextxy(30,110,"the largest disk on the bottom and the smallest on the top.");
	outtextxy(30,120,"# The objective is to get all the disks over to the destination stack.");
	
	outtextxy(30,140,"To move a disk, click on it (if can't click on a disk, it means you");
	outtextxy(30,150,"can't legally move it anywhere ). If there is only one place the disk");
	outtextxy(30,160,"can be moved to, it it will be moved there automatically; otherwise,");
	outtextxy(30,170,"you will have click on a stack to move it.");
	
	setcolor(12);
	outtextxy(30,190,"REMEMBER:");
	setcolor(15);
	outtextxy(60,200,"You can only move one disk per move, and you can only move the top");
	outtextxy(30,210,"disk on a stack. The top disk of any stack can  be moved to the top");
	outtextxy(30,220,"disk of any other stack, with the restriction that you can't move a");
	outtextxy(30,230,"larger disk on the top of a smaller disk.");
	
	
	setcolor(3);
	outtextxy(30,260,"HINT: Iterative solution.");
	
	setcolor(15);
	outtextxy(60,270,"STACK:   A [SOURCE]   B [TEMPORARY]   C [DESTINATION]");
	
	setcolor(12);
	outtextxy(30,290,"EVEN");
	setcolor(15);
	outtextxy(60,290," NUMBER OF DISK");
	outtextxy(60,300,"\t Move the disk between A and B [vise versa]");
	outtextxy(60,310,"\t Move the disk between A and C [vise versa]");
	outtextxy(60,320,"\t Move the disk between B and c [vise versa]");
	setcolor(3);
	outtextxy(100,330,"Repeat until complete.");
	
	setcolor(12);
	outtextxy(30,350,"ODD");
	setcolor(15);
	outtextxy(50,350," NUMBER OF DISK");
	outtextxy(60,360,"\t Move the disk between A and C [vise versa]");
	outtextxy(60,370,"\t Move the disk between A and B [vise versa]");
	outtextxy(60,380,"\t Move the disk between C and B [vise versa]");
	setcolor(3);
	outtextxy(100,390,"Repeat until complete.");

	setcolor(4);
    outtextxy(460,460,"BACK = [Backspace]");
    getch();
}

/*============================================================================*/
/*============================= DSA CASE STUDY ===============================*/
/*============================================================================*/
/*HERNANDEZ
*RAMOS
*TOWER OF HANOI PUZZLE GAME
*USING MERGE ALGORITHM
*/
