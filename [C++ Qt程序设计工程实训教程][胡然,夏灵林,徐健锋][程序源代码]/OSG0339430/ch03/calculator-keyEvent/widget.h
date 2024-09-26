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
    void keyPressEvent(QKeyEvent *event);

private:
    bool calculate(double operand, QString pendingOperator);
    //终止运算，清除数据，报错
    void abortOperation();
    //连接信号和槽
    void connectSlots();
    //初始化界面
    void initUi();

    Ui::Widget *ui;
    QString pendingOperator;
    double result;
    bool waitForOperand;

};

#endif // WIDGET_H
