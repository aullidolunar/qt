// the order is importat:
#include "MainWindow.h"
#ifdef Q_OS_WIN
#include <QtWin>
#endif
#include <QLayout>
#include <QPixmap>
#include <QLabel>

MainWindow::MainWindow(QTranslator* trans, QWidget* parent) : 
	translator(trans), QMainWindow(parent)
{
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
	
	QWidget *central = new QWidget();
	QVBoxLayout *layout = new QVBoxLayout();
	
	button1 = new QPushButton(central);
	QLabel *imager = new QLabel();
	imager->setPixmap(image);
	button2 = new QPushButton(central);
	combobox = new QComboBox(central);
	combobox->addItem(QString());
	//QString cmake_langs(QString("es fr"));
	combobox->addItems(QString("es fr").split(" "));
	
	retranslateUi();
	
// sloties:
	connect(button1, SIGNAL(clicked()), this, SLOT(button1_clicked()));
	connect(button2, SIGNAL(clicked()), this, SLOT(button2_clicked()));
	connect(combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(combobox_changed(int)));

// layout:	
	layout->addWidget(button1);
	layout->addWidget(imager);
	layout->addWidget(combobox);
	layout->addWidget(button2);
	central->setLayout(layout);
	setCentralWidget(central);
}

void MainWindow::button1_clicked()
{
	qInfo() << tr("Conected");
}

void MainWindow::button2_clicked()
{
	close();
}

void MainWindow::retranslateUi()
{
	button1->setText(tr("&Show"));
	button2->setText(tr("E&xit"));
	combobox->setItemText(0, tr("Choose a language"));
}

void MainWindow::combobox_changed(int index)
{
	if (!index || index != last_index)
	{
		QCoreApplication::removeTranslator(translator);
		
		QString lang = combobox->itemText(index);
		
		if (translator->load(lang, PROGRAM_LOCALEDIR))
		{
			QCoreApplication::installTranslator(translator);
			retranslateUi();
			qInfo() << tr("Changed to:") << lang;
			last_index = index;
		}
	}
}