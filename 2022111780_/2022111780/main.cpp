#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("BMI计算器（2022111780）");//改主窗口名字
    w.show();

    return a.exec();
}
