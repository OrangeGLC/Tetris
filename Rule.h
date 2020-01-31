#pragma once

#include "Board.h"
#include "Drawer.h"
#include "Coordinate.h"

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
	Rule(Board &bd);
	~Rule();

	// ���ɲ�ͬ��״��״����
	int generateSquire(Board &bd);
	void generateI(Board &bd);
	void generateO(Board &bd);
	void generateL(Board &bd);
	void generateJ(Board &bd);
	void generateS(Board &bd);
	void generateZ(Board &bd);
	void generateT(Board &bd);
	// �Ƿ񴥵�
	bool isBottomOut(Board &bd);
	// �ж�I�����Ƿ񴥵�
	bool isBottomOutShapeI(Board& bd);
	// ������ɷ���
	DIRECTION generateDirection();
	// ��ת����
	void whirlSquire(Board& bd);
	void whirlI(Board& bd);

	void runGame(Board &bd);
	bool isGameOver(Board& bd);

	//��������
	int fallSquire(Board &bd);
	void fallI(Board &bd);
	void fallO(Board &bd);
	void fallJ(Board &bd);
	void fallL(Board &bd);
	void fallZ(Board &bd);
	void fallS(Board &bd);
	void fallT(Board &bd);

private:
	int m_fall_speed;
	int m_score;
	DIRECTION m_direct;
	SHAPE m_shape;
	Coordinate m_cur_position;
public:
	
	
};


