//五子棋类，主要用于判定输赢

#pragma once
#ifndef GOBANG_H
#define GOBANG_H

#include"StoneType.h"
#define ROW 19
#define COL 19

class GoBang {
public:
	//函数：in_board
	//作用：用于判定输入的行和列数是否在棋盘内
	//输入：
	//int row, 行数
	//int col, 列数
	//输出：
	//true或false
	//例如： in_board(3,4) 返回 true， in_board(-1,20) 返回 false

	//函数：isWin
	//作用：用于判定棋子落下时是否赢得游戏
	//输入：
	//StoneType* chess_board[ROW][COL]， 用于存储棋子的数组
	//size_t row, 落子的行数（大于等于0，小于19）
	//size_t col, 落子的列数（大于等于0，小于19)
	//int chess_color, 棋子颜色（1或2）
	//输出：
	//true或false
	//例如：如果棋子落下后有五个相同颜色的棋子练成一条直线，则返回true，否则返回false

	GoBang();
	bool in_board(int row, int col);   
	bool isWin(StoneType* chess_board[ROW][COL], size_t row, size_t col, int chess_color);  
private:
};
#endif // !GOBANG_H

