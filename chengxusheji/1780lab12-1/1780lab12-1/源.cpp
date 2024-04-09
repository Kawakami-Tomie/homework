#include<iostream>
#include<cstring>
using namespace std;

class Shape {
protected:
    char name[20];
    float area, perimeter;
public:
    Shape()
    {
        area = 0;
        perimeter = 0;
    }
    ~Shape() {}//析构
    virtual void input() = 0;//变为虚方法
    virtual void computeArea() = 0;//基类指针的函数调用如果有virtual则根据多态性调用派生类的函数，如果没有virtual则是正常调用基类的函数。
    virtual void computePerimeter() = 0;
    virtual void display() = 0;
};
//定义派生类
class Rectangle : public Shape//类Rectangle继承类Shape的全部特性
{
private:
    float length, width;
public:
    Rectangle() {
        strcpy_s(name, "矩形");// strcpy是覆盖拷贝，将形状全覆盖拷贝到name，而strcpy_s()函数更加安全
        length = 0;
        width = 0;
    }
    ~Rectangle() {}//析构

    void input() {
        cout << "请输入矩形的长: ";
        cin >> length;
        cout << "请输入矩形的宽: ";
        cin >> width;
    }

    void computeArea()//计算面积
    {
        area = length * width;
    }

    void computePerimeter()//计算周长
    {
        perimeter = 2 * (length + width);
    }

    void display() {
     
        cout << name << "\t" << area << "\t" << perimeter << "\t" << "长/宽: " << length<<"/"<<width << endl;
    }
};
class Square : public Rectangle {
private:
    float side;
public:
    Square() {
        strcpy_s(name, "正方形");
        side = 0;
    }
    ~Square() {}

    void input() {
        cout << "请输入正方形的边长: ";
        cin >> side;
    }

    void computeArea() {
        area = side * side;
    }

    void computePerimeter() {
        perimeter = 4 * side;
    }

    void display() {
        cout << name << "\t" << area << "\t" << perimeter << "\t" << "边长: " << side << endl;
    }
};
class Circle : public Shape 
{
private:
    float radius;
public:
    Circle() {
        strcpy_s(name, "圆");
        radius = 0;
    }
    ~Circle() {}

    void input() {
        cout << "请输入圆的半径: ";
        cin >> radius;
    }

    void computeArea() {
        area = 3.14 * radius * radius;
    }

    void computePerimeter() {
        perimeter = 2 * 3.14 * radius;
    }

    void display() {
        cout <<  name <<"\t"<< area<<"\t"<<perimeter<<"\t" << "半径: " << radius<<endl;
    }
};
int main() {
    int choice, n, i;
    Shape* s[10];

    cout << "请输入图形的个数: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\n请选择形状:\n1.矩形\n2.正方形\n3.圆 ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            s[i] = new Rectangle();//new创建对象需要指针接收
            break;
        }
        case 2:
        {
            s[i] = new Square();
            break;
        }
        case 3: 
        {
            s[i] = new Circle();
            break;
        }
        }
        s[i]->input();//指向结构体、C++中的class等含有子数据的指针用来取子数据
        s[i]->computeArea();
        s[i]->computePerimeter();
    }

   
    cout << "\n___________________图形信息____________________\n";
    cout << "图形\t面积\t周长\t参数" << endl;
    for (i = 0; i < n; i++) {
        s[i]->display();
    }
    return 0;
}
//new开辟的空间在堆上，而一般声明的变量存放在栈上