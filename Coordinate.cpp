#include "Coordinate.h"



Coordinate::Coordinate()
	: m_x(0)
	, m_y(0)
{
}


Coordinate::~Coordinate()
{
}


int Coordinate::x()
{
	return m_x;
}


int Coordinate::y()
{
	return m_y;
}


Coordinate::Coordinate(int x, int y)
	:m_x(x)
	,m_y(y)
{
}


void Coordinate::x(int x)
{
	m_x = x;
	return;
}


void Coordinate::y(int y)
{
	m_y = y;
	return;
}
