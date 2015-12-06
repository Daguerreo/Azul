#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qApp->setApplicationVersion(APP_VERSION);
	qApp->setApplicationName(QString(APP_NAME).replace("_", " "));

	MainWindow w;
	w.setWindowTitle( qApp->applicationName() + QString(" - ") + qApp->applicationVersion());
	w.show();

	return a.exec();
}
