#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    errorDlg = new QErrorMessage(this);
}

Widget::~Widget()
{
    delete ui;
}

QWizardPage *Widget::createPage1()
{
    QWizardPage *page = new QWizardPage();
    page->setTitle("介绍");
    return page;
}

QWizardPage *Widget::createPage2()
{
    QWizardPage *page = new QWizardPage();
    page->setTitle("用户选择信息");
    return page;
}

QWizardPage *Widget::createPage3()
{
    QWizardPage *page = new QWizardPage();
    page->setTitle("结束");
    return page;
}

void Widget::on_pushButton_clicked()
{
    QColorDialog dialog(Qt::red, this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug() << "color:" << color;
}

void Widget::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "文件对话框", "D:", "图片文件(* png * jpg);;文本文件(*txt)");
    qDebug() << "fileName:" << fileName;
}

void Widget::on_pushButton_2_clicked()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
    {
        ui->pushButton_2->setFont(font);
    }
    else
    {
        qDebug() << "没有选择字体";
    }
}



void Widget::on_pushButton_6_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "输入对话框", "请输入用户名：", QLineEdit::Normal, "admin", &ok);
    if (ok)
    {
        qDebug() << "name:" << name;
    }
    int intNum = QInputDialog::getInt(this, "整数输入对话框", "请输入-1000到1000之间的数值", 100, -1000, 1000, 10, &ok);
    if (ok)
    {
        qDebug() << "intNum:" << intNum;
    }
    double doubleNum = QInputDialog::getDouble(this, "浮点数输入对话框", "请输入-1000到1000的数值",
                                               0.00, -1000, 1000, 2, &ok);
    if (ok)
    {
        qDebug() << "doubleNum:" << doubleNum;
    }
    QStringList items;
    items << "条目1" << "条目2";
    QString item = QInputDialog::getItem(this, "条目输入对话框", "请选择或输入一个条目", items, 0, true, &ok);
    if (ok)
    {
        qDebug() << "item:" << item;
    }
 }

void Widget::on_pushButton_3_clicked()
{
    int ret1 = QMessageBox::question(this, "问题对话框", "你了解Qt吗？", QMessageBox::Yes, QMessageBox::No);
    if (ret1 == QMessageBox::Yes)
    {
        qDebug() << "问题！";
    }
    int ret2 = QMessageBox::information(this, "提示对话框", "这是Qt书籍！", QMessageBox::Ok);
    if (ret2 == QMessageBox::Ok)
    {
        qDebug() << "提示！";
    }
    int ret3 = QMessageBox::warning(this, "警告对话框", "不能提前结束！", QMessageBox::Abort);
    if (ret3 == QMessageBox::Abort)
    {
        qDebug() << "警告！";
    }
    int ret4 = QMessageBox::critical(this, "严重错误对话框", "发现一个严重错误！现在要关闭所有文件！", QMessageBox::YesAll);
    if (ret4 == QMessageBox::YesAll)
    {
        qDebug() << "错误！";
    }
    QMessageBox::about(this, "关于对话框", "Qt对话框实例");
}

void Widget::on_pushButton_7_clicked()
{
    QProgressDialog dialog("文件复制进度", "取消", 0, 50000, this);
    dialog.setWindowTitle("进度对话框");
    dialog.show();
    for (int i = 0; i < 50000; i++)
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if (dialog.wasCanceled())
        {
            break;
        }
    }
    dialog.setValue(50000);
    qDebug() << "复制结束!";
}

void Widget::on_pushButton_4_clicked()
{
    errorDlg->setWindowTitle("错误消息对话框");
    errorDlg->showMessage("这里是出错消息");
}

void Widget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle("向导对话框");
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
