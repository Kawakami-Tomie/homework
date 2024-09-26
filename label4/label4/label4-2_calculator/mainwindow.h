#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class conversion;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    conversion *window=NULL;

    bool isInt(QString str);

private:
    Ui::MainWindow *ui;
    QString inToPost(QString infix) noexcept;
    double compute(QString s) noexcept;
    //终止运算，清除数据，报错
    void abortOpreration();
    void connectSlots();
    void setShortcutKeys();
    void specialOperatorClicked();
    //获取表达式当前值
    QString currentText();
    //设置当前行的值
    void setCurrentText(QString Text);

    //标记是否等待一个操作数
    bool waitForOperator;
    QString error;
    QString log; //存放历史

private slots:
    void on_clearBtn_clicked();
    void on_ClearAllBtn_clicked();
    void on_equalBtn_clicked();
    void digitClicked();
    void on_signBtn_clicked();
    void on_pointBtn_clicked();
    void operatorClicked();

    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_Ctrl_V_triggered();
    void on_action_3_triggered(bool checked);
    void on_action_4_triggered();
    void on_action_3_triggered();
};

#endif // MAINWINDOW_H
