void tohinfo()	{
	
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
	outtextxy(15,50,"ABOUT");
	
	settextstyle(0,0,1);
	outtextxy(55,90,"The tower of Hanoi (also called the tower of Brahma or the Lucas tower)");
	outtextxy(30,100,"was invented by a French mathematician Édouard Lucas in the 19th century.");
	
	setcolor(12);
	outtextxy(30,130,"LEGEND");
	
	setcolor(15);
	outtextxy(60,140,"It is associated with a legend of a Hindu temple where the puzzle was");
	outtextxy(30,150,"supposedly used to increase the mental discipline of young priests.");
	outtextxy(30,160,"In the legend the young priests were given 64 gold disks stacked neatly");
	outtextxy(30,170,"on one of three posts. Each disk rested on a slightly larger disk.");
	outtextxy(30,180,"The priests' goal was to re-create the stack on a different post by");
	outtextxy(30,190,"moving disks, one at a time, to another post with the rule that a");
	outtextxy(30,200,"larger disk could never be placed on top of a smaller disk. Using");
	outtextxy(30,210,"mathematics, you can calculate that even when the priests found the");
	outtextxy(30,220,"most efficient way to solve the problem, and moved the disks at");
	outtextxy(30,230,"a rate of one per second, it would take almost 585 billion years to");
	outtextxy(30,240,"finish the job. That is more than 40 times the age of the universe!");
	
	outtextxy(55,260,"You might wonder how mathematics is involved in playing this game.");
	outtextxy(30,270,"As you play the game with more and more disks, you will notice");
	outtextxy(30,280,"you start to look for patterns. If you try to explain how you solve");
	outtextxy(30,290,"the puzzle, you might realize you use one of the mathematical concepts");
	
	setcolor(3);
	outtextxy(30,310,"CONCEPT");
	setcolor(15);
	outtextxy(30,320,"   \t Mathematics");
	outtextxy(30,330,"   \t Puzzles");
	outtextxy(30,340,"   \t Algorithms");
	
	setcolor(3);
	outtextxy(30,360,"SOLUTIONS");
	setcolor(15);
	outtextxy(30,370,"   \t ITERATIVE");
	outtextxy(30,380,"   \t RECURSIVE");
	outtextxy(30,390,"   \t SORT ALGORITHM [MERGE]");
	
	setcolor(3);
	outtextxy(30,410,"MATERIALS");
	setcolor(15);
	outtextxy(30,420,"   \t DISK");
	outtextxy(30,430,"   \t STACK [Rod]");
	
	setcolor(3);
	rectangle(300,310,600,440);
	outtextxy(310,320,"MATHEMATICAL INDUCTION [FORMULA]");
	setcolor(15);
	outtextxy(340,330,"Sn = Minimum number of Move");
	outtextxy(340,340," n = Number of Disk");
	outtextxy(310,350,"Formula:");
	
	setcolor(12);
	outtextxy(380,350,"Sn = 2^n-1");
	
	setcolor(3);
	outtextxy(310,370,"EXAMPLE: 3 DISK");
	setcolor(15);
	outtextxy(310,380,"   Sn = 2^(3)-1");
	outtextxy(310,390,"   Sn = 8-1");
	outtextxy(310,400,"   Sn = 7");
	setcolor(12);
	outtextxy(330,415,"Therefore 7 is the minimum number");
	outtextxy(310,425,"of move to solve 3 Disk.");
	
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
