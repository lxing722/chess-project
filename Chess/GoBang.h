//�������࣬��Ҫ�����ж���Ӯ

#pragma once
#ifndef GOBANG_H
#define GOBANG_H

#include"StoneType.h"
#define ROW 19
#define COL 19

class GoBang {
public:
	//������in_board
	//���ã������ж�������к������Ƿ���������
	//���룺
	//int row, ����
	//int col, ����
	//�����
	//true��false
	//���磺 in_board(3,4) ���� true�� in_board(-1,20) ���� false

	//������isWin
	//���ã������ж���������ʱ�Ƿ�Ӯ����Ϸ
	//���룺
	//StoneType* chess_board[ROW][COL]�� ���ڴ洢���ӵ�����
	//size_t row, ���ӵ����������ڵ���0��С��19��
	//size_t col, ���ӵ����������ڵ���0��С��19)
	//int chess_color, ������ɫ��1��2��
	//�����
	//true��false
	//���磺����������º��������ͬ��ɫ����������һ��ֱ�ߣ��򷵻�true�����򷵻�false

	GoBang();
	bool in_board(int row, int col);   
	bool isWin(StoneType* chess_board[ROW][COL], size_t row, size_t col, int chess_color);  
private:
};
#endif // !GOBANG_H

