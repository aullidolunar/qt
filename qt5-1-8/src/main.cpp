#include "MyWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	MyTranslatorClass translator(&app);
	MyWindow win(&translator);
	win.show();
	
	return app.exec();
}