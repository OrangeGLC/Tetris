#include "Cell.h"
#include <iostream>

#define		DEFAULT_COLOR	(RGB(0,0,0))


Cell::Cell()
	: m_block_color(DEFAULT_COLOR)
	, m_isfull(false)
{
	static int i = 0;
	++i;
	std::cout << this->m_block_color;
	if (i % 10 == 0)
	{
		std::cout << std::endl;
	}

}


Cell::~Cell()
{
}



void Cell::setBlockColor(COLORREF color)
{
	m_block_color = color;
	return;
}


COLORREF Cell::getBlockColor()
{
	return m_block_color;
}




bool Cell::getCellStatu()
{
	return m_isfull;
}


void Cell::setCellStatu(bool statu)
{
	m_isfull = statu;
	return;
}
