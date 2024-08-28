#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QWidget>
#include "MyTranslator.h"

namespace Ui {
	class FormUI;
};

class MainWindow : public QWidget {
private:
	MyTranslator* m_Translator;
	Ui::FormUI *ui;
public:
	MainWindow(MyTranslator*, QWidget *parent = nullptr);
	virtual ~MainWindow();
protected:
	void showInfo(const QString&);
	void doOK();
};

#endif