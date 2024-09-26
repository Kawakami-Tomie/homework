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

    void initUi(); // 声明initUi函数


private slots:
void on_clearBtn_clicked ();
void on_clearAllBtn_clicked ();
void on_equalBtn_clicked ();
void digitClicked ();
void on_signBtn_clicked();
void operatorClicked () ;
void on_pointBtn_clicked();

private:
    Ui::Widget *ui;

    bool calculate (double operand, QString pendingoperator) ;
    //终止运算，清除致据，报错
    void abortOperation() ;
    //连接信号和槽
    void connectSlots();

    //储存运算符
    QString pendingOperator;
    //储存运算结果
    double result;
    //标记是否等待一个操作数
    bool waitForOperand;
    void setShortcutKeys();



};

#endif // WIDGET_H
