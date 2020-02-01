#pragma once
#include "Board.h"
#include <mutex>

#define CELL_SIZE			(40)
#define FUNAREA_WIDTH		(150)
#define BACKGROUND_COLOR	(RGB(0,0,0))
#define LINE_COLOR			(RGB(35,31,32))
#define LINE_WIDTH			(3)
#define DEFT_BORDER_COLOR	(RGB(179,197,135))

extern std::mutex g_mutex;

class Drawer
{
public:
	Drawer(Board &bd, int width = 5, COLORREF border_color = DEFT_BORDER_COLOR, COLORREF line_color = LINE_COLOR);
	~Drawer();
	void drawGame(Board& board);
	void setBorderColor(COLORREF border_color);
	void setLineColor(COLORREF line_color);

private:
	int			m_border_width;
	COLORREF	m_border_color;
	COLORREF	m_line_color;
};

