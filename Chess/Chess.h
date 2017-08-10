#pragma once
#ifndef CHESS_H
#define CHESS_H

#include <QtWidgets/QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QLineEdit>
#include"DataReceiver.h"
#include"DataSender.h"
#include"ChessBoard.h"
#include"GoBang.h"
#include"StoneType.h"
#include"Go.h"
#define ROW 19
#define COL 19
#define WHITE 1
#define BLACK 2

enum chess_type { none, go_game, go_bang_game, game_over };

class Chess : public QMainWindow
{
	Q_OBJECT
public slots:
	//函数：send_text
	//作用：发送消息编辑框内输入的信息，用于与对方实时聊天

	//函数：receive_text
	//作用：根据收到的信息（包括聊天信息和各种应用交互信息）进行相应的处理
	//输入：字符串
	//例如：如果收到的是对方的实时聊天信息，则输出在消息显示框内
	//     如果收到的是应用交互信息，如对方请求重新开始游戏，则弹出显示框进行确认是否同意重新开始游戏，再根据选择进行相应的处理

	//函数：set_restart
	//作用：重新开始游戏,并重置各项参数和棋盘

	//函数：ask_for_restart
	//作用：请求重新开始游戏

	//函数：choose_go
	//作用：将游戏模式设置为围棋

	//函数:choose_go_bang
	//作用：将游戏模式设置为五子棋

	//函数：take_back_stone
	//作用：悔棋，如果轮到对方落子，则可以请求悔棋，将最近落得一个棋子收回，如果是轮到自己落子，则无法悔棋

	void send_text();   
	void receive_text(std::string str);   
	void set_restart();   
	void ask_for_restart();   
	void choose_go();   
	void choose_go_bang();   
	void take_back_stone();   
public:
	Chess(QWidget *parent = Q_NULLPTR);
	~Chess();
	void board_clicked(size_t row, size_t col);  //点击棋盘时对应的操作
	

private:
	QPushButton *send;   //用于发送信息
	QPushButton *go_bang;  //用于选择五子棋
	QPushButton *go;   //选择围棋
	QPushButton *take_back;   //悔棋
	QPushButton *restart;  //重新开始游戏
	QLineEdit *text;   //编辑要发送的信息
	QLabel *received_text;   //聊天消息显示框
	QLabel *warning_box;   //信息提示框
	DataSender *sender;  //发送信息类
	DataReceiver *receiver;   //接收信息类
	ChessBoard *board;  //棋盘类
	chess_type type;  //游戏种类，五子棋或者围棋或者无种类
	GoBang go_bang_;   //用于判定五子棋输赢
	Go go_;            //用于围棋提子
	bool color_setted;  //棋子颜色是否已经设定
	bool my_turn;   //是否轮到本方下子
	int color;   //棋子颜色
	int temp_row, temp_col;   //用于暂存上一步所下棋子的位置，便于悔棋操作
};
#endif // !CHESS_H

