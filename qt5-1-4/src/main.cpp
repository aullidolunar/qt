#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTranslator translator;
	if (translator.load(QLocale::system().name(), ":/translations"))
	{
		qInfo() << "Loaded";
	}	
	
	app.installTranslator(&translator);
	MainWindow win(&translator);
	win.show();
	
    return app.exec();
}
