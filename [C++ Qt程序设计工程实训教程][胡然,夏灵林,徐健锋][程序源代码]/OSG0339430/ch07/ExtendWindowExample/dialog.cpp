#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->phoneLabel->hide();
    ui->phoneLineEdit->hide();
    ui->adressLabel->hide();
    ui->adressLineEdit->hide();
    ui->idCardLabel->hide();
    ui->idCardLineEdit->hide();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_moreBtn_clicked()
{
    ui->phoneLabel->show();
    ui->phoneLineEdit->show();
    ui->adressLabel->show();
    ui->adressLineEdit->show();
    ui->idCardLabel->show();
    ui->idCardLineEdit->show();
}
