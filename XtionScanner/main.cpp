#include "GUI\MainForm\xtionscanner.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	XtionScanner w;
	w.show();
	return a.exec();
}
