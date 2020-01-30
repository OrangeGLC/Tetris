#include "Board.h"
#include <iostream>


Board::Board()
{
	for (int i = 0; i < getBoardWidth(); ++i)
	{
		for (int j = 0; j < getBoardHight(); ++j)
		{
			m_board[i][j].setCellStatu(false);
			m_board[i][j].setBlockColor(RGB(90, 13, 67));
		}
	}
}


Board::~Board()
{
}


void Board::clearBoard()
{
	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HIGHT; ++j)
		{
			m_board[i][j].setCellStatu(false);
		}
	}
}



int Board::getBoardHight()
{
	return sizeof(m_board[0]) / sizeof(m_board[0][0]);
}


int Board::getBoardWidth()
{
	return sizeof(m_board) / sizeof(m_board[0]);
}


COLORREF Board::getCellColor(int x, int y)
{
	return m_board[x][y].getBlockColor();
}


bool Board::getCellStatus(int x, int y)
{
	return m_board[x][y].getCellStatu();
}


void Board::setCellStatu(int x, int y, bool statu)
{
	m_board[x][y].setCellStatu(statu);
	return;
}


int Board::setCellColor(int x, int y, COLORREF color)
{
	m_board[x][y].setBlockColor(color);
	return 0;
}

