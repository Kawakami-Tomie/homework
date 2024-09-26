#include "chengxu.h"
#include "ui_chengxu.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <map>
#include <stack>
#include <cmath>
#include <QClipboard>
#include <QtMath>
#include <QTextBlock>
#include <QRadioButton>

chengxu::chengxu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chengxu)
{
    ui->setupUi(this);
}

chengxu::~chengxu()
{
    delete ui;
}

void chengxu::on_radio_2_clicked()
{

}


void chengxu::on_radio_8_clicked()
{

}

