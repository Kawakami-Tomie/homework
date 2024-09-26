#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool isInt(QString str);

private:
    Ui::MainWindow *ui;
    QString inToPost(QString infix) throw(const char*);
    double compute(QString s) throw(const char*);
    //终止运算，清除数据，报错
    void abortOpreration();
    void connectSlots();
    void setShortcutKeys();

    //标记是否等待一个操作数
    bool waitForOperand;
    QString error;

private slots:
    void on_clearBtn_clicked();
    void on_ClearAllBtn_clicked();
    void on_equalBtn_clicked();
    void digitClicked();
    void on_signBtn_clicked();
    void on_pointBtn_clicked();
    void operatorClicked();
    void on_lnBtn_clicked();
    void on_action_triggered();
    void on_sinBtn_clicked();
    void on_cosBtn_clicked();
    void on_facBtn_clicked();
    void on_piBtn_clicked();
};

#endif // MAINWINDOW_H
