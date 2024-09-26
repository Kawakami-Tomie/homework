#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "before create widget";
    Widget w;
    qDebug() << "after create widget";
    w.show();

    qDebug() << "enter the event loop";
    return a.exec();
}
