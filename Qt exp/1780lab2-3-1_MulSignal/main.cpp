#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
     w.setWindowTitle("Widget_MulSignal_1780");//改主窗口名字
    w.show();

    return a.exec();
}
