#pragma once
class Coordinate
{
public:
	Coordinate();
	Coordinate(int x, int y);
	~Coordinate();
	int x();
	int y();
	void x(int x);
	void y(int y);
private:
	int m_x;
	int m_y;

	
};

