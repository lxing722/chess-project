#include "DataSender.h"

DataSender::DataSender(QObject *parent)
	: QObject(parent)
{
	socket = new QUdpSocket();
	host = new QHostAddress();
	host->setAddress("127.0.0.1");
	port = 6666;
}

DataSender::~DataSender()
{
	delete socket;
	delete host;
}
int DataSender::send(const char *data, int len) {
	return socket->writeDatagram(data, (quint64)len, *host, port);
}
