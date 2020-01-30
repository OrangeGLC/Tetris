#pragma once
#include <graphics.h> 

class Cell
{
public:
	Cell();
	~Cell();
	void		setBlockColor(COLORREF color);
	COLORREF	getBlockColor();
	bool		getCellStatu();
	void		setCellStatu(bool statu);

private:
	
	bool		m_isfull;
	COLORREF	m_block_color;

};

