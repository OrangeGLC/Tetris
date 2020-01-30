#include "Cell.h"
#include <iostream>

#define		DEFAULT_COLOR	(RGB(0,0,0))


Cell::Cell()
	: m_block_color(DEFAULT_COLOR)
	, m_isfull(false)
{
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
