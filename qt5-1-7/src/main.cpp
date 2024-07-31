#include <QApplication>
#include "MyWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MyWindow win;
	win.show();
	return app.exec();
}