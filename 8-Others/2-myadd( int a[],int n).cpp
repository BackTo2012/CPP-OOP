#include <iostream>
using namespace std;


int myadd(int a, int b)
{
	return a + b;
}
int myadd(int a[], int b)
{
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += a[i];
	}
	return sum ;
}
int myadd(int a, int b, int c)
{
	return a + b + c;
}





//StudybarCommentBegin
main()
{
	int a[20], n, i;

	cin >> n;
	if (n == 2)
		cout << myadd(5, 3);
	else if (n == 3)
		cout << myadd(5, 3, 9);
	else if (n > 3)
	{
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		cout << myadd(a, n);
	}

}
//StudybarCommentEnd