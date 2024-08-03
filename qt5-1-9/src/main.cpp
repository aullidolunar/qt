#include "MyWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	//MyTranslatorClass translator(&app, PROGRAM_QMDIR);
	MyTranslatorClass translator(&app, ":/translations");
	MyWindow win(&translator);
	win.show();
	
	return app.exec();
}