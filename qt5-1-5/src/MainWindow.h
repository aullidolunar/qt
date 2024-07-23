#ifndef _MAINWINDOW_H_INC
#define _MAINWINDOW_H_INC

#include <QApplication>
#include <QMainWindow>
#include <QTranslator>
#include <QtDebug>

namespace Ui {
    class MainWindowUI;
}

class MainWindow : public QMainWindow
{
private:
	Q_OBJECT
	QTranslator* translator;
	int last_index;
	Ui::MainWindowUI *ui;

public:
	MainWindow(QTranslator*, QWidget* parent = nullptr);
	virtual ~MainWindow();

protected:
	void changeEvent(QEvent*);
	void retranslateUi2();

protected slots:
	void button1_clicked();
	void button2_clicked();
	void combobox_changed(int);
};


#endif
