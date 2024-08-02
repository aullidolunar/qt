#ifndef _MYWINDOW_H
#define _MYWINDOW_H

#include <QMessageBox>
#include "MyTranslatorClass.h"

namespace Ui {
    class MainWindowUI;
}

class MyWindow : public QWidget
{
private:
	Q_DECLARE_TR_FUNCTIONS(MyWindow)
	Ui::MainWindowUI *ui;
	MyTranslatorClass *m_ptc;
	int m_savedIndex;
public:
	MyWindow(MyTranslatorClass*, QWidget* parent = nullptr);
	virtual ~MyWindow();
protected:
	void showMsgBox(QMessageBox::Icon, const QString&);
	void changeEvent(QEvent *);
};

#endif