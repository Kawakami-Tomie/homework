#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowFlags(Qt::WindowCloseButtonHint);//只显示窗口关闭。
    w.show();
    w.setFixedSize(w.width(),w.height());//固定窗口大小。

    return a.exec();
}
