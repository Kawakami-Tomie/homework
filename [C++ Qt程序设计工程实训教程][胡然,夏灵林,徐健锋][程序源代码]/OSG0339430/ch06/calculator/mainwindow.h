#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_clearBtn_clicked();

    void on_clearAllBtn_clicked();

    void on_equalBtn_clicked();

    void digitClicked();

    void on_signBtn_clicked();

    void operatorClicked();

    void on_pointBtn_clicked();



    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_triggered();

private:
    //将表达式转化为后缀表达式
    QString inToPost(QString infix) throw(const char*);
    //计算后缀表达式的结果
    double compute(QString s) throw(const char*);
    //终止运算并打印出错信息
    void abortOperation();
    //获取当前表达式的值
    QString currentText();
    //设置当前行的值
    void setCurrentText(QString text);
    //初始化界面
    void initUi();
    //连接信号和槽
    void connectSlots();
    //设置键盘按键
    void setShortcutKeys();

    Ui::MainWindow *ui;         //ui控件
    bool waitForOperator;       //等待运算符标志，判断运算完成是否换行
    QString error;              //错误信息
    QString log;                //历史记录
};

#endif // MAINWINDOW_H
