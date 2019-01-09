#include "ftpclient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FTPclient w;
	w.show();
	return a.exec();
}
