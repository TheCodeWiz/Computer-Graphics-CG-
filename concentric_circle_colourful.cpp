#include<stdio.h>
#include<graphics.h>
#include<conio.h>
 
int main(){
   int gd = DETECT,gm;
   int x ,y;
   char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
   initgraph(&gd,&gm,data);
   x = getmaxx()/2;
   y = getmaxy()/2;
   outtextxy(240, 50, "Concentric Circles");
   setcolor(RED);
   circle(x, y, 30);
   setcolor(GREEN);
   circle(x, y, 50);
   setcolor(YELLOW);
   circle(x, y, 70);
   setcolor(BLUE);
   circle(x, y, 90);
   getch();
   closegraph();
   return 0;
}