#include "MainWindow.h"
#include <QDebug>
#ifdef Q_OS_WIN
#include <windows.h>
#endif

int main(int argc, char** argv) {
  
  QApplication app(argc, argv);
	MyTranslator translator(&app, ":/translations");
	MainWindow mw(&translator);
#ifdef Q_OS_WIN
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), PROGRAM_DESC.utf16(), PROGRAM_DESC.length(), nullptr, nullptr);
#else
  qInfo() << PROGRAM_DESC;
#endif
	mw.show();
	
	return app.exec();
}
