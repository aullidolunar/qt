#include <QFileSelector>
#include <QMessageBox>
#include "ui_FormUI.h"
#include "MainWindow.h"

MainWindow::MainWindow(MyTranslator *translator, QWidget *parent) : 
	QWidget(parent),
	m_Translator(translator),
	ui(new Ui::FormUI) {
	
	ui->setupUi(this);
	setWindowTitle(PROGRAM_NAME);

	connect(ui->checkBox, &QCheckBox::toggled, ui->lineEdit_name, &QLineEdit::setDisabled);
	
	connect(ui->btn_ok, &QPushButton::clicked, [=]() {
		doOK();
	});
	
	connect(ui->btn_quit, &QPushButton::clicked, [=]() {
		close();
	});
	
	connect(ui->btn_about, &QPushButton::clicked, [=]() {
		showAboutDlg();
	});
	
	/* 0: title; 1: Spanish; 2: french; 3: Italian; 4: Portuguese; 5: English */
	connect(ui->comboBox1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::switchToLanguage);
}

void MainWindow::showInfo(const QString& body) {
	QMessageBox mb(QMessageBox::Information, PROGRAM_TITLE, tr("This is your inputed text:"), QMessageBox::Close, this);
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
			showInfo(tr("Please input some information"));
		}
	}
	
}

void MainWindow::switchToLanguage(int lang) {
	const QString langs[] = {
		QT_TR_NOOP("None"), "es", "fr", "it", "pr", "en"
	};
	if (lang) {
		m_Translator->changeLanguage(langs[lang]);
		ui->retranslateUi(this);
	}
}

void MainWindow::showAboutDlg() {
  QMessageBox::about(this, tr("About program"), PROGRAM_DESC);
}

MainWindow::~MainWindow() {
	delete ui;
}