#include <iostream>
using namespace std;

#include <math.h>
float left_high, right_high, right_low, left_low;
float point_x = 0, point_y = 0;
double distance = 105.3;
float hypotenuse = 0;
float AngleX = 0, AngleY = 0, PI = 3.14159625;
int x, y;
float AngleX_Turn(int x)
{

	AngleX = atan2(x, 105.3) * 180 / PI;
	return AngleX;

}
float AngleY_Turn(int x, int y)
{
	double  hypotenuse2 = x * x + 105.3 * 105.3;
	hypotenuse = sqrt(hypotenuse2);
	AngleY= atan2(y, hypotenuse) * 180 / PI;
	return AngleY;

}
int main()
{
	cin >> x >> y;
	cout << AngleX_Turn(x);
	cout<< AngleY_Turn(x, y);



}
