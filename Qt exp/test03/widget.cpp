#include "widget.h"
#include "ui_widget.h"
#include "QLabel"
#include "QListWidget"
#include "QStackedLayout"
#include "QHBoxLayout"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QListWidget *listWidget = new QListWidget();
//      listWidget->addItem("One");
//      listWidget->addItem("Two");
//      listWidget->addItem("Three");

//      QWidget *widget1 = new QWidget();
//      QWidget *widget2 = new QWidget();
//      QWidget *widget3 = new QWidget();

//      QLabel *label1 = new QLabel("LABEL ONE", widget1);
//      QLabel *label2 = new QLabel("LABEL TWO", widget2);
//      QLabel *label3 = new QLabel("LABEL THREE", widget3);

//      QStackedLayout *sLayout = new QStackedLayout();
//      sLayout->addWidget(widget1);
//      sLayout->addWidget(widget2);
//      sLayout->addWidget(widget3);

//      QHBoxLayout *hLayout = new QHBoxLayout();
//      hLayout->addWidget(listWidget);
//      hLayout->addLayout(sLayout);

//      setLayout(hLayout);

//      QObject::connect(listWidget, &QListWidget::currentRowChanged, sLayout, &QStackedLayout::setCurrentIndex);

 //       connect(ui->pushButton,SIGNAL(pressed()),ui->label,SLOT(close()));
//        connect(ui->pushButton,&QPushButton::pressed,ui->label,&QLabel::close);
//        connect(ui->pushButton,&QPushButton::released,ui->label,&widget::myslot);
//        connect(ui->LineEdit,&Q)
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

void Widget::myslot()
{
    ui->pushButton->setText("12345678");
}

