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

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_action_pen_color_triggered();

    void on_action_pen_thick_triggered();

    void on_action_pen_style_triggered();

    void on_action_brush_color_triggered();

    void on_action_draw_line_triggered();

    void on_action_draw_circle_triggered();

    void on_action_draw_rect_triggered();

    void on_action_clear_triggered();

    void on_action_draw_pie_triggered();

private:
    Ui::MainWindow *ui;
    int x1, y1, x2, y2;
    int x, y, r;
    int x111, y111, x222, y222;
    int X,Y,W,H,A,Alen;
    bool clear;
    QColor penColor = Qt::black;
    Qt::PenStyle penStyle = Qt::SolidLine;
    int penWidth = 1;
    QColor brushColor = Qt::white;
};
#endif // MAINWINDOW_H
