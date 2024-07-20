#ifndef _MAINWINDOW_H_INC
#define _MAINWINDOW_H_INC

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QTranslator>
#include <QtDebug>

class MainWindow : public QMainWindow
{
private:
	Q_OBJECT
	QTranslator* translator;
	QPushButton* button1;
	QPushButton* button2;
	QComboBox* combobox;
	int last_index;
public:
	MainWindow(QTranslator*, QWidget* parent = nullptr);
protected:
	void retranslateUi();
protected slots:
	void button1_clicked();
	void button2_clicked();
	void combobox_changed(int);
};


#endif
