#include "ui_MainWindowUI.h"
#include "MyWindow.h"
#include <QFileSelector>

MyWindow::MyWindow(QWidget* parent) : 
	QWidget(parent), ui(new Ui::MainWindowUI)
{
	ui->setupUi(this);
	
	setWindowTitle(PROGRAM_TITLE);
	QFileSelector selector;
#ifndef Q_OS_WIN
	setWindowIcon(QIcon(":/main/icon"));
#endif
	
	QPixmap image(selector.select(":/main/platform"));
	connect(ui->buttonSave, &QPushButton::clicked, [=](){
		
		QString text = ui->m_lineEdit->text();
		
		if (text.isEmpty()) {
			showMsgBox(QMessageBox::Critical, "El campo está vacío");
		} else {
			showMsgBox(QMessageBox::Information, text);
		}
	});
	
	connect(ui->buttonAbout, &QPushButton::clicked, [=](){
		QMessageBox::aboutQt(this);
	});
	
	connect(ui->buttonQuit, &QPushButton::clicked, [=](){
		close();
	});
	
	ui->imager->setPixmap(image);
}

void MyWindow::showMsgBox(QMessageBox::Icon _icon, const QString& _text)
{
	QString msg = QString("Mensaje: ") + _text;
	QMessageBox msgbox(_icon, windowTitle(), msg, QMessageBox::NoButton, this);
	QPushButton buttonOK(QIcon(":/ok"), "&Aceptar");
	msgbox.addButton(&buttonOK, QMessageBox::AcceptRole);
	msgbox.exec();
}

MyWindow::~MyWindow()
{
	delete ui;
}
