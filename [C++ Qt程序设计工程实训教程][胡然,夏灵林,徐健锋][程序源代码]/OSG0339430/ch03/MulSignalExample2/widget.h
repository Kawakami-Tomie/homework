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

private:

    //连接信号和槽
    void connectSlots();

private slots:
    void digitClicked();
    void on_pointBtn_clicked();
    void on_clearBtn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
