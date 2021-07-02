#include <iostream>
using namespace std;
template <typename T>
T abs(T temp) {
	return  (temp >= 0) ? temp : -temp;
}
// abs(double temp) {
// 	return  (temp >= 0) ? temp : -temp;
// }

int main()
{
	int n = -5;
	double d = -5.5;
	cout << abs(n) << endl;
	cout << abs(d) << endl;
	return 0;
}