#ifndef _MAINWINDOW_H_INC
#define _MAINWINDOW_H_INC

#include <QMainWindow>

class MainWindow : public QMainWindow
{
private:
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);
protected slots:
	void button1_clicked();
	void button2_clicked();
};


#endif
