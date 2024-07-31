#ifndef _MYWINDOW_H
#define _MYWINDOW_H

#include <QMessageBox>

namespace Ui {
    class MainWindowUI;
}

class MyWindow : public QWidget
{
private:
	Ui::MainWindowUI *ui;
public:
	MyWindow(QWidget* parent = nullptr);
	virtual ~MyWindow();
protected:
	void showMsgBox(QMessageBox::Icon, const QString&);
};

#endif