//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
//StudybarCommentEnd


class Time
{
private:
	int hour, minute, second;
public:
	Time(int a = 0, int b = 0, int c = 0) {hour = a, minute = b, second = c;};
	void setTime(int a, int b, int c) {hour = a, minute = b, second = c;};
	void printTime() { cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;}
	Time& operator++() {second++; return *this;};
	Time operator++(int) { Time old(hour, minute, second); second++; return old;};


	friend Time operator+(int h, Time z) {
		int c, d, e, f;
		c = h + z.second;
		if (c < 60) {
			z.second = c;
			return z;
		}
		else {

			d = c / 60;
			z.second = c - 60 * d;
			e = z.minute + d;
			if (e < 60) {
				z.minute = e;
				return z;
			}
			else {
				f = e / 60;
				z.hour += f;
				if (z.hour < 24) {
					z.minute = e - 60 * f;
					return z;
				}
				else {
					z.hour -= 24;
					z.minute = e - 60 * f;
					return z;
				}
			}

		}
	}
};



//StudybarCommentBegin
int main()
{
	int hour, minute, second;
	int increase;
	Time t1(23, 45, 0), t2, t3(t1);
	cin >> hour >> minute >> second >> increase;
	t1.setTime(hour, minute, second);
	t1.printTime();
	t2 = ++t1;      //This is  for ++t1
	t2.printTime();

	t3 = increase + t1;  //This is  for friend function
	t3.printTime();

	t1 = t2++;     //This is  for t2++
	t1.printTime();
	t2.printTime();

	t1 = (++t3)++;  // This is for left value (return the reference of  the object )
	t1.printTime();
	t3.printTime();
	return 0;
}
//StudybarCommentEnd
