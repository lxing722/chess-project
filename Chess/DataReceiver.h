#pragma once
#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include<QtNetWork>
#include<string>
class DataReceiver : public QObject
{
	Q_OBJECT
public slots:
	void read();

public:
	DataReceiver(QObject *parent);
	~DataReceiver();

signals:
	void dataReady(std::string str);

private:
	QUdpSocket *socket;
	QHostAddress *host;
	quint16 port;
};
#endif // !DATARECEIVER_H
