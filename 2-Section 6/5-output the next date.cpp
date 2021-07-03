#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using namespace std;
class date {
private:
	int y;
	int m;
	int d;
public:
	date(int year = 0, int month = 0, int day = 0) {y = year, m = month, d = day; };
	date operator ++(int) {
		date tmp = *this; d++;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d <= 31) {
				return tmp;
			}
			else {
				d -= 31;
				m++;
				if (m < 12) {	return tmp;}
				else {
					m -= 12; y++; return tmp;
				}
			}
		}
		else {
			if (m == 2) {
				if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
					if (d > 29) {
						d -= 29;
						m++;
						if (m < 12) {return tmp;}
						else {
							m -= 12; y++;
							return tmp;
						}
					}
					else {	return tmp;}
				}
				else {
					if (d > 28) {
						d -= 28; m++;
						if (m < 12) {	return tmp;}
						else {
							m -= 12; y++;
							return tmp;
						}
					}
					else {
						return tmp;
					}
				}
			}
			else {
				if (d > 30) {
					d -= 30;
					m++;
					if (m < 12) {
						return tmp;
					}
					else {
						m -= 12;
						y++;
						return tmp;
					}
				}
				else {
					return tmp;
				}
			}
		}
	}

	int year() {return y;};
	int month() {return m;};
	int day() {return d;};

};
//StudybarCommentBegin
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	date D1, D2;

	int year;
	int month;
	int day;

	cin >> year >> month >> day; //shu ru di yi ge ri qi
	D1 = date(year, month, day);

	D2 = D1++;

	cout << D1.year() << " " << D1.month() << " " << D1.day() << endl;
	cout << D2.year() << " " << D2.month() << " " << D2.day() << endl;
	return 0;
}
//StudybarCommentEnd