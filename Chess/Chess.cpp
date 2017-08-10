#include "Chess.h"
#include<QPainter>
#include"json.h"
#include<QMessageBox>
Chess::Chess(QWidget *parent)
	: QMainWindow(parent)
{
	temp_row = temp_col = -1;
	color_setted = false;
	my_turn = true;
	color = BLACK;
	type = none;
	go_bang_ = GoBang();
	go_ = Go();

	send = new QPushButton("Send");
	go_bang = new QPushButton("Go bang");
	go = new QPushButton("Go");
	take_back = new QPushButton("Take back");
	restart = new QPushButton("Restart");

	text = new QLineEdit();
	received_text = new QLabel();
	warning_box = new QLabel();
	received_text->setMinimumWidth(200);
	sender = new DataSender(this);
	receiver = new DataReceiver(this);
	board = new ChessBoard(19, 19, this);
	board->draw_board();
	QWidget *centerWindow = new QWidget();
	this->setCentralWidget(centerWindow);

	QGridLayout *left_layout = new QGridLayout();
	left_layout->addWidget(warning_box, 0, 0, 1, 1);
	left_layout->addWidget(board, 1, 0, 2, 2);
	left_layout->addWidget(received_text, 3, 0, 1, 1);
	left_layout->addWidget(text, 4, 0, 1, 1);
	QVBoxLayout *right_layout = new QVBoxLayout();
	right_layout->addWidget(go);
	right_layout->addWidget(go_bang);
	right_layout->addWidget(take_back);
	right_layout->addWidget(restart);
	right_layout->addStretch();
	right_layout->addWidget(send);

	QHBoxLayout *main_layout = new QHBoxLayout();
	main_layout->addLayout(left_layout);
	main_layout->addLayout(right_layout);

	centerWindow->setLayout(main_layout);

	connect(receiver, SIGNAL(dataReady(std::string)), this, SLOT(receive_text(std::string)));
	connect(board, &ChessBoard::clicked, this, &Chess::board_clicked);
	connect(restart, SIGNAL(clicked()), this, SLOT(ask_for_restart()));
	connect(send, SIGNAL(clicked()), this, SLOT(send_text()));
	connect(go, SIGNAL(clicked()), this, SLOT(choose_go()));
	connect(go_bang, SIGNAL(clicked()), this, SLOT(choose_go_bang()));
	connect(take_back, SIGNAL(clicked()), this, SLOT(take_back_stone()));

}

Chess::~Chess() {
	delete send;
	delete go_bang;
	delete go;
	delete restart;
	delete text;
	delete received_text;
	delete warning_box;
	delete sender;
	delete receiver;
	delete board;
}
void Chess::take_back_stone() {
	if (my_turn == false) {
		JSONObject take_stone;
		take_stone["keyword"] = "take_back_stone";
		take_stone["row"] = temp_row;
		take_stone["col"] = temp_col;
		sender->send(take_stone.to_json().c_str(), take_stone.to_json().length());
	}
	else {
		if (type == none) {
			warning_box->setText("Please choose a game!");
		}
		else if (temp_row == -1) {
			warning_box->setText("You haven't placed chess yet!");
		}
		else
			warning_box->setText("It's your turn!");
	}
}
void Chess :: choose_go() {  //选择玩围棋，给对方发送请求信息，对方同意，游戏开始
	if (type == none) {
		JSONObject ask_go;
		ask_go["keyword"] = "ask_go";
		sender->send(ask_go.to_json().c_str(), ask_go.to_json().length());
	}
	else
		warning_box->setText("Game has started!");
}
void Chess::choose_go_bang() {
	if (type == none) {
		JSONObject ask_go_bang;
		ask_go_bang["keyword"] = "ask_go_bang";
		sender->send(ask_go_bang.to_json().c_str(), ask_go_bang.to_json().length());
	}
	else
		warning_box->setText("Game has started!");
}

void Chess::ask_for_restart() {
	JSONObject ask_restart;
	ask_restart["keyword"] = "restart";
	sender->send(ask_restart.to_json().c_str(), ask_restart.to_json().length());
}

void Chess::set_restart() {   //重新开始重置各项参数
	type = none;     //棋种置零
	color_setted = false;   
	my_turn = true;
	color = BLACK;
	board->clear();
}

void Chess::send_text() {
	JSONObject message;
	message["keyword"] = "message";
	message["message"] = text->text().toStdString();
	sender->send(message.to_json().c_str(), message.to_json().length());
}

