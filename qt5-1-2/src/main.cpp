#include <QApplication>
#include <QTranslator>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTranslator translator;
	if (translator.load(QLocale::system().name(), PROGRAM_LOCALEDIR))
	{
		qInfo() << "Loaded";
	}	
	
	app.installTranslator(&translator);
	MainWindow win;
	win.show();
	
    return app.exec();
}
