#include <QFileSelector>
#include <QMessageBox>
#include "ui_FormUI.h"
#include "MainWindow.h"

MainWindow::MainWindow(MyTranslator *translator, QWidget *parent) : 
	QWidget(parent),
	m_Translator(translator),
	ui(new Ui::FormUI) {
	
	ui->setupUi(this);
	setWindowTitle(PROGRAM_TITLE);

#ifdef Q_OS_LINUX
	setWindowIcon(QIcon(":/icons/main"));
#endif

	ui->lineEdit_name->setText(m_Translator->language());
	
	QFileSelector selector;
	QPixmap image(selector.select(":/main/platform"));
	ui->os_image->setPixmap(image);
	
	/*connect(ui->checkBox, &QCheckBox::toggled, [=](bool checked) {
		ui->lineEdit_name->setDisabled(checked);
	});*/
	
	//connect(ui->checkBox, SIGNAL(toggled(bool)), ui->lineEdit_name, SLOT(setDisabled(bool)));
	
	connect(ui->checkBox, &QCheckBox::toggled, ui->lineEdit_name, &QLineEdit::setDisabled);
	
	connect(ui->btn_ok, &QPushButton::clicked, [=]() {
		doOK();
	});
	
	connect(ui->btn_quit, &QPushButton::clicked, [=]() {
		close();
	});
	
}

void MainWindow::showInfo(const QString& body) {
	QMessageBox mb(QMessageBox::Information, PROGRAM_TITLE, QObject::tr("This is your inputed text:"), QMessageBox::Close, this);
	mb.setInformativeText(body);
	mb.exec();
}

void MainWindow::doOK() {
	
	if (ui->checkBox->isChecked()) {
		QMessageBox::aboutQt(this);
	}
	else {
		QString myText = ui->lineEdit_name->text();
		if (!myText.isEmpty()) {
			showInfo(myText);
		} else {
			showInfo(QObject::tr("Please input some information"));
		}
	}
	
}

MainWindow::~MainWindow() {
	delete ui;
}