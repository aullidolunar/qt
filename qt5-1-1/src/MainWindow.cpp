// the order is importat:
#include "MainWindow.h"
#ifdef Q_OS_WIN
#include <QtWin>
#endif
#include <QPushButton>
#include <QLayout>
#include <QPixmap>
#include <QLabel>
#include <QtDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	
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
	
	QPushButton* button1 = new QPushButton(tr("&Show"), central);
	QLabel *imager = new QLabel();
	imager->setPixmap(image);
	QPushButton* button2 = new QPushButton(tr("E&xit"), central);
	
// sloties:
	connect(button1, SIGNAL(clicked()), this, SLOT(button1_clicked()));
	connect(button2, SIGNAL(clicked()), this, SLOT(button2_clicked()));

// layout:	
	layout->addWidget(button1);
	layout->addWidget(imager);
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