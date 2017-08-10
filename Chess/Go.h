#pragma once
#ifndef GO_H
#define GO_H
#include "ChessBoard.h"
#define ROW 19
#define COL 19
class Go {
public:
	void kill(ChessBoard* board);  //将棋盘类作为参数传入，因为要用到棋盘的chess_board数组和remove_stone方法
								   //该种方法类似于穷举，遍历每一个子和它所属的块，然后遍历这个块的每个棋子，如果所有棋子都没气，则这整块棋就死了
private:
	void recursion(StoneType* chess_board[ROW][COL], int i, int j);  //用递归的方法将整个块的棋子存入block数组
	bool has_life(StoneType* chess_board[ROW][COL]);   //遍历整个块的棋子，看每个棋子是否有气
	bool in_block(int neighbor);   //判断棋子是否在块内，防止重复将同一个棋子放入块中
	int block[361];		//用于存储棋子坐标
	int block_length = 0;   //整个块棋子的个数

};
#endif // !GO_H

