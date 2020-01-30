#pragma once

#include "Board.h"
#include "Drawer.h"

typedef enum _DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}DIRECTION;

typedef enum _SHAPE
{
	SHAPE_I,
	SHAPE_J,
	SHAPE_L,
	SHAPE_S,
	SHAPE_Z,
	SHAPE_O,
	SHAPE_T
}SHAPE;

class Rule
{
public:
	Rule(Board &bd, Drawer &dw);
	~Rule();
	void generateSquire();

	// ����I��״����
	int generateI(Board &bd, Drawer &dw, int i = 4, int j = 0);
	// I��������
	void fallI(Board &bd, Drawer &dw, int i = 4, int j = 0);
private:
	int m_fall_speed;
	int m_score;
	static DIRECTION m_statu_I;
	static DIRECTION m_statu_O;
	static DIRECTION m_statu_J;
	static DIRECTION m_statu_L;
	static DIRECTION m_statu_S;
	static DIRECTION m_statu_Z;
	static DIRECTION m_statu_T;
public:
	// �Ƿ񴥵�
	bool isBottomOut(Board &bd, int x, int y, SHAPE shape);
	// �ж�I�����Ƿ񴥵�
	bool isBottomOutShapeI(Board& bd, int i, int j);
	// ������ɷ���
	DIRECTION generateDirection();
	// ��תI����
	void whirlI(Board& bd, int x, int y);
};


