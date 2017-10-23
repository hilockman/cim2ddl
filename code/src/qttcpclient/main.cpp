#include <QTcpSocket>
#include <QCoreApplication>
#include <QHostAddress>
#include <QIODevice>
#include <QDataStream>
#include <QTextCodec>
#if _MSC_VER >= 1600      
#pragma execution_character_set("utf-8")      
#endif   
int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
		QTcpSocket s;
		s.connectToHost(QHostAddress("127.0.0.1"), 6666, QIODevice::WriteOnly);

		//QString strMesg = "Hello,World!";
		//s.write(strMesg.toStdString().c_str(), strlen(strMesg.toStdString().c_str()));
		QTextStream ss(&s);
		ss.setCodec("utf-8");


		ss << "hello!";
		ss << "fsdfsdfdsfs";
		ss << QString("中国");
		ss.flush();
		s.close();
		//QDataStream ds(&s);
		//ds << "hello";
	

	
	app.exec();
	return 0;
}

//#include "TestNet.h"
//
////#include <QtGui/QApplication>
//int main(int argc, char *argv[])
//{
//	QCoreApplication a(argc, argv);
//	QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
//	TestNet *test = new TestNet();
//	return a.exec();
//}