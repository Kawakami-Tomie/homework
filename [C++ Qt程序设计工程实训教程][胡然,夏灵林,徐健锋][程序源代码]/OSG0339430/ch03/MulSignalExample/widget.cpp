#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLineEdit *si[] = {ui->lineEdit, ui->lineEdit_2, ui->lineEdit_3};
    QLabel *sl[] = {ui->label, ui->label_2, ui->label_3};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            connect(si[i], &QLineEdit::textChanged, sl[j], &QLabel::setText);
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
