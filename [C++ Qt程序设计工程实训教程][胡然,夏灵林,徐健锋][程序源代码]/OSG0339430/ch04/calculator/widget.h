#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_clearBtn_clicked();

    void on_clearAllBtn_clicked();

    void on_equalBtn_clicked();

    void digitClicked();

    void on_signBtn_clicked();

    void operatorClicked();

    void on_pointBtn_clicked();
protected:


private:
    //将表达式转化为后缀表达式
    QString inToPost(QString infix) throw(const char*);
    //计算后缀表达式的结果
    double compute(QString s) throw(const char*);
    //终止运算，报错
    void abortOperation();
    //初始化界面
    void initUi();
    //连接信号和槽
    void connectSlots();
    //设置键盘按键
    void setShortcutKeys();

    Ui::Widget *ui;
    bool waitForOperand;
    QString error;

};

#endif // WIDGET_H
