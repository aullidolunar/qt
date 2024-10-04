#include "MainWindow.h"
#include <QDebug>

#define TR(str) QObject::tr(str)

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	MyTranslator translator(&app, ":/translations");
	MainWindow mw(&translator);
	qInfo() << PROGRAM_DESC;
	mw.show();
	
	return app.exec();
}
