#include"GoBang.h"
#define HORIZON 0
#define VERTICAL 1
#define LEFTBOTTOMTORIGHTTOP 2
#define LEFTTOPTORIGHTBOTTOM 3

GoBang::GoBang() {

}
bool GoBang::in_board(int Row, int Col) {
	if (Row >= 0 && Row < ROW && Col >= 0 && Col < COL)
		return true;
	return false;
}
bool GoBang::isWin(StoneType* chess_board[ROW][COL], size_t row, size_t col, int chess_color) {
	int TempRow, TempCol;
	int count = 1;
	for (int direct = HORIZON; direct <= LEFTTOPTORIGHTBOTTOM; direct++) {
		for (int i = -4; i <= 4; i++) {
			if (i == 0)
				continue;
			switch (direct) {
			case HORIZON:
				TempRow = row + i;
				TempCol = col;
				break;
			case VERTICAL:
				TempRow = row;
				TempCol = col + i;
				break;
			case LEFTBOTTOMTORIGHTTOP:
				TempRow = row + i;
				TempCol = col - i;
				break;
			case LEFTTOPTORIGHTBOTTOM:
				TempRow = row - i;
				TempCol = col - i;
				break;
			}
			if (in_board(TempRow,TempCol) && chess_board[TempRow][TempCol] != Q_NULLPTR && chess_board[TempRow][TempCol]->get_color() == chess_color)
				count++;
			else
				count = 1;
			if (count == 5)
				return true;
		}
	}
	return false;
}