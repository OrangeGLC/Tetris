#include "Rule.h"
#include <time.h>
#include <iostream>

#define COLOR_I (RGB(247, 68, 97))


Rule::Rule(Board &bd)
	: m_shape(SHAPE_I)
	, m_direct(LEFT)
	, m_cur_position(4,0)
	, m_fall_speed(500)
	, m_score(0)
{
	runGame(bd);
}


Rule::~Rule()
{
}


int Rule::generateSquire(Board &bd)
{

	srand((unsigned)time(0));
	switch (0/*rand() % 7*/)
	{
	case 0:
		generateI(bd);
		break;
	case 1:
		generateO(bd);
		break;
	case 2:
		generateL(bd);
		break;
	case 3:
		generateJ(bd);
		break;
	case 4:
		generateS(bd);
		break;
	case 5:
		generateZ(bd);
		break;
	case 6:
		generateT(bd);
		break;
	default:
		break;
	}
	return 0;
}


// 生成I形状方块
void Rule::generateI(Board &bd)
{
	m_direct = generateDirection();
	m_shape = SHAPE_I;
	m_cur_position.x(4);
	m_cur_position.y(0);

	int i = m_cur_position.x();
	int j = m_cur_position.y();

	if (m_direct == UP || m_direct == DOWN)
	{
		bd.setCellStatu(i, j , true);
		bd.setCellStatu(i, j + 1, true);
		bd.setCellStatu(i, j + 2, true);
		bd.setCellStatu(i, j + 3, true);
						   
		bd.setCellColor(i, j, COLOR_I);
		bd.setCellColor(i, j + 1, COLOR_I);
		bd.setCellColor(i, j + 2, COLOR_I);
		bd.setCellColor(i, j + 3, COLOR_I);
	}
	else
	{
		i -= 1;
		bd.setCellStatu(i, j, true);
		bd.setCellStatu(i + 1, j, true);
		bd.setCellStatu(i + 2, j, true);
		bd.setCellStatu(i + 3, j, true);

		bd.setCellColor(i, j, COLOR_I);
		bd.setCellColor(i + 1, j, COLOR_I);
		bd.setCellColor(i + 2, j, COLOR_I);
		bd.setCellColor(i + 3, j, COLOR_I);
	}
	m_cur_position.x(i);
	return;
}


// I方块下落1格
void Rule::fallI(Board &bd)
{
	int i = m_cur_position.x();
	int j = m_cur_position.y();
	
	if (m_direct == UP || m_direct == DOWN)
	{
		bd.setCellStatu(i, j, false);
		bd.setCellStatu(i, j + 1, true);
		bd.setCellStatu(i, j + 2, true);
		bd.setCellStatu(i, j + 3, true);
		bd.setCellStatu(i, j + 4, true);
		
		bd.setCellColor(i, j + 1, COLOR_I);
		bd.setCellColor(i, j + 2, COLOR_I);
		bd.setCellColor(i, j + 3, COLOR_I);
		bd.setCellColor(i, j + 4, COLOR_I);
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

		bd.setCellColor(i, j + 1, COLOR_I);
		bd.setCellColor(i + 1, j + 1, COLOR_I);
		bd.setCellColor(i + 2, j + 1, COLOR_I);
		bd.setCellColor(i + 3, j + 1, COLOR_I);
	}

	m_cur_position.y(++j);	
}

void Rule::fallO(Board & bd)
{
	return;
}

void Rule::fallJ(Board & bd)
{
	return;
}

void Rule::fallL(Board & bd)
{
	return;
}

void Rule::fallZ(Board & bd)
{
	return;
}

void Rule::fallS(Board & bd)
{
	return;
}

void Rule::fallT(Board & bd)
{
	return;
}


// 是否触底
bool Rule::isBottomOut(Board &bd)
{
	switch (m_shape)
	{
	case SHAPE_I:
		return isBottomOutShapeI(bd);
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
bool Rule::isBottomOutShapeI(Board& bd)
{
	int i = m_cur_position.x();
	int j = m_cur_position.y();

	if (m_direct == UP || m_direct == DOWN)
	{
		if (j + 4 >= bd.getBoardHight() || true == bd.getCellStatus(i,j + 4))
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
void Rule::whirlI(Board& bd)
{
	int x = m_cur_position.x();
	int y = m_cur_position.y();
	if (m_direct == UP || m_direct == DOWN)
	{
		m_direct = LEFT;
		bd.setCellStatu(x, y, false);
		bd.setCellStatu(x, y + 1, false);
		bd.setCellStatu(x, y + 2, false);
		bd.setCellStatu(x, y + 3, false);


		bd.setCellStatu(x - 1, y + 1, true);
		bd.setCellStatu(x + 1, y + 1, true);
		bd.setCellStatu(x + 2, y + 1, true);

		bd.setCellColor(x - 1, y + 1, COLOR_I);
		bd.setCellColor(x + 1, y + 1, COLOR_I);
		bd.setCellColor(x + 2, y + 1, COLOR_I);
	}
	else
	{
		m_direct = UP;
		bd.setCellStatu(x, y, false);
		bd.setCellStatu(x + 2, y, false);
		bd.setCellStatu(x + 3, y, false);

		bd.setCellStatu(x + 1, y - 1, true);
		bd.setCellStatu(x + 1, y + 1, true);
		bd.setCellStatu(x + 1, y + 2, true);

		bd.setCellColor(x + 1, y - 1, COLOR_I);
		bd.setCellColor(x + 1, y + 1, COLOR_I);
		bd.setCellColor(x + 1, y + 2, COLOR_I);
	}
	return;
}


void Rule::runGame(Board &bd)
{
	while (true)
	{
		generateSquire(bd);
		if (isBottomOut(bd))
		{
			break;
		}
		while (true)
		{
			Sleep(m_fall_speed);
			fallSquire(bd);
			if (isBottomOut(bd))
			{
				break;
			}
		}
		
	}
	
}


bool Rule::isGameOver(Board& bd)
{
	bool ret = false;
	for (int i = 0; i < bd.getBoardHight(); ++i)
	{
		if (bd.getCellStatus(4, i))
		{
			//
		}
	}
	return ret;
}


// 生成O形状方块
void Rule::generateO(Board& bd)
{
	return;
}


void Rule::generateL(Board& bd)
{
	return;
}


void Rule::generateJ(Board& bd)
{
	return;
}


void Rule::generateZ(Board& bd)
{
	return;
}


void Rule::generateS(Board& bd)
{
	return;
}

void Rule::generateT(Board& bd)
{
	return;
}


int Rule::fallSquire(Board& bd)
{
	srand((unsigned)time(0));
	switch (0/*rand() % 7*/)
	{
	case 0:
		fallI(bd);
		break;
	case 1:
		fallO(bd);
		break;
	case 2:
		fallL(bd);
		break;
	case 3:
		fallJ(bd);
		break;
	case 4:
		fallS(bd);
		break;
	case 5:
		fallZ(bd);
		break;
	case 6:
		fallT(bd);
		break;
	default:
		break;
	}
	return 0;
}


// 旋转方块
void Rule::whirlSquire(Board& bd)
{
}
