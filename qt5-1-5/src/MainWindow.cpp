// the order is importat:
#include "MainWindow.h"
#ifdef Q_OS_WIN
#include <QtWin>
#endif
#include <QPixmap>
#include "ui_MainWindowUI.h"

MainWindow::MainWindow(QTranslator* trans, QWidget* parent) : 
	translator(trans), QMainWindow(parent), ui(new Ui::MainWindowUI)
{
	ui->setupUi(this);
	
	last_index = 0;
	setWindowTitle(PROGRAM_NAME);
#ifdef Q_OS_WIN
	HICON hIcon = static_cast<HICON>(::LoadImageW(::GetModuleHandleW(nullptr), L"AppIcon", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE|LR_LOADTRANSPARENT));
	setWindowIcon(QIcon(QtWin::fromHICON(hIcon)));
	::DestroyIcon(hIcon);
	QPixmap image(":/icons/windows/os");
#else
	setWindowIcon(QIcon(":/app/main"));
	QPixmap image(":/icons/linux/os");
#endif

	ui->imager->setPixmap(image);
	ui->combobox->addItem(QString());
	ui->combobox->addItems(QString(PROGRAM_LANGS).split(" "));
	ui->combobox->addItem("en");
	
	QString str_search(trans->language());
	
	int current_lang = ui->combobox->findText(str_search.left(2)); // es_MX -> es
	if (current_lang < 0)
		current_lang = 0;
	
	ui->combobox->setCurrentIndex(current_lang);
	
// custom translations:
	retranslateUi2();
	
// sloties:
	connect(ui->button1, SIGNAL(clicked()), this, SLOT(button1_clicked()));
	connect(ui->button2, SIGNAL(clicked()), this, SLOT(button2_clicked()));
	connect(ui->combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(combobox_changed(int)));

}

void MainWindow::button1_clicked()
{
	qInfo() << tr("Conected");
}

void MainWindow::button2_clicked()
{
	close();
}

void MainWindow::combobox_changed(int index)
{
	if (index && index != last_index)
	{
		QCoreApplication::removeTranslator(translator);
		
		QString lang = ui->combobox->itemText(index);
		translator->load(lang, ":/translations");
		QCoreApplication::installTranslator(translator);
		qInfo() << tr("Changed to:") << lang;
		last_index = index;
	}
}

void MainWindow::retranslateUi2()
{
	ui->combobox->setItemText(0, tr("Select language"));
}

void MainWindow::changeEvent(QEvent *e)
{
	if (e->type() == QEvent::LanguageChange)
	{
		ui->retranslateUi(this);
		retranslateUi2();
	}

	QMainWindow::changeEvent(e);
}

MainWindow::~MainWindow()
{
	delete ui;
}
