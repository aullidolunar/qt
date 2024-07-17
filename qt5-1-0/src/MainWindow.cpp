#include <QPushButton>
#include <QLayout>
#include <QtDebug>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle(PROGRAM_NAME);
	QWidget *central = new QWidget();
	QVBoxLayout *layout = new QVBoxLayout();
	
	QPushButton* button1 = new QPushButton(tr("Mostrar"), central);
	QPushButton* button2 = new QPushButton(tr("Salir"), central);
	
// sloties:
	connect(button1, SIGNAL(clicked()), this, SLOT(button1_clicked()));
	connect(button2, SIGNAL(clicked()), this, SLOT(button2_clicked()));
	
	layout->addWidget(button1);
	layout->addWidget(button2);
	central->setLayout(layout);
	setCentralWidget(central);
}

void MainWindow::button1_clicked()
{
	qInfo() << tr("Conectado");
}

void MainWindow::button2_clicked()
{
	close();
}