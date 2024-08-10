#include "binaryclockwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BinaryClockWidget w;
    w.show();
    return a.exec();
}
