#include <bits\stdc++.h>
using namespace std;
int main()
{
	try
	{
		double x, y;
		cin >> x; cin >> y;
		if (y == 0)
		{
			throw 99;
		}
		else
		{
			cout << x / y;
		}
	}
	catch (int x)
	{
		cout << "Attempted to divide by zero!";
	}
	return 0;
}
