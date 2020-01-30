#include "Drawer.h"



Drawer::Drawer(int width /*= 5*/, COLORREF border_color /*= DEFT_BORDER_COLOR*/, COLORREF line_color /*= LINE_COLOR*/)
	: m_border_width(5)
	, m_border_color(DEFT_BORDER_COLOR)
	, m_line_color(LINE_COLOR)
{
	m_border_width = width;
	m_border_color = border_color;
	m_line_color = line_color;
	initgraph(WIDTH * CELL_SIZE + 2 * m_border_width + FUNAREA_WIDTH, HIGHT * CELL_SIZE + 2 * m_border_width + 3);
	setlinecolor(m_border_color);
	setlinestyle(PS_SOLID, m_border_width);
	setfillcolor(BACKGROUND_COLOR);
	fillrectangle(2,2, WIDTH * CELL_SIZE + 2 * m_border_width, HIGHT * CELL_SIZE + 2 * m_border_width);
}



Drawer::~Drawer()
{
}


void Drawer::drawGame(Board board)
{
	BeginBatchDraw();
	for (int i = 0; i < board.getBoardWidth(); ++i)
	{
		for (int j = 0; j < board.getBoardHight(); ++j)
		{
			if (board.getCellStatus(i, j))
			{
				setlinecolor(m_border_color);
				setfillcolor(board.getCellColor(i, j));
				setlinestyle(PS_SOLID, LINE_WIDTH);
				fillrectangle(6 + i * CELL_SIZE, 6 + j * CELL_SIZE, 7 + (i + 1) * CELL_SIZE, 7 + (j + 1) * CELL_SIZE);
			}
			else
			{
				int lx = 6 + i * CELL_SIZE;
				int ly = 6 + j * CELL_SIZE;
				int rx = 7 + (i + 1) * CELL_SIZE;
				int ry = 7 + (j + 1) * CELL_SIZE;

				setlinecolor(BACKGROUND_COLOR);
				setfillcolor(BACKGROUND_COLOR);
				setlinestyle(PS_SOLID| PS_ENDCAP_SQUARE, LINE_WIDTH);
				
				///边角处理
				//左一格||左下角不为空
				if ((i != 0) && (board.getCellStatus(i - 1, j) || board.getCellStatus(i - 1, j + 1)))
				{
					lx += LINE_WIDTH + 1;
				}
				//左上角不为空
				if ((i * j != 0) && board.getCellStatus(i - 1, j - 1))
				{
					lx += LINE_WIDTH + 1;
					ly += LINE_WIDTH + 1;
				}
				//上一格不为空
				if ((j != 0) && (board.getCellStatus(i, j - 1)))
				{
					ly += LINE_WIDTH + 1;
				}
				fillrectangle(lx, ly, rx, ry);
			}
		}
	}
	EndBatchDraw();
}

void Drawer::setBorderColor(COLORREF border_color)
{
	m_border_color = border_color;
	return;
}


void Drawer::setLineColor(COLORREF line_color)
{
	m_line_color = line_color;
	return;
}
