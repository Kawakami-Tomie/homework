#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_line_triggered()
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

void MainWindow::on_color_triggered()
{
    color = QColorDialog::getColor(Qt::red, this, "边框颜色");
    update();
}

void MainWindow::setBackgroundColor(const QString &colorCode) {
    this->setStyleSheet("background-color: " + colorCode + ";");
}
void MainWindow::on_bgcolor_triggered()
{
    colorb=QColorDialog::getColor(Qt::black,this,"选择背景颜色");
    if (colorb.isValid()) {
        // 将 QColor 转换为 #RRGGBB 格式的字符串
        QString colorCode = colorb.name(QColor::HexRgb);
//        setBackgroundColor(colorCode);
        image.fill(colorCode);

    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    int wid=this->geometry().width();//获取窗口的宽高
    int heg=this->geometry().height()-51;//减去工具栏
    QRectF targetRect(0, 51, wid, heg); // 目标矩形区域，为窗口的宽和高
    QRectF sourceRect(0, 0, image.width(), image.height()); // 图片源矩形区域，表示图片的有效部分

    if(bline==1){
        bline=0;
        QPainter painter(&image);
        QPen pen(color);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawLine(x1, y1, x2, y2);
    }
    if(bcircle==1){
        bcircle=0;
        QPainter painter(&image);
        QPen pen(color);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawEllipse(x-r, y-r, 2*r, 2*r);
    }
    if(brect==1){
        brect=0;
        QPainter painter(&image);
        QPen pen(color);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawRect(xr,yr,chang,kuan);
    }
    if(bpie==1){//扇形
        bpie=0;
        QPainter painter(&image);//绘制目标
        QPen pen(color);
        pen.setStyle(penStyle);
        pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.setBrush(brushColor);
        painter.drawPie(X,Y,W,H,A*16,Alen*16);//外接矩阵左上角坐标，宽高，起始角度，覆盖角度
    }

    QPainter painter(this);//当前窗口
    painter.drawImage(targetRect, image, sourceRect);

}

void MainWindow::on_cuxi_triggered()
{
    bool ok;
    penWidth = QInputDialog::getInt(this, tr("输入"), tr("请输入画笔宽度:"), 1, 1, 1000, 1, &ok);
    if (!ok) return;
    update();
}

void MainWindow::on_style_triggered()
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


void MainWindow::on_circle_triggered()
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


void MainWindow::on_rect_triggered()
{
    bool ok = false;
    int x4=0, y4 = 0, chang1 = 0,kuan1=0;
    x4 = QInputDialog::getInt(this, "输入","请输入x4坐标",0,0,800,1,&ok);
    if(ok) y4 = QInputDialog::getInt(this,"输入","请输入y4坐标",0,0,600,1,&ok);
    if(ok) chang1 = QInputDialog::getInt(this,"输入","请输入长",0,0,800,1,&ok);
    if(ok) kuan1 = QInputDialog::getInt(this,"输入","请输入宽",0,0,800,1,&ok);
    if(ok){
        xr=x4;
        yr=y4;
        chang=chang1;
        kuan=kuan1;
    }
    brect=1;
    update();
}



void MainWindow::on_clear_triggered()
{
    image.fill(Qt::white);
    update();
}


void MainWindow::on_shan_triggered()
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

