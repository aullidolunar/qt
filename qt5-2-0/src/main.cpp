#include "MainWindow.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	
	MyTranslator translator(&app);
	MainWindow mw(&translator);
	mw.show();
	
	return app.exec();
}
