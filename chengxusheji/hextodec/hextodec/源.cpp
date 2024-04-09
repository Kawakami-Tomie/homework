#include <iostream>
using namespace std;

int hextoDec(int hex)
{
	int sum = 0, mul = 1;
	int i, r;
	int count = 0;
	do {
		r = hex % 16;
		for (i = 0; i < count; i++)
			mul *= 16;
		mul *= r;
		sum += mul;
		mul = 1;
		count++;
	} while (hex /= 16);
	return sum;
}
int main()
{
	
	cout << hextoDec(0x35) << endl;
	cout << int(0x35) << endl;
	


}

