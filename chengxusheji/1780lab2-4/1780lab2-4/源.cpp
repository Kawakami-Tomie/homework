#include <iostream>
using namespace std;
#include<string>;
int main()
{
	string A,C;
	string W = "white";
	string L = "black";
	cout << "ÊäÈëA¡¢CµÄÑÕÉ«" << endl;
	cin >> A >> C;
	if (A != C)
	{
		cout << "B=" << C << endl;
		cout << "D=" << A << endl;
	}
	else if (A == C)
	{
		if (A == W)
		{
			cout << "B=" << L << endl;
			cout << "D=" << L << endl;
		}
		if (A == L)
		{
			cout << "B=" << W << endl;
			cout << "D=" << W << endl;
		}
	}
	return 0;
}
