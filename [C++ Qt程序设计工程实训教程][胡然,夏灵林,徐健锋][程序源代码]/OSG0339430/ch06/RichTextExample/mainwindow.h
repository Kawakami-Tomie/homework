#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void findNext();

private slots:
    void on_action_triggered();

    void on_action_textTable_triggered();

    void on_action_textList_triggered();

    void on_action_textImage_triggered();

    void on_action_find_triggered();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit;
    QDialog *findDialog;
};

#endif // MAINWINDOW_H
