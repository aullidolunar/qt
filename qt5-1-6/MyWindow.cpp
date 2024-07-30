#include "MyWindow.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

MyWindow::MyWindow(const QString& _title, QWidget* parent) : QWidget(parent)
{
	setWindowTitle(_title);
#ifdef Q_OS_WIN
	QPixmap image(":/main/windows");
#else
	setWindowIcon(QIcon(":/main/icon"));
	QPixmap image(":/main/linux");
#endif
	
	auto layout = new QGridLayout();
	layout->setColumnStretch(0, 0);
	layout->setColumnStretch(1, 0);
	layout->setColumnStretch(2, 1);
	
	auto m_lineEdit = new QLineEdit(this);
	auto buttonSave = new QPushButton(QIcon(":/save"), "&Guardar", this);
	auto buttonAbout = new QPushButton(QIcon(":/qt"), "&Acerca de...", this);
	auto buttonQuit = new QPushButton(QIcon(":/close"), "&Salir", this);
	
	connect(buttonSave, &QPushButton::clicked, [=]() {
		
		QString text =  m_lineEdit->text();
		
		if (text.isEmpty()) {
			showMsgBox(QMessageBox::Critical, "El campo está vacío");
		} else {
			showMsgBox(QMessageBox::Information, text);
		}
	});
	
	connect(buttonAbout, &QPushButton::clicked, [=](){
		QMessageBox::aboutQt(this);
	});
	
	connect(buttonQuit, &QPushButton::clicked, [=](){
		close();
	});
	
	auto imager = new QLabel(this);
	imager->setPixmap(image);

// layout:
	layout->addWidget(m_lineEdit, 0, 0, 1, 3);
	layout->addWidget(buttonSave, 1, 0, 1, 1);
	layout->addWidget(buttonAbout, 2, 0, 1, 1);
	layout->addWidget(buttonQuit, 3, 0, 1, 1);
	layout->addWidget(imager, 1, 1, 3, 1);
	layout->addItem(new QSpacerItem(1, 1), 1, 2, 3, 1);
	setLayout(layout);
}

void MyWindow::showMsgBox(QMessageBox::Icon _icon, const QString& _text)
{
	QString msg = QString("Mensaje: ") + _text;
	QMessageBox msgbox(_icon, windowTitle(), msg, QMessageBox::NoButton, this);
	QPushButton buttonOK(QIcon(":/ok"), "&Aceptar");
	msgbox.addButton(&buttonOK, QMessageBox::AcceptRole);
	msgbox.exec();
}
