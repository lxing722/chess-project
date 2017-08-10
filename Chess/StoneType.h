#pragma once
#ifndef STONETYPE_H
#define STONETYPE_H

#include <QGraphicsItem>
#define WHITE 1
#define BLACK 2
class StoneType : public QGraphicsItem
{
public:
	StoneType();//Ĭ�Ϲ��캯��
	StoneType(qreal x, qreal y, int color);//���캯��
	~StoneType();
	QRectF boundingRect() const;   //�߽�
	QPainterPath shape();   //����
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);  //������
	int get_color();  //�������ӵ���ɫ
private:
	qreal radius;	
	int color;
};
#endif // !STONETYPE_H

