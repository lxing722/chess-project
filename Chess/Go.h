#pragma once
#ifndef GO_H
#define GO_H
#include "ChessBoard.h"
#define ROW 19
#define COL 19
class Go {
public:
	void kill(ChessBoard* board);  //����������Ϊ�������룬��ΪҪ�õ����̵�chess_board�����remove_stone����
								   //���ַ�����������٣�����ÿһ���Ӻ��������Ŀ飬Ȼ�����������ÿ�����ӣ�����������Ӷ�û�������������������
private:
	void recursion(StoneType* chess_board[ROW][COL], int i, int j);  //�õݹ�ķ���������������Ӵ���block����
	bool has_life(StoneType* chess_board[ROW][COL]);   //��������������ӣ���ÿ�������Ƿ�����
	bool in_block(int neighbor);   //�ж������Ƿ��ڿ��ڣ���ֹ�ظ���ͬһ�����ӷ������
	int block[361];		//���ڴ洢��������
	int block_length = 0;   //���������ӵĸ���

};
#endif // !GO_H

