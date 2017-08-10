#include "DataReceiver.h"

DataReceiver::DataReceiver(QObject *parent)
	: QObject(parent)
{
	socket = new QUdpSocket();
	host = new QHostAddress("127.0.0.1");
	port = 7777;
	socket->bind(*host, port);
	connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
}

DataReceiver::~DataReceiver()
{
	delete socket;
	delete host;
}
void DataReceiver::read()
{
	QByteArray data;
	data.resize(socket->pendingDatagramSize());
	socket->readDatagram(data.data(), data.size());
	std::string str(data.data(), data.size());
	emit dataReady(str);
}
