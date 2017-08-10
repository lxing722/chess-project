#include "StoneType.h"
#include<QPainter>
StoneType::StoneType() {

}
StoneType::StoneType(qreal x, qreal y, int color)
{
	setPos(x, y);
	this->color = color;
	radius = 30;
}

StoneType::~StoneType()
{
}
QRectF StoneType::boundingRect() const{
	return QRectF(0, 0, radius, radius);
}
QPainterPath StoneType::shape() {
	QPainterPath path;
	path.addEllipse(0, 0, radius, radius);
	return path;
}
void StoneType::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->save();
	if (color == WHITE)
		painter->fillPath(shape(), Qt::white);
	else
		painter->fillPath(shape(), Qt::black);
	painter->restore();
}
int StoneType::get_color() {
	return color;
}
