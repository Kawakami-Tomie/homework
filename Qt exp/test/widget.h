#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QLabel>
class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = 0);
    ~widget();
    QLabel *label;
};

#endif // WIDGET_H
