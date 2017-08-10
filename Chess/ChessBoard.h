/*
*�����ǻ���ͼ����ͼ��ܽ����ģ��������ڷ��ú�ɾ������
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
	//������draw_board
	//���ã���һ�����̣�����������ʾ

	//������clear
	//���ã��������ϵ����Ӷ�������������ڴ洢���ӵ����鶼�ÿ�

	//������put_stone
	//���ã����ڽ����ӷ��õ�������
	//���룺
	//sizt_t row, Ҫ���ӵ����� ��ֵ���ڵ���0��С�����̵���������
	//sizt_t col, ���ӵ�������ֵ���ڵ���0��С�����̵���������
	//int color, ���ӵ���ɫ������ǰ���define��ֵΪ1��2��
	
	//������remove_stone
	//���ã��Ƴ������ϵ�����
	//���룺
	//sizt_t row, Ҫ���ӵ����� ��ֵ���ڵ���0��С�����̵���������
	//sizt_t col, ���ӵ�������ֵ���ڵ���0��С�����̵���������

	//���飺chess_board
	//���ã����ڴ洢����

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
	void mousePressEvent(QMouseEvent *e);   //������¼������ź�clicked������������������к���
private:
	size_t row;
	size_t col;

	size_t row_pix;
	size_t col_pix;

	static const size_t padding = 50;
	static const size_t interval = 40;
	QPixmap pix;

	QGraphicsScene *scene;   //����
	QGraphicsView *view;   //��ͼ
	StoneType *stone;
};
#endif // !CHESSBOARD_H
