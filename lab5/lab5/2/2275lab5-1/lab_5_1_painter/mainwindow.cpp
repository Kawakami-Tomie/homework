#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QInputDialog>
#include <QDebug>
#include <QPainter>
#include <QImage>

QImage image(500,500,QImage::Format_RGBA8888);
bool bline=0;bool bcircle=0;bool brect=0;bool bpie=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image.fill(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_pen_color_triggered()
{
    penColor = QColorDialog::getColor(Qt::red, this, "边框颜色");
    update();
}

void MainWindow::on_action_pen_thick_triggered()
{
    bool ok;
    penWidth = QInputDialog::getInt(this, tr("输入"), tr("请输入画笔宽度:"), 1, 1, 1000, 1, &ok);
    if (!ok) return;
    update();
}

void MainWindow::on_action_pen_style_triggered()
{
    QStringList styles;
    styles << tr("SolidLine") << tr("DashLine") << tr("DotLine") << tr("DashDotLine") << tr("DashDotDotLine");
    bool ok;
    QString style = QInputDialog::getItem(this, tr("选择画笔样式"), tr("画笔样式:"), styles, 0, false, &ok);
    if (ok && !style.isEmpty())
    {
        if (style == tr("SolidLine"))
            penStyle = Qt::SolidLine;
        else if (style == tr("DashLine"))
            penStyle = Qt::DashLine;
        else if (style == tr("DotLine"))
            penStyle = Qt::DotLine;
        else if (style == tr("DashDotLine"))
            penStyle = Qt::DashDotLine;
        else if (style == tr("DashDotDotLine"))
            penStyle = Qt::DashDotDotLine;
    }
    update();
}

void MainWindow::on_action_brush_color_triggered()
{
    brushColor = QColorDialog::getColor(Qt::white, this, "背景颜色");
    update();
}


void MainWindow::on_action_draw_line_triggered()
{
    bool ok;
    x1 = QInputDialog::getInt(this, tr("输入"), tr("请输入x1坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    y1 = QInputDialog::getInt(this, tr("输入"), tr("请输入y1坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    x2 = QInputDialog::getInt(this, tr("输入"), tr("请输入x2坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    y2 = QInputDialog::getInt(this, tr("输入"), tr("请输入y2坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    bline=1;
    update();
}

void MainWindow::on_action_draw_circle_triggered()
{
    bool ok;
    x = QInputDialog::getInt(this, tr("输入"), tr("请输入圆心x坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    y = QInputDialog::getInt(this, tr("输入"), tr("请输入圆心y坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    r = QInputDialog::getInt(this, tr("输入"), tr("请输入半径:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    bcircle=1;
    update();
}

void MainWindow::on_action_draw_rect_triggered()
{
    bool ok;
    x111 = QInputDialog::getInt(this, tr("输入"), tr("请输入x1坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    y111 = QInputDialog::getInt(this, tr("输入"), tr("请输入y1坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    x222 = QInputDialog::getInt(this, tr("输入"), tr("请输入x2坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    y222 = QInputDialog::getInt(this, tr("输入"), tr("请输入y2坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    brect=1;
    update();
}

void MainWindow::on_action_draw_pie_triggered()
{
    bool ok;
    X = QInputDialog::getInt(this, tr("输入"), tr("请输入x坐标:"), 0 ,0, 1000, 1, &ok);
    if (!ok) return;
    Y = QInputDialog::getInt(this, tr("输入"), tr("请输入y坐标:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    W = QInputDialog::getInt(this, tr("输入"), tr("请输入宽W:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    H = QInputDialog::getInt(this, tr("输入"), tr("请输入高H:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    A = QInputDialog::getInt(this, tr("输入"), tr("请输入起始角度:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    Alen = QInputDialog::getInt(this, tr("输入"), tr("请输入跨越角度:"), 0, 0, 1000, 1, &ok);
    if (!ok) return;
    bpie=1;
    update();
}

void MainWindow::on_action_clear_triggered()
{
   image.fill(Qt::white);
   update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    int wid=this->geometry().width();
    int heg=this->geometry().height()-51;

    QRectF targetRect(0, 51, wid, heg); // 目标矩形区域
    QRectF sourceRect(0, 0, image.width(), image.height()); // 图片源矩形区域

    if(bline==1){
        bline=0;
        QPainter painter(&image);
        QPen pen(penColor);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawLine(x1, y1, x2, y2);
    }
    if(bcircle==1){
        bcircle=0;
        QPainter painter(&image);
        QPen pen(penColor);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawEllipse(x-r, y-r, 2*r, 2*r);
    }
    if(brect==1){
        brect=0;
        QPainter painter(&image);
        QPen pen(penColor);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawRect(x111, y111, x222-x111, y222-y111);
    }
    if(bpie==1){
        bpie=0;
        QPainter painter(&image);
        QPen pen(penColor);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawPie(X,Y,W,H,A*16,Alen*16);
    }

    QPainter painter(this);
    painter.drawImage(targetRect, image, sourceRect);
}
