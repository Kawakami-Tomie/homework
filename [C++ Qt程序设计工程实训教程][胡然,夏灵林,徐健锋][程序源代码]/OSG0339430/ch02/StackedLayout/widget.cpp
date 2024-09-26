#include "widget.h"
#include "ui_widget.h"
#include <QStackedLayout>
#include <QListWidget>
#include <QLabel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QListWidget *listWidget = new QListWidget();
    listWidget->addItem("One");
    listWidget->addItem("Two");
    listWidget->addItem("Three");

    QWidget *widget1 = new QWidget();
    QWidget *widget2 = new QWidget();
    QWidget *widget3 = new QWidget();

    QLabel *label1 = new QLabel("LABEL ONE", widget1);
    QLabel *label2 = new QLabel("LABEL TWO", widget2);
    QLabel *label3 = new QLabel("LABEL THREE", widget3);

    QStackedLayout *sLayout = new QStackedLayout();
    sLayout->addWidget(widget1);
    sLayout->addWidget(widget2);
    sLayout->addWidget(widget3);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(listWidget);
    hLayout->addLayout(sLayout);

    setLayout(hLayout);

    QObject::connect(listWidget, &QListWidget::currentRowChanged, sLayout, &QStackedLayout::setCurrentIndex);
}

Widget::~Widget()
{
    delete ui;
}
