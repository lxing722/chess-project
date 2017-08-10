#include"Go.h"
void Go::kill(ChessBoard* board) {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board->chess_board[i][j] == nullptr)
				continue;
			else {
				block_length = 1;
				block[0] = i * 100 + j;

				recursion(board->chess_board, i, j);

				if (has_life(board->chess_board))
					continue;
				else {
					for (int t = 0; t < block_length; t++)
						board->remove_stone(block[t] / 100, block[t] % 100);
				}
			}
		}
	}
}

void Go::recursion(StoneType* chess_board[ROW][COL], int i, int j) {
	//Left
	if (i - 1 >= 0 && (chess_board[i - 1][j]!=nullptr && chess_board[i][j] != nullptr && chess_board[i - 1][j]->get_color() == chess_board[i][j]->get_color()) && !in_block((i - 1) * 100 + j)) {
		block[block_length] = (i - 1) * 100 + j;
		block_length++;
		recursion(chess_board, i - 1, j);
	}
	//Up
	if (j - 1 >= 0 && (chess_board[i][j - 1] != nullptr && chess_board[i][j] != nullptr && chess_board[i][j - 1]->get_color() == chess_board[i][j]->get_color()) && !in_block(i * 100 + j - 1)) {
		block[block_length] = i * 100 + j - 1;
		block_length++;
		recursion(chess_board, i, j - 1);
	}
	//Right
	if (i + 1 < 19 && (chess_board[i + 1][j] != nullptr && chess_board[i][j] != nullptr && chess_board[i + 1][j]->get_color() == chess_board[i][j]->get_color()) && !in_block((i + 1) * 100 + j)) {
		block[block_length] = (i + 1) * 100 + j;
		block_length++;
		recursion(chess_board, i + 1, j);
	}
	//Down
	if (j + 1 < 19 && (chess_board[i][j + 1] != nullptr && chess_board[i][j] != nullptr && chess_board[i][j + 1]->get_color() == chess_board[i][j]->get_color()) && !in_block(i * 100 + j + 1)) {
		block[block_length] = i * 100 + j + 1;
		block_length++;
		recursion(chess_board, i, j + 1);
	}
}

bool Go::has_life(StoneType* chess_board[ROW][COL]) {
	int i, j;
	for (int t = 0; t < block_length; t++) {
		i = block[t] / 100;
		j = block[t] % 100;
		if (i - 1 >= 0 && chess_board[i - 1][j] == nullptr) return true;
		if (i + 1 < 19 && chess_board[i + 1][j] == nullptr) return true;
		if (j - 1 >= 0 && chess_board[i][j - 1] == nullptr) return true;
		if (j + 1 < 19 && chess_board[i][j + 1] == nullptr) return true;
	}
	return false;
}

bool Go::in_block(int neighbor) {
	for (int i = 0; i < block_length; i++)
	{
		if (block[i] == neighbor) return true;
	}
	return false;
}