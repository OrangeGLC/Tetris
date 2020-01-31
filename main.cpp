#include <graphics.h>      
#include <conio.h>
#include <iostream>
#include <thread>
#include "Drawer.h"
#include "Rule.h"


#define OK		0
#define ERROR	-1

static Board bd;

void startDrwa()
{
	Drawer dw(bd);
	while (true)
	{
		dw.drawGame(bd);
		Sleep(1000 / 30);
	}
}


int main(int argc, char* argv[])
{
	std::thread ui(startDrwa);
	ui.detach();
	Rule ru(bd);
	_getch();  
	return OK;
}