#pragma once
#ifndef DATASENDER_H
#define DATASENDER_H

#include <QObject>
#include<QtNetWork>
class DataSender : public QObject
{
	Q_OBJECT

public:
	DataSender(QObject *parent);
	~DataSender();
	int send(const char *data, int len);
private:
	QUdpSocket *socket;
	QHostAddress *host;
	quint16 port;
};
#endif // !DATASENDER_H

