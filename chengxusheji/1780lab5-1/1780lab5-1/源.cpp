#include<iostream>
#include<iomanip>
#include<string>

using namespace std;
class Car
{
public:
	Car()
	{
		ID = "0";
		MODEL = "0";
		POWER = 0;
		COLOR = "黑色";
		PRICE = 0;
	}

	void setID(string id)
	{
		ID = id;
	}
	void setModel(string model)
	{
		MODEL = model;
	}
	void setPower(int power)
	{
		POWER = power;
	}
	void setPrice(double price)
	{
		PRICE = price;
	}
	void setColor(string color)
	{
		COLOR = color;
	}
	string getID() { return ID; }
	string getModel() { return MODEL; }
	int getPower() { return POWER; }
	double getPrice() { return PRICE; }
	string getColor() { return COLOR; }
	void display()
	{
		cout << "编号为" << getID() << "的" << getModel() << "型汽车的颜色是" << getColor() << ",功率为" << getPower() << "马力，价格为" << getPrice() << endl;
	}
private:
	string ID;
	string MODEL;
	int POWER;
	double	PRICE;
	string COLOR;
};

int main()
{
	Car car1, car2, car3;
	string a,b;
	double d,PriceMax,PriceAverage;
	int c;
	string e;
	cout << "请依次输入第一辆车的编号（ID） , 型号（MODEL） ，功率（ POWER ），颜色（ COLOR），价格（ PRICE ）" << endl;
	cin >> a >> b >> c >> e >> d;
	car1.setID(a);
	car1.setModel(b);
	car1.setPower(c);
	car1.setPrice(d);
	car1.setColor(e);
	car1.display();
	cout << "请依次输入第二辆车的编号（ID） ,  型号（MODEL） ，功率（ POWER ），颜色（ COLOR），价格（ PRICE ）" << endl;
	cin >> a >> b >> c >> e >> d;
	car2.setID(a);
	car2.setModel(b);
	car2.setPower(c);
	car2.setPrice(d);
	car2.setColor(e);
	car2.display();
	cout << "请依次输入第三辆车的编号（ID） , 型号（MODEL） ，功率（ POWER ），颜色（ COLOR），价格（ PRICE ）" << endl;
	cin >> a >> b >> c >> e >> d;
	car3.setID(a);
	car3.setModel(b);
	car3.setPower(c);
	car3.setPrice(d);
	car3.setColor(e);
	car3.display();
	
	PriceMax = (car1.getPrice() > car2.getPrice() ? car1.getPrice() : car2.getPrice());
	PriceMax = (PriceMax > car3.getPrice() ? PriceMax : car3.getPrice());
	cout << "最高价格为" << PriceMax << endl;
	PriceAverage = (car1.getPrice() + car2.getPrice() + car3.getPrice()) / 3;
	cout << "平均价格为" << PriceAverage << endl;
	
	return 0;
}

