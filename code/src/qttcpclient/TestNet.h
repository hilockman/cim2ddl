#ifndef _TESTNET_H_
#define _TESTNET_H_

#include <iostream>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>

class TestNet : public QObject
{
	Q_OBJECT
public:
	TestNet();
	~TestNet();
	public slots:
	void getConnect();
private:
	QTcpServer *server;
	QTcpSocket *socket;
};

#endif