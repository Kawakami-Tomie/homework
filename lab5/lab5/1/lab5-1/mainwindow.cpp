#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QBrush>
#include <QPainter>
#include <QRectF>
#include <QDebug>
#include <QMouseEvent>
#include <QVector>
#include <QTextEdit>
#include <QColor>
#include <QColorDialog>
#include <QFontDialog>  //字体对话框
#include <QInputDialog>
#include <QPalette>
#include <QPoint>
#include "math.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _drawType=0;//描绘初始化为0，默认什么都不画
    _drag=0;//默认为非拖拽模式
    _openflag=0;//默认不打开图片
    QPen pen1;
    pen1.setColor(Qt::red);
    pen1.setWidth(5);
    pen1.setStyle(Qt::SolidLine);
    for(int i=0;i<20;i++)
    {
        pen[i]=pen1;
        pen_num[i]=-1;
    }
    opre_num=0;
    last_width=MainWindow::frameGeometry().width();
    last_height=MainWindow::frameGeometry().height();
    _tEdit = new QTextEdit(this);//初始化文本输入框
    _tEdit->hide();//隐藏
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(_openflag == 0)//不是打开图片的，每一次新建一个空白的画布
    {
        _pixmap = QPixmap(size());//新建pixmap
        _pixmap.fill(Qt::white);//背景色填充为白色
    }

    _pixmap.fill(BackGround);
    QPixmap pix = _pixmap;//以_pixmap作为画布
    QPainter p(&pix);//将_pixmap作为画布

    unsigned int i1=0,i2=0,i3=0,i4=0,i5=0;//各种图形的索引
    for(int c=0;c<_shape.size();++c)
    {
         p.setPen(pen[c]);
        if(_shape.at(c)==1)
        {
            const QVector<QPoint>& line = _lines.at(i1++);
            for(int j=0;j<line.size()-1;++j){
                QPoint temp1,temp2;
                temp1.setX(line.at(j).x()*MainWindow::frameGeometry().width()/last_width);
                temp1.setY(line.at(j).y()*MainWindow::frameGeometry().height()/last_height);
                temp2.setX(line.at(j+1).x()*MainWindow::frameGeometry().width()/last_width);
                temp2.setY(line.at(j+1).y()*MainWindow::frameGeometry().height()/last_height);
                p.drawLine(temp1,temp2);
            }
        }
        else if(_shape.at(c) == 2)//矩形
        {
             p.drawRect(QRect(_rects.at(i2).topLeft().x()*MainWindow::frameGeometry().width()/last_width,
                              _rects.at(i2).topLeft().y()*MainWindow::frameGeometry().height()/last_height,
                              _rects.at(i2).bottomRight().x()*MainWindow::frameGeometry().width()/last_width,
                              _rects.at(i2).bottomRight().y()*MainWindow::frameGeometry().height()/last_height));
             i2++;
        }

        else if(_shape.at(c) == 3)//椭圆
        {
            p.drawEllipse(QRect(_ellipse.at(i3).x()*MainWindow::frameGeometry().width()/last_width,
                                _ellipse.at(i3).y()*MainWindow::frameGeometry().height()/last_height,
                                _ellipse.at(i3).width()*MainWindow::frameGeometry().width()/last_width,
                                _ellipse.at(i3).height()*MainWindow::frameGeometry().height()/last_height
                              ));
            i3++;
        }
        else if(_shape.at(c) == 4)//直线
        {
            p.drawLine(QPoint(_line.at(i4).topLeft().x()*MainWindow::frameGeometry().width()/last_width,
                              _line.at(i4).topLeft().y()*MainWindow::frameGeometry().height()/last_height),
                             QPoint(_line.at(i4).bottomRight().x()*MainWindow::frameGeometry().width()/last_width,
                                   _line.at(i4).bottomRight().y()*MainWindow::frameGeometry().height()/last_height));
            i4++;
        }
        else if(_shape.at(c) == 5)//文本
        {
            p.drawText(_tpoint.at(i5),_text.at(i5));
            i5++;
        }
        else if(_shape.at(c)==6)//圆
        {
            int r1=qMax(r*MainWindow::frameGeometry().width()/last_width,
                        r*MainWindow::frameGeometry().height()/last_height);
            p.drawEllipse(QPoint(yuanxin.x()*MainWindow::frameGeometry().width()/last_width,
                                       yuanxin.y()*MainWindow::frameGeometry().height()/last_height),r1,r1);
         }
    }
    p.end();
    p.begin(this);//将当前窗体作为画布
    p.drawPixmap(0,0, pix);//将pixmap画到窗体
}

void MainWindow::on_actionLine_triggered()
{
    _drawType=1;//为铅笔
    opre_num++;
    _tEdit->hide();//隐藏
}

