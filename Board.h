#pragma once

#include "Cell.h"

#define	WIDTH	10
#define	HIGHT	20
#define	BORDER_WIDTH	5
#define BORDER_COLOR	(RGB(207,191,140))


class Board
{
public:
	Board();
	~Board();
	void		clearBoard();
	int			getBoardWidth();
	int			getBoardHight();
	COLORREF	getCellColor(int x, int y);
	bool		getCellStatus(int x, int y);
	void		setCellStatu(int x, int y, bool statu);
	int			setCellColor(int x, int y, COLORREF color);

private:
	Cell m_board[WIDTH][HIGHT];
};

