#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QTranslator translator;
	QString lang = QLocale::system().name();
	translator.load(lang, ":/translations");
	app.installTranslator(&translator);
	qInfo() << QObject::tr("Loaded:") << lang;
	MainWindow win(&translator);
	
	win.show();
	
    return app.exec();
}