void Chess::receive_text(std::string str) {
	int a = 0;
	JSONObject read_obj = read_object(str, a);  //每个json设置一个keyword，判断是对方发送的信息，设置棋子颜色，还是对方落子的坐标
	if (read_obj["keyword"].to_string() == "message")
		received_text->setText(QString::fromStdString(read_obj["message"].to_string()));
	else if (read_obj["keyword"].to_string() == "set_color")
		color_setted = true;
	else if (read_obj["keyword"].to_string() == "place_chess") {
		size_t row = read_obj["row"].to_int();
		size_t col = read_obj["col"].to_int();
		int chess_color = read_obj["color"].to_int();
		board->put_stone(row, col, chess_color);
		my_turn = true;
		QString str = QString("(%1, %2)").arg(char('A' + row)).arg(QString::number(col + 1));
		warning_box->setText(str);
		if (type == go_game)
			go_.kill(board);
	}
	else if (read_obj["keyword"].to_string() == "restart") {
		JSONObject reply;
		reply["keyword"] = "reply";
		QMessageBox warning(QMessageBox::Warning, "Ask for restart", "Your partner want to restart. Do you agree?", QMessageBox::Yes | QMessageBox::No);
		if(warning.exec() == QMessageBox::Yes){			
			reply["reply"] = "yes";
			sender->send(reply.to_json().c_str(), reply.to_json().length());
			set_restart();
		}
		else {
			reply["reply"] = "no";
			sender->send(reply.to_json().c_str(), reply.to_json().length());
		}
	}
	else if (read_obj["keyword"].to_string() == "reply") {
		if (read_obj["reply"].to_string() == "yes") {
			warning_box->setText("Your partner agree to restart! ");
			set_restart();
		}
		else {
			warning_box->setText("Your partner refuse to restart! ");
		}
	}

	else if (read_obj["keyword"].to_string() == "ask_go") {
		JSONObject reply_go;
		reply_go["keyword"] = "reply_go";
		QMessageBox warning(QMessageBox::Warning, "Choose go", "Your partner want to play go. Do you agree?", QMessageBox::Yes | QMessageBox::No);
		if (warning.exec() == QMessageBox::Yes) {
			reply_go["reply"] = "yes";
			sender->send(reply_go.to_json().c_str(), reply_go.to_json().length());
			type = go_game;
		}
		else {
			reply_go["reply"] = "no";
			sender->send(reply_go.to_json().c_str(), reply_go.to_json().length());
		}
	}
	else if (read_obj["keyword"].to_string() == "ask_go_bang") { //回应是否玩五子棋
		JSONObject reply_go_bang;
		reply_go_bang["keyword"] = "reply_go_bang";
		QMessageBox warning(QMessageBox::Warning, "Choose go bang", "Your partner want to play go bang. Do you agree?", QMessageBox::Yes | QMessageBox::No);
		if (warning.exec() == QMessageBox::Yes) {
			reply_go_bang["reply"] = "yes";  //同意，则回复同意信息，同时将游戏模式设置为五子棋
			sender->send(reply_go_bang.to_json().c_str(), reply_go_bang.to_json().length());
			type = go_bang_game;
		}
		else {
			reply_go_bang["reply"] = "no";
			sender->send(reply_go_bang.to_json().c_str(), reply_go_bang.to_json().length());
		}
	}
	else if (read_obj["keyword"].to_string() == "reply_go") {
		if (read_obj["reply"].to_string() == "yes") {
			warning_box->setText("Your partner agree to play go! Game starts now! ");
			type = go_game;
		}
		else {
			warning_box->setText("Your partner don't want to play go! ");
		}
	}
	else if (read_obj["keyword"].to_string() == "reply_go_bang") {
		if (read_obj["reply"].to_string() == "yes") {
			warning_box->setText("Your partner agree to play go bang! Game starts now! ");
			type = go_bang_game;
		}
		else {
			warning_box->setText("Your partner don't want to play go bang! ");
		}
	}
	else if (read_obj["keyword"].to_string() == "over") {
		type = game_over;
		if (color == WHITE) {
			warning_box->setText("Black Win! Game over!");
		}
		else
			warning_box->setText("White Win! Game over!");
	}
	else if (read_obj["keyword"].to_string() == "take_back_stone") {
		JSONObject reply_take_back;
		reply_take_back["keyword"] = "reply_take_back";
		QMessageBox warning(QMessageBox::Warning, "Choose go bang", "Your partner want to play go bang. Do you agree?", QMessageBox::Yes | QMessageBox::No);
		if (warning.exec() == QMessageBox::Yes) {
			board->remove_stone(read_obj["row"].to_int(), read_obj["col"].to_int());
			my_turn = false;
			reply_take_back["reply"] = "yes";
			sender->send(reply_take_back.to_json().c_str(), reply_take_back.to_json().length());
		}
		else {
			reply_take_back["reply"] = "no";
			sender->send(reply_take_back.to_json().c_str(), reply_take_back.to_json().length());
		}
	}
	else if (read_obj["keyword"].to_string() == "reply_take_back") {
		if (read_obj["reply"].to_string() == "yes") {
			board->remove_stone(temp_row, temp_col);
			my_turn = true;
		}
	}
}

void Chess::board_clicked(size_t row, size_t col) {
	if (!color_setted) {   //用于判断是否是第一个落子
		color = WHITE;   //设定第一个落子的执白子
		color_setted = true;
		JSONObject set_color;
		set_color["keyword"] = "set_color";   //通知对方本方已先落子，将对方棋子设置成黑
		sender->send(set_color.to_json().c_str(), set_color.to_json().length());
	}
	if (type != none && type != game_over && my_turn) {
		if (board->chess_board[row][col] == Q_NULLPTR) {
			temp_row = row;
			temp_col = col;
			board->put_stone(row, col, color);
			my_turn = false;
			JSONObject place_chess;
			place_chess["keyword"] = "place_chess";
			place_chess["row"] = (int)row;
			place_chess["col"] = (int)col;
			place_chess["color"] = color;
			sender->send(place_chess.to_json().c_str(), place_chess.to_json().length());		
		}
		else
			warning_box->setText("Here is taken!");
		if (type == go_bang_game) {  //五子棋
			if (go_bang_.isWin(board->chess_board, row, col, color)) {
				type = game_over;
				JSONObject over;
				over["keyword"] = "over";
				sender->send(over.to_json().c_str(), over.to_json().length());
				if (color == WHITE)
					warning_box->setText("White Win! Game over!");
				else
					warning_box->setText("Black Win! Game over!");
			}
		}
		else if (type == go_game) {  //围棋
			go_.kill(board);   //提子
		}
	}
	else {
		if (type == none)
			warning_box->setText("Please choose a game!");
		else if(type == game_over)
			warning_box->setText("Game over!");
		else if(!my_turn)
			warning_box->setText("It's not your turn!");
	}

}

