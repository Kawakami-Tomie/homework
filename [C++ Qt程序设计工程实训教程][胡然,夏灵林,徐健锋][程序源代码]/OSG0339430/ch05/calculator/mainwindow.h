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

    void on_action_triggered();

private:
    //将表达式转化为后缀表达式
    QString inToPost(QString infix) throw(const char*);
    //计算后缀表达式的结果
    double compute(QString s) throw(const char*);
    void abortOperation();
    //初始化界面
    void initUi();
    //连接信号和槽
    void connectSlots();
    //设置快捷键
    void setShortcutKeys();

    Ui::MainWindow *ui;
    bool waitForOperand;
    QString error;

};

#endif // MAINWINDOW_H
