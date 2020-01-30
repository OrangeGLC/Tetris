#include "Rule.h"
#include <time.h>
#include <iostream>

DIRECTION Rule::m_statu_I = LEFT;
DIRECTION Rule::m_statu_O = UP;
DIRECTION Rule::m_statu_J = UP;
DIRECTION Rule::m_statu_L = UP;
DIRECTION Rule::m_statu_S = UP;
DIRECTION Rule::m_statu_Z = UP;
DIRECTION Rule::m_statu_T = UP;

Rule::Rule(Board &bd, Drawer &dw)
	: m_fall_speed(1000)
	, m_score(0)
{
	generateI(bd, dw);
	fallI(bd, dw);
}


Rule::~Rule()
{
}


void Rule::generateSquire()
{

}


// 生成I形状方块
int Rule::generateI(Board &bd, Drawer &dw, int i , int j)
{
	m_statu_I = generateDirection();
	if (m_statu_I == UP || m_statu_I == DOWN)
	{
		bd.setCellStatu(i, j , true);
		bd.setCellStatu(i, j + 1, true);
		bd.setCellStatu(i, j + 2, true);
		bd.setCellStatu(i, j + 3, true);
						   
		bd.setCellColor(i, j, RGB(247, 68, 97));
		bd.setCellColor(i, j + 1, RGB(247, 68, 97));
		bd.setCellColor(i, j + 2, RGB(247, 68, 97));
		bd.setCellColor(i, j + 3, RGB(247, 68, 97));
	}
	else
	{
		i -= 1;
		bd.setCellStatu(i, j, true);
		bd.setCellStatu(i + 1, j, true);
		bd.setCellStatu(i + 2, j, true);
		bd.setCellStatu(i + 3, j, true);

		bd.setCellColor(i, j, RGB(247, 68, 97));
		bd.setCellColor(i + 1, j, RGB(247, 68, 97));
		bd.setCellColor(i + 2, j, RGB(247, 68, 97));
		bd.setCellColor(i + 3, j, RGB(247, 68, 97));
	}

	dw.drawGame(bd);
	return 0;
}


// I方块下落
void Rule::fallI(Board &bd, Drawer &dw, int i, int j)
{
	if (!(m_statu_I == UP || m_statu_I == DOWN))
	{
		i--;
	}

	while (1)
	{
		if (m_statu_I == UP || m_statu_I == DOWN)
		{
			bd.setCellStatu(i, j, false);
			bd.setCellStatu(i, j + 1, true);
			bd.setCellStatu(i, j + 2, true);
			bd.setCellStatu(i, j + 3, true);
			bd.setCellStatu(i, j + 4, true);
			
			bd.setCellColor(i, j + 1, RGB(247, 68, 97));
			bd.setCellColor(i, j + 2, RGB(247, 68, 97));
			bd.setCellColor(i, j + 3, RGB(247, 68, 97));
			bd.setCellColor(i, j + 4, RGB(247, 68, 97));
		}
		else
		{
			bd.setCellStatu(i, j, false);
			bd.setCellStatu(i + 1, j, false);
			bd.setCellStatu(i + 2, j, false);
			bd.setCellStatu(i + 3, j, false);

			bd.setCellStatu(i, j + 1, true);
			bd.setCellStatu(i + 1, j + 1, true);
			bd.setCellStatu(i + 2, j + 1, true);
			bd.setCellStatu(i + 3, j + 1, true);

			bd.setCellColor(i, j + 1, RGB(247, 68, 97));
			bd.setCellColor(i + 1, j + 1, RGB(247, 68, 97));
			bd.setCellColor(i + 2, j + 1, RGB(247, 68, 97));
			bd.setCellColor(i + 3, j + 1, RGB(247, 68, 97));
		}

		Sleep(m_fall_speed);
		dw.drawGame(bd);
		j++;
		if (isBottomOut(bd, i, j, SHAPE_I))
		{
			break;
		}	
	}
}


// 是否触底
bool Rule::isBottomOut(Board &bd, int x, int y, SHAPE shape)
{
	switch (shape)
	{
	case SHAPE_I:
		return isBottomOutShapeI(bd, x, y);
	case SHAPE_J:
		break;
	case SHAPE_L:
		break;
	case SHAPE_S:
		break;
	case SHAPE_Z:
		break;
	case SHAPE_O:
		break;
	case SHAPE_T:
		break;
	}
	return false;
}


// 判断I方块是否触底
bool Rule::isBottomOutShapeI(Board& bd, int i, int j)
{
	if (m_statu_I == UP || m_statu_I == DOWN)
	{
		if (j + 4 >= bd.getBoardHight() || true == bd.getCellStatus(i,j + 5))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		for(int t = i;t < i+4;++t)
		{
			if (true == bd.getCellStatus(t, j + 1))
			{
				return true;
			}
		}
		if (j + 1 >= bd.getBoardHight())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return 0;
}


// 随机生成方向
DIRECTION Rule::generateDirection()
{
	DIRECTION sd;
	srand((unsigned)time(0));
	switch (rand() % 4)
	{
	case 0:
		sd = UP;
		break;
	case 1:
		sd = DOWN;
		break;
	case 2:
		sd = LEFT;
		break;
	case 3:
		sd = RIGHT;
		break;
	}
	return sd;
}


// 旋转I方块
void Rule::whirlI(Board& bd, int x, int y)
{
	if (m_statu_I == UP || m_statu_I == DOWN)
	{
		m_statu_I = LEFT;
		bd.setCellStatu(x, y, false);
	}
	return;
}
