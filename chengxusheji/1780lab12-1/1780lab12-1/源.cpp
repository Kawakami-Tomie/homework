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
    ~Shape() {}//����
    virtual void input() = 0;//��Ϊ�鷽��
    virtual void computeArea() = 0;//����ָ��ĺ������������virtual����ݶ�̬�Ե���������ĺ��������û��virtual�����������û���ĺ�����
    virtual void computePerimeter() = 0;
    virtual void display() = 0;
};
//����������
class Rectangle : public Shape//��Rectangle�̳���Shape��ȫ������
{
private:
    float length, width;
public:
    Rectangle() {
        strcpy_s(name, "����");// strcpy�Ǹ��ǿ���������״ȫ���ǿ�����name����strcpy_s()�������Ӱ�ȫ
        length = 0;
        width = 0;
    }
    ~Rectangle() {}//����

    void input() {
        cout << "��������εĳ�: ";
        cin >> length;
        cout << "��������εĿ�: ";
        cin >> width;
    }

    void computeArea()//�������
    {
        area = length * width;
    }

    void computePerimeter()//�����ܳ�
    {
        perimeter = 2 * (length + width);
    }

    void display() {
     
        cout << name << "\t" << area << "\t" << perimeter << "\t" << "��/��: " << length<<"/"<<width << endl;
    }
};
class Square : public Rectangle {
private:
    float side;
public:
    Square() {
        strcpy_s(name, "������");
        side = 0;
    }
    ~Square() {}

    void input() {
        cout << "�����������εı߳�: ";
        cin >> side;
    }

    void computeArea() {
        area = side * side;
    }

    void computePerimeter() {
        perimeter = 4 * side;
    }

    void display() {
        cout << name << "\t" << area << "\t" << perimeter << "\t" << "�߳�: " << side << endl;
    }
};
class Circle : public Shape 
{
private:
    float radius;
public:
    Circle() {
        strcpy_s(name, "Բ");
        radius = 0;
    }
    ~Circle() {}

    void input() {
        cout << "������Բ�İ뾶: ";
        cin >> radius;
    }

    void computeArea() {
        area = 3.14 * radius * radius;
    }

    void computePerimeter() {
        perimeter = 2 * 3.14 * radius;
    }

    void display() {
        cout <<  name <<"\t"<< area<<"\t"<<perimeter<<"\t" << "�뾶: " << radius<<endl;
    }
};
int main() {
    int choice, n, i;
    Shape* s[10];

    cout << "������ͼ�εĸ���: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\n��ѡ����״:\n1.����\n2.������\n3.Բ ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            s[i] = new Rectangle();//new����������Ҫָ�����
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
        s[i]->input();//ָ��ṹ�塢C++�е�class�Ⱥ��������ݵ�ָ������ȡ������
        s[i]->computeArea();
        s[i]->computePerimeter();
    }

   
    cout << "\n___________________ͼ����Ϣ____________________\n";
    cout << "ͼ��\t���\t�ܳ�\t����" << endl;
    for (i = 0; i < n; i++) {
        s[i]->display();
    }
    return 0;
}
//new���ٵĿռ��ڶ��ϣ���һ�������ı��������ջ��