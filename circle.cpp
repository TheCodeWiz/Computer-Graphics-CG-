
#include <graphics.h> 

int main() 
{ 
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 
	circle(300, 225, 200); 
	getch(); 
	closegraph(); 
	return 0; 
} 
