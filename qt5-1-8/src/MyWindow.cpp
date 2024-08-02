#include <QFileSelector>
#include <QTextStream>
#include "ui_MainWindowUI.h"
#include "MyWindow.h"

MyWindow::MyWindow(MyTranslatorClass* ptc, QWidget* parent) : 
	QWidget(parent), ui(new Ui::MainWindowUI), m_ptc(ptc)
{
	ui->setupUi(this);
	
	setWindowTitle(PROGRAM_TITLE);
#ifndef Q_OS_WIN
	setWindowIcon(QIcon(":/main/icon"));
#endif
	
	ui->m_comboBox->addItems(QString(PROGRAM_TRANSLATIONS).split(' '));
	ui->m_comboBox->addItem("en");
	
	QString curr_lang = m_ptc->language();
	int npos = ui->m_comboBox->findText(curr_lang.left(2));
	
	if (npos == -1) {
		npos = ui->m_comboBox->count()-1;
	}
	
	m_savedIndex = npos;
	ui->m_comboBox->setCurrentIndex(npos);
	
	QFileSelector selector;
	QPixmap image(selector.select(":/main/platform"));
	ui->imager->setPixmap(image);
	
	connect(ui->buttonSave, &QPushButton::clicked, [=](){
		
		QString text = ui->m_lineEdit->text();
		
		if (text.isEmpty()) {
			showMsgBox(QMessageBox::Critical, tr("The entry has no strings"));
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
	
	connect(ui->m_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index){
		if (index != m_savedIndex) {
			
			QString lang = ui->m_comboBox->itemText(index);
			
			m_ptc->changeLanguage(lang);
			
			m_savedIndex = index;
		
		}
	});
	
}

void MyWindow::showMsgBox(QMessageBox::Icon _icon, const QString& _text) {
	QString msg;
	QTextStream out(&msg);
	out << tr("Message") << ":\n" << _text;
	QMessageBox msgbox(_icon, windowTitle(), msg, QMessageBox::NoButton, this);
	QPushButton buttonOK(QIcon(":/ok"), tr("&OK"));
	msgbox.addButton(&buttonOK, QMessageBox::AcceptRole);
	msgbox.exec();
}

void MyWindow::changeEvent(QEvent *e) {
	if (e->type() == QEvent::LanguageChange) {
		ui->retranslateUi(this);
	}

	QWidget::changeEvent(e);
}

MyWindow::~MyWindow() {
	delete ui;
}
