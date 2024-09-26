#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void on_begin_clicked();

    void on_pushButton_3_clicked();

    void on_record_clicked();

private:
    Ui::Widget *ui;
    int timer_id;
    int count;
     int elapsedTime;  // 经过的时间（以毫秒为单位）
};

#endif // WIDGET_H
