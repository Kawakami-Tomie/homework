#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include<QStack>
#include<QDebug>
#include<QKeyEvent>
#include<QPushButton>
#include<QThread>
#include<QMessageBox>
#include<QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double jointNum(QString str,int &i);//提取操作数
    int in_priority(char ch);//栈内运算符优先级
    int out_priority(char ch);//栈外运算符优先级
    int compare_priority(int in,int out); //比较栈内外的优先级
    double calcualate_num(double num1,double num2,char oper);//根据运算符计算两个操作数
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void btn_highlight(QPushButton* btn); //键盘按下高亮
    void btn_release(QPushButton* btn);//键盘释放
    void de_weight(QVector<QString> &vec);//去重

private slots:
    void on_btn_back_clicked();

    void on_btn_clear_clicked();

    void on_btn_left_clicked();

    void on_btn_right_clicked();

    void on_btn_mul_clicked();

    void on_btn_equal_clicked();

    void on_btn_sub_clicked();

    void on_btn_multiply_clicked();

    void on_btn_dividie_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_pushButton_9_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_point_clicked();

    void on_btn_0_clicked();

    void on_btn_4_clicked();

    void on_btn_add_clicked();

    void on_btn_divide_clicked();

    void on_action_V_triggered();

    void on_btn_qufan_clicked();

private:
    Ui::MainWindow *ui;
    QStack<char> optr;//运算符栈
    QStack<double> opnd;//操作数栈
    QString infix;//中缀表达式
    QString infix_copy;//中缀表达式
    QVector<QString> history_infix;//存储历史记录
};

#endif // MAINWINDOW_H
