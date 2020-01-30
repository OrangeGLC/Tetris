#include <graphics.h>      
#include <conio.h>
#include "Drawer.h"
#include "Rule.h"
#include <iostream>

#define OK		0
#define ERROR	-1


int main(int argc, char* argv[])
{
	Drawer dw;
	Board bd;
	Rule ru(bd, dw);
	
	_getch();              
	closegraph();

	return OK;
}