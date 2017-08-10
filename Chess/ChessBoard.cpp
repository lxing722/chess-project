#include"ChessBoard.h"
#include<math.h>
#include<QMessageBox>
#define CHESS_SIZE 30

ChessBoard::ChessBoard(size_t row, size_t col, QWidget *parent)
	: QLabel(parent)
{
	stone = Q_NULLPTR;
	this->row = row;
	this->col = col; 
	row_pix = padding * 2 + interval*(row - 1);
	col_pix = padding * 2 + interval*(col - 1);
	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, row_pix, col_pix);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	view = new QGraphicsView(scene, this);
	view->resize(row_pix + 5, col_pix + 5);
	pix = QPixmap(row_pix, col_pix);
}

ChessBoard::~ChessBoard()
{
	delete scene;
	delete view;
}

void ChessBoard::draw_board() {	
	QPainter painter(&pix);
	painter.setPen(QColor(0, 0, 0));
	pix.fill(QColor(245, 222, 179));
	for (int i = 0; i < row; i++) {
		painter.drawLine(padding, padding + interval*i, col_pix - padding, padding + interval*i);
	}
	for (int j = 0; j < col; j++) {
		painter.drawLine(padding + interval*j, padding, padding + interval*j, row_pix - padding);
	}
	painter.setBrush(Qt::black);
	for (int k = 0; k < 3; k++) {
		for (int m = 0; m < 3; m++) {
			painter.drawEllipse(padding + interval*(3 + 6 * k) - 3, padding + interval*(3 + 6 * m) - 3, 6, 6);
		}
	}
	for (int i = 0; i < 19; i++) {
		painter.drawText(padding + interval*i - 3, padding / 2 + 3, QString("%1").arg(QString::number(i+1)));
		painter.drawText(padding / 2 - 5, padding + interval*i + 5, QString("%1").arg(char('A' + i)));
	}
	this->setPixmap(pix);
	scene->setBackgroundBrush(QBrush(pix));	//以pix为背景铺满整个场景
}

void ChessBoard::put_stone(size_t row, size_t col, int color) {
	stone = new StoneType(padding + col*interval - 15, padding + row*interval - 15, color);
	scene->addItem(stone);
	chess_board[row][col] = stone;
	stone = Q_NULLPTR;
}

void ChessBoard::clear() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (chess_board[i][j] != Q_NULLPTR) {
				remove_stone(i, j);
			}
		}
	}
}

void ChessBoard::remove_stone(size_t row, size_t col) {
	scene->removeItem(chess_board[row][col]);
	delete chess_board[row][col];
	chess_board[row][col] = Q_NULLPTR;
}

void ChessBoard::mousePressEvent(QMouseEvent *e) {	
	if (e->pos().x() < col_pix - padding + interval / 2 && e->pos().x() > padding - interval / 2 &&
		e->pos().y() < row_pix - padding + interval / 2 && e->pos().y() > padding - interval / 2) {  //设定鼠标有效点击区域在棋盘内
		size_t row, col;

		row = (std::fabs(e->pos().y() - int(padding)) / interval + 0.5);
		col = (std::fabs(e->pos().x() - int(padding)) / interval + 0.5);

		emit clicked(row, col);
	}
}
