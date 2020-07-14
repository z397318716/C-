#include<easyx.h>
#include<conio.h>
#include<graphics.h>


int main()
{
	
	//setlinecolor(WHITE);
	initgraph(500, 600);
	setaspectratio(1, -1);

	
	line(100, 300, 300, 300);
	moveto(300, 0);
	linerel(0, 300);
	lineto(200, 300);
	_getch();
	closegraph();


	return 0;
}