#include "Rule.h"
#include <time.h>
#include <iostream>
#include <conio.h>
#include <mutex>

#define COLOR_I (RGB(247, 68, 97))

extern std::mutex g_mutex;

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


void Rule::generateSquire(Board &bd)
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
	return;
}


// 生成I形状方块
void Rule::generateI(Board &bd)
{
	g_mutex.lock();
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

	g_mutex.unlock();
	return;
}


// I方块下落1格
void Rule::fallI(Board &bd)
{
	g_mutex.lock();
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
	g_mutex.unlock();
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
	g_mutex.lock();
	bool ret = false;
	int i = m_cur_position.x();
	int j = m_cur_position.y();

	if (m_direct == UP || m_direct == DOWN)
	{
		if (j + 4 >= bd.getBoardHight() || true == bd.getCellStatus(i,j + 4))
		{
			ret = true;
		}
	}
	else
	{
		for(int t = i;t < i+4;++t)
		{
			if (true == bd.getCellStatus(t, j + 1))
			{
				ret = true;
				break;
			}
		}
		if (j + 1 >= bd.getBoardHight())
		{
			ret = true;
		}
	}
	g_mutex.unlock();
	return ret;
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
	g_mutex.lock();
	int x = m_cur_position.x();
	int y = m_cur_position.y();

	if (m_direct == UP || m_direct == DOWN)
	{
		m_direct = LEFT;
		bd.setCellStatu(x, y, false);
		bd.setCellStatu(x, y + 2, false);
		bd.setCellStatu(x, y + 3, false);

		bd.setCellStatu(x - 1, y + 1, true);
		bd.setCellStatu(x + 1, y + 1, true);
		bd.setCellStatu(x + 2, y + 1, true);

		bd.setCellColor(x - 1, y + 1, COLOR_I);
		bd.setCellColor(x + 1, y + 1, COLOR_I);
		bd.setCellColor(x + 2, y + 1, COLOR_I);

		m_cur_position.x(x - 1);
		m_cur_position.y(y + 1);
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

		m_cur_position.x(x + 1);
		m_cur_position.y(y - 1);
	}
	g_mutex.unlock();
	return;
}


void Rule::runGame(Board &bd)
{
	char ch;
	while (true)
	{
		generateSquire(bd);
		if (isGameOver(bd))
		{
			break;
		}
		while (true)
		{
			if (_kbhit())
			{
				ch = getch();
				switch (ch)
				{
				case 0x48://上
					whirlI(bd);
					break;
				case 0x50://下
					break;
				case 0x4b://左
					break;
				case 0x4d://右
					break;
				}
			}
			
			if (isBottomOut(bd))
			{
				break;
			}
			Sleep(m_fall_speed);
			fallSquire(bd);
			
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


void Rule::fallSquire(Board& bd)
{
	switch (m_shape)
	{
	case SHAPE_I:
		fallI(bd);
		break;
	case SHAPE_O:
		fallO(bd);
		break;
	case SHAPE_L:
		fallL(bd);
		break;
	case SHAPE_J:
		fallJ(bd);
		break;
	case SHAPE_S:
		fallS(bd);
		break;
	case SHAPE_Z:
		fallZ(bd);
		break;
	case SHAPE_T:
		fallT(bd);
		break;
	default:
		break;
	}
	return;
}


// 旋转方块
void Rule::whirlSquire(Board& bd)
{
}


void Rule::moveLeft(Board& bd)
{
	switch (m_shape)
	{
	case SHAPE_I:
		moveLeftI(bd);
		break;
	case SHAPE_L:
		moveLeftL(bd);
		break;
	case SHAPE_J:
		moveLeftJ(bd);
		break;
	case SHAPE_S:
		moveLeftS(bd);
		break;
	case SHAPE_Z:
		moveLeftZ(bd);
		break;
	case SHAPE_T:
		moveLeftT(bd);
		break;
	case SHAPE_O:
		moveLeftO(bd);
		break;
	default:
		break;

	}
}


void Rule::moveLeftI(Board& bd)
{
	int i = m_cur_position.x();
	int j = m_cur_position.y();

}


void Rule::moveLeftJ(Board& bd)
{
}


void Rule::moveLeftL(Board& bd)
{
}


void Rule::moveLeftS(Board& bd)
{
}


void Rule::moveLeftZ(Board& bd)
{
}


void Rule::moveLeftT(Board& bd)
{
}


void Rule::moveLeftO(Board& bd)
{
}
