#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

const double PI = 3.1415926;
int flag=0;

Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    //    if (event->key() == Qt::Key_Up)
    //    {
    //        ui->label->move(ui->label->pos() + QPoint(0, -20));
    //    }
    //    else if (event->key() == Qt::Key_Down)
    //    {
    //        ui->label->move(ui->label->pos() + QPoint(0, 20));
    //    }
    //    else if (event->key() == Qt::Key_Left)
    //    {
    //        ui->label->move(ui->label->pos() + QPoint(-20, 0));
    //    }
    //    else if (event->key() == Qt::Key_Right)
    //    {
    //        ui->label->move(ui->label->pos() + QPoint(20, 0));
    //    }

    // ESC键
    //    case Qt::Key_Escape:
    //        qDebug() <<"ESC";
    //        break;
    //        // 回车键
    //    case Qt::Key_Return:
    //        qDebug() <<"Enter";
    //        break;
    //        // F1键
    //    case Qt::Key_F1:
    //        qDebug() <<"F1";
    //        break;

    if(event->key() == Qt::Key_1){
        a += "1"; // 将 '1' 添加到字符串 'a'
        ui->res->setText(a); // 将字符串 'a' 的内容设置为文本框的文本
    }
    else if (event->key() ==Qt::Key_2){
        a += "2"; // 将 '1' 添加到字符串 'a'
        ui->res->setText(a); // 将字符串 'a' 的内容设置为文本框的文本
    }
    else if (event->key() ==Qt::Key_3){
        a += "3"; // 将 '1' 添加到字符串 'a'
        ui->res->setText(a); // 将字符串 'a' 的内容设置为文本框的文本
    }
    else if (event->key() ==Qt::Key_4){
        a += "4"; // 将 '1' 添加到字符串 'a'
        ui->res->setText(a); // 将字符串 'a' 的内容设置为文本框的文本
    }
    else if (event->key() ==Qt::Key_5){
        a += "5";
        ui->res->setText(a);
    }
    else if (event->key() == Qt::Key_6){
        a += "6";
        ui->res->setText(a);
    }
    else if (event->key() ==Qt::Key_7){
        a += "7";
        ui->res->setText(a);
    }
    else if (event->key() ==Qt::Key_8&&(flag==0)){
        a += "8";
        ui->res->setText(a);
    }
    else if (event->key() ==Qt::Key_9){
        a += "9";
        ui->res->setText(a);
    }
    else if (event->key() ==Qt::Key_0){
        a += "0";
        ui->res->setText(a);
    }
    else if (event->key() ==Qt::Key_Period){
        a += ".";
        ui->res->setText(a);
    }

    else if (event->key() ==Qt::Key_Minus){
        b.insert(0,a); // 将字符串a插入到字符串b的首位
        a.clear(); // 清空字符串a
        b.insert(1,"-"); // 在字符串b的第1个位置插入"-"符号
        ui->res->setText("-"); // 将字符串a的内容设置为文本框的文本
    }
    else if (event->key() ==Qt::Key_Slash){
        b.insert(0,a); // 将字符串a插入到字符串b的首位
        a.clear(); // 清空字符串a
        b.insert(1,"/"); // 在字符串b的第1个位置插入"/"符号
        ui->res->setText("/"); // 将字符串a的内容设置为文本框的文本
    }

    else if (event->key() == Qt::Key_S){
        b.insert(0,0);//填充0位
        b.insert(1,"sin"); // 在字符串b的第1个位置插入"sin"符号
        ui->res->setText("sin"); // 将字符串a的内容设置为文本框的文本
    }
    else if (event->key() ==Qt::Key_C){
        b.insert(0,0);//填充0位
        b.insert(1,"cos"); // 在字符串b的第1个位置插入"cos"符号
        ui->res->setText("cos"); // 将字符串a的内容设置为文本框的文本
    }
    else if (event->key() ==Qt::Key_T){
        b.insert(0,0);//填充0位
        b.insert(1,"tan"); // 在字符串b的第1个位置插入"tan"符号
        ui->res->setText("tan"); // 将字符串a的内容设置为文本框的文本
    }
    else if (event->key() == Qt::Key_Q){
        b.insert(0,0);//填充0位
        b.insert(1,"sqrt"); // 在字符串b的第1个位置插入"sqrt"符号
        ui->res->setText("sqrt"); // 将字符串a的内容设置为文本框的文本
    }
    else if (event->key() == Qt::Key_Equal&&(flag==0)){
        if (!a.isEmpty() && !b.isEmpty()) {
            b.insert(2, a); // 在字符串b的第2个位置插入字符串a
            float v3;
            if (b.at(1) == "+") { // 判断字符串b的第1个元素是否为"+"
                v3 = QString(b.at(0)).toFloat() + QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为浮点数，并进行加法运算
                ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
            } else if (b.at(1) == "-") { // 判断字符串b的第1个元素是否为"-"
                v3 = QString(b.at(0)).toFloat() - QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为浮点数，并进行减法运算
                ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
            } else if (b.at(1) == "*") { // 判断字符串b的第1个元素是否为"*"
                v3 = QString(b.at(0)).toFloat() * QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为整数，并进行乘法运算
                ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
            } else if (b.at(1) == "/") { // 判断字符串b的第1个元素是否为"/"
                if(b.at(2)=="0"){
                    ui->res->setText("输入不合法！");
                }
                else{
                    v3 = QString(b.at(0)).toFloat() / QString(b.at(2)).toFloat(); // 将字符串b的第0个和第2个元素转换为整数，并进行除法运算
                    ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
                }
            } else if(b.at(1) == "sin"){
                if((QString(b.at(2)).toFloat())>(PI/2)){
                    ui->res->setText("输入不合法！");
                }else{
                    v3 = sin(QString(b.at(2)).toFloat()); // 将字符串b的第0个和第2个元素转换为浮点数，并进行乘法运算
                    ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
                }
            }else if(b.at(1) == "cos"){
                if((QString(b.at(2)).toFloat())>(PI/2)){
                    ui->res ->setText("输入不合法！");
                }else{
                    v3 = cos(QString(b.at(2)).toFloat()); // 将字符串b的第0个和第2个元素转换为浮点数，并进行乘法运算
                    ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
                }
            }else if(b.at(1) == "tan"){
                if((QString(b.at(2)).toFloat())>(PI/2)){
                    ui->res->setText("输入不合法！");
                }else{
                    v3 = tan(QString(b.at(2)).toFloat()); // 将字符串b的第0个和第2个元素转换为浮点数，并进行乘法运算
                    ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
                }
            }else if(b.at(1) == "sqrt"){
                if((QString(b.at(2)).toFloat())<0){
                    ui->res->setText("输入不合法！");
                }else{
                    v3 = sqrt(QString(b.at(2)).toFloat()); // 开根号
                    ui->res->setText(QString::number(v3)); // 将结果转换为字符串，并将其设置为文本框的文本
                }
            }

            // 清空a和b，同时将结果保存到a，以便后续计算
            a = QString::number(v3);
            b.clear();
        }
        else {
            b.insert(0, a); // 将字符串a插入到字符串b的首位
            a.clear(); // 清空字符串a
        }
    }

    else if (event->key() == Qt::Key_Backspace){
        a.chop(1);
        ui->res->setText(a); // 将字符串 'a' 的内容设置为文本框的文本
    }

    else if (event->key() == Qt::Key_Delete){
        a.clear(); // 清空字符串a
        b.clear(); // 清空字符串b
        ui->res->setText("0"); // 将文本框的文本设置为"0"

    }
    // 两键组合
    else if(event->modifiers() == Qt::ControlModifier) {flag=1; }// 如果按下了CTRL键
    else if(event->key() == Qt::Key_Equal&&(flag==1)){//"+"
        b.insert(0,a); // 将字符串a插入到字符串b的首位
        a.clear(); // 清空字符串a
        b.insert(1,"+"); // 在字符串b的第1个位置插入"+"符号
        ui->res->setText("+"); // 将字符串a的内容设置为文本框的文本
        flag=0;
    }


      else  if(event->key() == Qt::Key_8&&(flag==1)){//"*"
            b.insert(0,a); // 将字符串a插入到字符串b的首位
            a.clear(); // 清空字符串a
            b.insert(1,"*"); // 在字符串b的第1个位置插入"+"符号
            ui->res->setText("*"); // 将字符串a的内容设置为文本框的文本
            flag=0;
        }

    //    else     ui->lineEdit->setText("输入不合法！"); // 将字符串a的内容设置为文本框的文本

}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_B)
    {
        b.insert(0,a); // 将字符串a插入到字符串b的首位
        a.clear(); // 清空字符串a
        b.insert(1,"*"); // 在字符串b的第1个位置插入"+"符号
        ui->res->setText("*"); // 将字符串a的内容设置为文本框的文本
    }
    //    else if (event->key() == Qt::Key_Down)
    //    {
    //        ui->label->move(ui->label->pos() + QPoint(0, -20));
    //    }
    //    else if (event->key() == Qt::Key_Left)
    //    {
    //        ui->label->move(ui->label->pos() + QPoint(20, 0));
    //    }
    //    else if (event->key() == Qt::Key_Right)
    //    {
    //        ui->label->move(ui->label->pos() + QPoint(-20, 0));
    //    }
}
