#ifndef _MYWINDOW_H
#define _MYWINDOW_H

#include <QWidget>
#include <QMessageBox>

class MyWindow : public QWidget
{
private:
public:
	MyWindow(const QString& _title = QString(), QWidget* parent = nullptr);
protected:
	void showMsgBox(QMessageBox::Icon, const QString&);
};

#endif