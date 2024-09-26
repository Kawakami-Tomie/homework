#ifndef WIDGET_H
#define WIDGET_H
#include<QPainter>
#include<QPixmap>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
protected:
        void paintEvent(QPaintEvent *event);
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
        void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int x=10;
};

#endif // WIDGET_H
