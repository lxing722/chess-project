/*
*棋盘是基于图形视图框架建立的，这样便于放置和删除棋子
*/

#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "StoneType.h"
#include <QGraphicsItem>

#define ROW 19
#define COL 19
#define WHITE 1
#define BLACK 2
class ChessBoard : public QLabel
{
	Q_OBJECT
public:
	//函数：draw_board
	//作用：画一个棋盘，并将棋盘显示

	//函数：clear
	//作用：将棋盘上的棋子都清除，并将用于存储棋子的数组都置空

	//函数：put_stone
	//作用：用于将棋子放置到棋盘上
	//输入：
	//sizt_t row, 要落子的行数 （值大于等于0，小于棋盘的总行数）
	//sizt_t col, 落子的列数（值大于等于0，小于棋盘的总行数）
	//int color, 棋子的颜色（按照前面的define，值为1或2）
	
	//函数：remove_stone
	//作用：移除棋盘上的棋子
	//输入：
	//sizt_t row, 要落子的行数 （值大于等于0，小于棋盘的总行数）
	//sizt_t col, 落子的列数（值大于等于0，小于棋盘的总行数）

	//数组：chess_board
	//作用：用于存储棋子

	ChessBoard(size_t row, size_t col, QWidget *parent);
	~ChessBoard();
	void draw_board(); 
	void clear();   
	void put_stone(size_t row, size_t col, int color);  
	void remove_stone(size_t row, size_t col);   
	StoneType* chess_board[ROW][COL] = { Q_NULLPTR };  
signals:
	void clicked(size_t row, size_t col);
protected:
	void mousePressEvent(QMouseEvent *e);   //鼠标点击事件，与信号clicked相连，发送鼠标点击的行和列
private:
	size_t row;
	size_t col;

	size_t row_pix;
	size_t col_pix;

	static const size_t padding = 50;
	static const size_t interval = 40;
	QPixmap pix;

	QGraphicsScene *scene;   //场景
	QGraphicsView *view;   //视图
	StoneType *stone;
};
#endif // !CHESSBOARD_H
