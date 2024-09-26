#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

protected:
           void keyPressEvent(QKeyEvent *event);
           void keyReleaseEvent(QKeyEvent *event);

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
