#include "gamewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWidget w;
    w.setWindowTitle("五子棋_1780");//改主窗口名字
    w.show();

    return a.exec();
}
