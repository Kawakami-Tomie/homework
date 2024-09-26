#include "widget.h"

widget::widget(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,200);
    label = new QLabel(this);
    label->setText("hello world");
    label->setGeometry(50,50,100,100);

 //   label->show();
}

widget::~widget()
{

}