void MainWindow::on_actionCircle_triggered()
{
     _drawType=6;//为圆
      _shape.append(6);
     yuanxin.setX(QInputDialog::getInt(this,"输入","输入圆心x坐标",0,0,1000,1));
     yuanxin.setY(QInputDialog::getInt(this,"输入","输入圆心y坐标",0,0,1000,1));
     r=QInputDialog::getInt(this,"输入","输入半径",0,0,1000,1);
     opre_num++;
     _tEdit->hide();//隐藏
}

void MainWindow::on_actionRet_triggered()
{
    _drawType=2;//为矩形
    opre_num++;
    _tEdit->hide();//隐藏
}

void MainWindow::on_actionclear_triggered()
{
    _drawType=7;
    _lines.clear();
    _rects.clear();
    _ellipse.clear();
    _circle.clear();
    _line.clear();
    _text.clear();
    _tpoint.clear();
    _shape.clear();
    QPen pen1;
    pen1.setColor(Qt::red);
    pen1.setWidth(5);
    pen1.setStyle(Qt::SolidLine);
    for(int i =0;i<20;i++)
    {
        pen[i]=pen1;
        pen_num[i]=-1;
    }
    opre_num=0;
    update();
    _tEdit->hide();//隐藏
}

void MainWindow::on_actionellipse_triggered()
{
    _drawType=3;//为椭圆
    opre_num++;
    _tEdit->hide();//隐藏
}

void MainWindow::on_actionline_triggered()
{
    _drawType=4;//为line
    opre_num++;
    _tEdit->hide();//隐藏
}
void MainWindow::on_actiontext_triggered()
{
    _drawType=5;//为文本

}

