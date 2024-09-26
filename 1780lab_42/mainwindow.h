#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStack>
#include<QQueue>
#include<QDebug>
#include<qmath.h>
#include<QMessageBox>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();

    void two_transition(QString texts);
    void eight_transition(QString texts);
    void ten_transition(QString texts);
    void sixteen_transition(QString texts);
    int twoToeight(QString str);
    int twoTosixteen(QString str);
    QString eightTotwo(int num);
    QString sixteenTotwo(int num);
    QString delete_zero(QString ret);
    void error_tip();

protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    QString error;
    void InitUi();

    //终止运算，清除数据，报错
    void abortOPeration();

    //连接信号和槽
    void connectSlots();

    //储存运算符
    QString pendingOperator;

    //储存运算结果
    double result;

    //标记是否等待一个变量
    bool waitForOperator;

    void setShortcutKeys();

    //将表达式转化为后缀表达式
    QString inToPost(QString infix) noexcept;

    //计算后缀表达式的结果
    double compute(QString s) noexcept;

    //获取当前表达式的值
    QString currentText();

    //设置当前行的值
    void setCurrentText(QString text);

    //一个私有成员变量
    QString log;

    int system_flag = 2;//进制变量
    bool is_minus = false; //判断是否为负数
    bool is_float = false;//判断是否带小数



private slots:
    void on_clearBtn_clicked();
    void on_clearAllBtn_clicked();
    void on_equalBtn_clicked();
    void digitClicked();
    void on_signBtn_clicked();
    void operatorClicked();
    void on_pointBtn_clicked();

    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered();
    void on_action_4_triggered(bool checked);

    void specialOperatorClicked();


    void on_btn_transition_clicked();

    void on_radio_2_clicked(){system_flag=2;}

    void on_radio_8_clicked(){system_flag=8;}

    void on_radio_10_clicked(){system_flag=10;}

    void on_radio_16_clicked(){system_flag=16;}
    //void on_action_5_triggered(bool checked);

    //  void on_radio_2_clicked();
    void on_action_4_triggered();
    void on_radio_2_toggled(bool checked);
    void on_action_5_triggered(bool checked);
    void on_tanBtn_clicked();
 //   void on_tanBtn_toggled(bool checked);
    void on_textEdit_destroyed();
};
#endif // MAINWINDOW_H

