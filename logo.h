void logo()	{
	
	//ROD
	setcolor(15);
	rectangle(410,130,430,195);
	int x=411,y=131,x1=429,y1=131;
	while(y1!=250)	{
   		line(x,y,x1,y1);
   		y++,y1++;
   	}
  	//GREEN PEG
  	setcolor(10);
	rectangle(350,195,500,250);
	x=351,y=196,x1=499,y1=196;
	while(y1!=250)	{
   		line(x,y,x1,y1);
   		y++,y1++;
   	}
   	//BLUE PEG
	setcolor(3);
	rectangle(300,250,550,305);
  	x=301,y=251,x1=549,y1=251;
 	while(y1!=305)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
	//RED PEG
	setcolor(12);
	rectangle(250,305,600,360);
  	x=251,y=306,x1=599,y1=306;
  	while(y1!=360)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
  	//BASE
  	setcolor(15);
	rectangle(230,360,625,370);
  	x=231,y=361,x1=624,y1=361;
  	while(y1!=370)	{
  	line(x,y,x1,y1);
  	y++,y1++;
  	}
}

/*============================================================================*/
/*============================= DSA CASE STUDY ===============================*/
/*============================================================================*/
/*HERNANDEZ
*RAMOS
*TOWER OF HANOI PUZZLE GAME
*USING MERGE ALGORITHM
*/