void MainWindow::mousePressEvent(QMouseEvent *e){//
    if(e->button()==Qt::LeftButton)
    {
        if(_drawType==1)
        {
            qDebug()<<"验证成功！"<<1;
            _lpress=true;
            QVector<QPoint> line;
            _lines.append(line);
            QVector<QPoint>& lastline=_lines.last();
            lastline.append(e->pos());
            _shape.append(1);
        }
        else if(_drawType==2)
        {
            qDebug()<<"验证成功！"<<2;
            _lpress=true;
            if(!_drag)
            {
                QRect rect;//鼠标按下矩形开始
                _rects.append(rect);
                QRect& lastRect=_rects.last();
                lastRect.setTopLeft(e->pos());
                _shape.append(2);
            }
            else if(_rects.last().contains(e->pos()))
            {
                _begin=e->pos();
            }
        }
        else if(_drawType == 3)//椭圆
        {
            _lpress = true;//左键按下标志
            if(!_drag)//非拖拽模式
            {
                QRect rect;//鼠标按下，椭圆开始
                _ellipse.append(rect);//将新椭圆添加到椭圆集合
                QRect& lastEllipse = _ellipse.last();//拿到新椭圆
                lastEllipse.setTopLeft(e->pos());//记录鼠标的坐标(新椭圆的左上角坐标)
                 _shape.append(3);
            }
            else if(_ellipse.last().contains(e->pos()))//如果在椭圆内按下
            {
                _begin = e->pos();//记录拖拽开始的坐标位置
            }
        }
        else if(_drawType == 4)//直线
        {
            _lpress = true;//左键按下标志
            QRect rect;//鼠标按下，直线一端开始
            _line.append(rect);//将新直线添加到直线集合
            QRect& lastLine = _line.last();//拿到新直线
            lastLine.setTopLeft(e->pos());//记录鼠标的坐标(新直线开始一端坐标)
            _shape.append(4);
        }
        else if(_drawType == 5)//文字
        {
            update();//触发窗体重绘
            QPoint p;//鼠标按下，文字开始
            _tpoint.append(p);//将文字坐标添加到文字位置集合
            QPoint& lastp = _tpoint.last();//拿到新文字
            lastp = e->pos();//记录鼠标的坐标
            _tEdit->setGeometry(lastp.x()-6,lastp.y()-17,90,90);//设置文本框的位置、大小

            _tEdit->show();//显示文本输入框
            _text.append("");//添加文本到文本集合
            _tEdit->clear();//因为全局只有一个，所以使用之前要清空
            _shape.append(5);
        }
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *e){

    if(_drag && ((_drawType == 2 && _rects.last().contains(e->pos()))
            || (_drawType == 3 && _ellipse.last().contains(e->pos()) )))
    {
        setCursor(Qt::SizeAllCursor);//拖拽模式下，并且在拖拽图形中，将光标形状改为十字

    }
    else
    {
        setCursor(Qt::ArrowCursor);//恢复原始光标形状
        _drag = 0;
    }
    if(_lpress)
    {
        if(_drawType==1)
        {
            if(_lines.size()<=0)return;
            QVector<QPoint>& lastline=_lines.last();
            lastline.append(e->pos());
            update();//触发窗体重绘
        }
        else if(_drawType==2)
        {
            if(_drag==0)
            {
                QRect& lastRect=_rects.last();
                lastRect.setBottomRight(e->pos());
            }
            else
            {
                QRect& lastRect=_rects.last();
                if(lastRect.contains(e->pos()))
                {
                    int dx=e->pos().x()-_begin.x();
                    int dy=e->pos().y()-_begin.y();
                    lastRect=lastRect.adjusted(dx,dy,dx,dy);
                    _begin=e->pos();
                }

            }
            update();//触发窗体重绘
        }
        else if(_drawType == 3)
         {
             if(_drag == 0)//非拖拽
             {
                QRect& lastEllipse = _ellipse.last();//拿到新椭圆
                lastEllipse.setBottomRight(e->pos());//更新椭圆的右下角坐标)
             }
             else//拖拽
             {
                QRect& lastEllipse = _ellipse.last();//拿到最后添加的矩形
                if(lastEllipse.contains(e->pos()))//在椭圆内部
                {
                    int dx = e->pos().x()-_begin.x();//横向移动x
                    int dy = e->pos().y()-_begin.y();//纵向移动y
                    lastEllipse = lastEllipse.adjusted(dx,dy,dx,dy);
                    _begin = e->pos();//刷新拖拽点起始坐标
                }
             }
             update();//触发窗体重绘
         }
         else if(_drawType == 4)
         {
            QRect& lastLine = _line.last();//拿到新直线
            lastLine.setBottomRight(e->pos());//更新直线另一端)
            update();//触发窗体重绘
         }
    }

}
void MainWindow::mouseReleaseEvent(QMouseEvent *e){
    if(_lpress)
    {
        if(_drawType == 1)
        {
            QVector<QPoint>& lastLine = _lines.last();//最后添加的线条，就是最新画的
            lastLine.append(e->pos());//记录线条的结束坐标
            _lpress = false;//标志左键释放
        }
        else if(_drawType == 2)
        {
            QRect& lastRect = _rects.last();//拿到新矩形
            if(!_drag)
            {
                lastRect.setBottomRight(e->pos());//不是拖拽时，更新矩形的右下角坐标)
                //刚画完矩形，将光标设置到新矩形的中心位置，并进入拖拽模式
                this->cursor().setPos(this->cursor().pos().x()-lastRect.width()/2,this->cursor().pos().y()-lastRect.height()/2);
                _drag = 1;
            }
            _lpress = false;
        }
        else if(_drawType == 3)
        {
            QRect& lastEllipse = _ellipse.last();//拿到新椭圆
            if(!_drag)
            {
                lastEllipse.setBottomRight(e->pos());//不是拖拽时，更新椭圆的右下角坐标)
                //刚画完椭圆，将光标设置到新椭圆的中心位置，并进入拖拽模式
                this->cursor().setPos(this->cursor().pos().x()-lastEllipse.width()/2,this->cursor().pos().y()-lastEllipse.height()/2);
                _drag = 1;
            }
            _lpress = false;
        }
        else if(_drawType == 4)
        {
            QRect& lastLine = _line.last();//拿到新矩形
            lastLine.setBottomRight(e->pos());//更新矩形的右下角坐标)
            _lpress = false;
        }
   }
}

void MainWindow::on_actionPenColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::red,this, tr("颜色对话框！"));
    pen[opre_num].setColor(color);
    update();
}

void MainWindow::on_actionPenW_triggered()
{
    int width;
    width=QInputDialog::getInt(
    this, //指向父对象的指针
    "Input_Width", //窗口标题
    "请输入需要的字体宽度", //窗口提示文本信息
     0, //默认值
     0, //最小值范围
     1000, //最大值范围
     1); //步长（单次操作，值递增幅度）
    pen[opre_num].setWidth(width);
    // _pen.setWidth(width);
    update();
}

void MainWindow::on_actionPenSty_triggered()
{
    QString items[]={"SolidLine","DashLine","DotLine","DashDotLine"};
    QStringList it;
    int num;
    it<<"SolidLine"<<"DashLine"<<"DotLine"<<"DashDotLine";
    QString a=QInputDialog::getItem(this,"边框样式","请选择边框样式",it,0,true);
    for(int i = 0; i < 4; i++)
    {
        if(items[i] == a)
        {
            num=i;
            break;
        }
    }
   pen[opre_num].setStyle(Qt::PenStyle(num+1));
   // _pen.setStyle(Qt::PenStyle(num+1));
}

void MainWindow::on_actionBackGroundColor_triggered()
{
  BackGround = QColorDialog::getColor(Qt::red,this, tr("颜色对话框！"));
}
