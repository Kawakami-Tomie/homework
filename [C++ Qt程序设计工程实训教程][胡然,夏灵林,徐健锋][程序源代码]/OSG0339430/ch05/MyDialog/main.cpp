#include "widget.h"
#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Dialog myDialog;
    if (myDialog.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    return 0;
}
