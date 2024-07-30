#include <QApplication>
#include "MyWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MyWindow win(PACKAGE_TITLE);
	win.show();
	return app.exec();
}