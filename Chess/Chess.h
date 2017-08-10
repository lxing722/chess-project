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
	//������send_text
	//���ã�������Ϣ�༭�����������Ϣ��������Է�ʵʱ����

	//������receive_text
	//���ã������յ�����Ϣ������������Ϣ�͸���Ӧ�ý�����Ϣ��������Ӧ�Ĵ���
	//���룺�ַ���
	//���磺����յ����ǶԷ���ʵʱ������Ϣ�����������Ϣ��ʾ����
	//     ����յ�����Ӧ�ý�����Ϣ����Է��������¿�ʼ��Ϸ���򵯳���ʾ�����ȷ���Ƿ�ͬ�����¿�ʼ��Ϸ���ٸ���ѡ�������Ӧ�Ĵ���

	//������set_restart
	//���ã����¿�ʼ��Ϸ,�����ø������������

	//������ask_for_restart
	//���ã��������¿�ʼ��Ϸ

	//������choose_go
	//���ã�����Ϸģʽ����ΪΧ��

	//����:choose_go_bang
	//���ã�����Ϸģʽ����Ϊ������

	//������take_back_stone
	//���ã����壬����ֵ��Է����ӣ������������壬��������һ�������ջأ�������ֵ��Լ����ӣ����޷�����

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
	void board_clicked(size_t row, size_t col);  //�������ʱ��Ӧ�Ĳ���
	

private:
	QPushButton *send;   //���ڷ�����Ϣ
	QPushButton *go_bang;  //����ѡ��������
	QPushButton *go;   //ѡ��Χ��
	QPushButton *take_back;   //����
	QPushButton *restart;  //���¿�ʼ��Ϸ
	QLineEdit *text;   //�༭Ҫ���͵���Ϣ
	QLabel *received_text;   //������Ϣ��ʾ��
	QLabel *warning_box;   //��Ϣ��ʾ��
	DataSender *sender;  //������Ϣ��
	DataReceiver *receiver;   //������Ϣ��
	ChessBoard *board;  //������
	chess_type type;  //��Ϸ���࣬���������Χ�����������
	GoBang go_bang_;   //�����ж���������Ӯ
	Go go_;            //����Χ������
	bool color_setted;  //������ɫ�Ƿ��Ѿ��趨
	bool my_turn;   //�Ƿ��ֵ���������
	int color;   //������ɫ
	int temp_row, temp_col;   //�����ݴ���һ���������ӵ�λ�ã����ڻ������
};
#endif // !CHESS_H

