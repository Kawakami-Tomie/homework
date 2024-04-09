#include <iostream>
//#include <math.h>
using namespace std;

float xo = 83, yo = 85;
float Xa, Ya, Xb, Yb, Xc, Yc, Xd, Yd;
int xa=69, ya=59, xb=69, yb=39, xc=98, yc=38, xd=100, yd=59;
float numxa, numya, numxb, numyb, numxc, numyc, numxd, numyd;


int main()
{

	Xa = ((float)xa - xo) * 1.036269;
	Ya = (yo - (float)ya) * 1.036269;
	Xb = ((float)xb - xo) * 1.036269;
	Yb = (yo - (float)yb) * 1.036269;
	Xc = ((float)xc - xo) * 1.036269;
	Yc = (yo - (float)yc) * 1.036269;
	Xd = ((float)xd - xo) * 1.036269;
	Yd = (yo - (float)yd) * 1.036269;
	numxa = (Xb - Xa) * 0.025;
	numya = (Yb - Ya) * 0.025;
	numxb = (Xc - Xd) * 0.025;
	numyb = (Yc - Yd) * 0.025;
	numxc = (Xd - Xc) * 0.025;
	numyc = (Yd - Yc) * 0.025;
	numxd = (Xa - Xd) * 0.025;
	numyd = (Ya - Yd) * 0.025;
	cout << numya << endl;
	cout << "ok" << endl;
	return 0;

}


