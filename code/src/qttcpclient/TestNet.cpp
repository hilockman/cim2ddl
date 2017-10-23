#include "TestNet.h"
#if _MSC_VER >= 1600      
#pragma execution_character_set("utf-8")      
#endif   

TestNet::TestNet()
{
	server = new QTcpServer(this);
	server->listen(QHostAddress::Any, 8888);
	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(getConnect()));
}

TestNet::~TestNet()
{
}

void TestNet::getConnect()
{
	std::cout << "here_1" << std::endl;
	socket = server->nextPendingConnection();
	std::cout << "here_2" << std::endl;
	std::cout << "here_3" << std::endl;
	//QString strMesg = "Hello,World!是不是？";
	QTextStream os(socket);
	os.setCodec("UTF-8");
	os << QString("Hello,World!是不是？");
	//socket->write(strMesg.toStdString().c_str(), strlen(strMesg.toStdString().c_str()));
}