#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textChanged, ui->label, &QLabel::setText);
}

Widget::~Widget()
{
    delete ui;
}
