#include <iostream>
using namespace std;
int circularshift(int& a, int& b, int& c)
{
	int temp;
	temp = c;
	c = b;
	b = a;
	a = temp;
	return 0;
}

//StudybarCommentBegin

int main( )
{
	int i, j, k;
	cin >> i >> j >> k;
	circularshift(i, j, k);
	cout << i << " " << j << " " << k << endl;
	return 0;
}
//StudybarCommentEnd