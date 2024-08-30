#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void BFill(int x, int y , int newcolor ,int delay_time)
{
	int currpixel= getpixel(x,y);
	if(currpixel!=newcolor && currpixel!= WHITE)
	{
		putpixel(x,y,newcolor);
		delay(delay_time);
		BFill(x-1,y,newcolor, delay_time);
		BFill(x+1,y,newcolor, delay_time);
		BFill(x,y+1,newcolor, delay_time);
		BFill(x,y-1,newcolor, delay_time);
	}
}

int main()
{
	int gd,gm;
	detectgraph(&gd,&gm);
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd,&gm,data);
	int x= getmaxx();
	int y= getmaxy();
	line(x/2,0,x/2,y);
	line(0,y/2,x,y/2);

	line(x/2+10,y/2-10,x/2+10,y/2-50);
	line(x/2+10,y/2-50,x/2+50,y/2-50);
	line(x/2+50,y/2-50,x/2+50,y/2-10);
	line(x/2+50,y/2-10,x/2+10,y/2-10);

	BFill(x/2+30,y/2-30,2, 10);

	getch();

	closegraph();
	return 0;
}