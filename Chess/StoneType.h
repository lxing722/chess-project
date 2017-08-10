#pragma once
#ifndef STONETYPE_H
#define STONETYPE_H

#include <QGraphicsItem>
#define WHITE 1
#define BLACK 2
class StoneType : public QGraphicsItem
{
public:
	StoneType();//默认构造函数
	StoneType(qreal x, qreal y, int color);//构造函数
	~StoneType();
	QRectF boundingRect() const;   //边界
	QPainterPath shape();   //外形
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);  //画棋子
	int get_color();  //返回棋子的颜色
private:
	qreal radius;	
	int color;
};
#endif // !STONETYPE_H

