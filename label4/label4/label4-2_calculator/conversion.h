#ifndef CONVERSION_H
#define CONVERSION_H

#include <QMainWindow>

class MainWindow;

namespace Ui {
class conversion;
}

class conversion : public QMainWindow
{
    Q_OBJECT

public:
    explicit conversion(QWidget *parent = 0);
    ~conversion();

    MainWindow *window=NULL;

private:
    Ui::conversion *ui;
    void convert();

signals:
    void goback();
private slots:
    void on_action_triggered();
    void on_convert10_clicked();
    void on_convert2_clicked();
    void on_convert16_clicked();
    void on_convert8_clicked();
};

#endif // CONVERSION_H
