//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
//StudybarCommentEnd
class Time {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public:
	Time(int y = 0, int mm = 0, int d = 0, int h = 0, int m = 0, int s = 0);
	void printTime();
	int setTime(int, int, int, int, int, int);
	Time& operator--();
	Time operator --(int);
	friend Time operator+(int, Time);
	friend int operator-(Time, Time);
};
int operator-(Time z, Time x)
{
	int n = 0;
	while (z.day != x.day || z.month != x.month || z.year != x.year || z.hour != x.hour || z.minute != x.minute || z.second != x.second) {
		n++;
		if (x.second == 59) {
			x.second = 0;
			if (x.minute == 59) {
				x.minute = 0;
				if (x.hour == 23) {
					x.hour = 0;
					if ( x.month == 4 || x.month == 6 || x.month == 9 || x.month == 11) {
						if (x.day == 31) {
							x.day = 1;
							x.month++;
						}
						else {
							x.day++;
						}
					}
					else if (x.month == 2) {
						if (x.year % 400 == 0 || (x.year % 100 != 0 && x.year % 4 == 0)) {
							if (x.day == 29) {
								x.day = 1;
								x.month++;
							}
							else {
								x.day++;
							}
						}
						else {
							if (x.day == 28) {
								x.day = 1;
								x.month++;
							}
							else {
								x.day++;
							}
						}
					}
					else if (x.month == 12) {
						if (x.day == 31) {
							x.day = 1;
							x.month = 1;
							x.year++;
						}
						else {
							x.day++;
						}
					}
					else {
						if (x.day == 30) {
							x.day = 1;
							x.month++;
						}
						else {
							x.day++;
						}
					}
				}
				else {
					x.hour++;
				}
			}
			else {
				x.minute++;
			}
		}
		else {
			x.second++;
		}
	}
	return n;
}
Time::Time(int y, int mm, int d, int h, int m, int s)
{
	year = y;
	month = mm;
	day = d;
	hour = h;
	minute = m;
	second = s;
}
void Time::printTime()
{
	cout << year << "/" << month << "/" << day
	     << " " << setfill('0') << setw(2) << hour
	     << ":" << setw(2) << minute << ":"
	     << setw(2) << second << endl;
}
int Time::setTime(int y, int mm, int d, int h, int m, int s)
{
	year = y;
	month = mm;
	day = d;
	if (0 <= h && h <= 23 && 0 <= m && s <= 59)
	{
		hour = h;
		minute = m;
		second = s;
		return 1;
	}
	else
	{
		return 0;
	}
}
Time& Time::operator--()
{
	if (second == 0) {
		if (minute == 0) {
			if (hour == 0) {
				second = 59;
				minute = 59;
				hour = 23;
				if (day == 1) {
					if (month == 5 || month == 7 || month == 10 || month == 12) {
						day = 30;
						month--;
						return *this;
					}
					else {
						if (month == 3) {
							if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
								month = 2;
								day = 29;
								return *this;
							}
							else {
								month = 2;
								day = 28;
								return *this;
							}
						}
						else if (month == 1) {
							day = 31;
							month = 12;
							year--;
							return *this;
						}
						else {
							day = 31;
							month--;
							return *this;
						}
					}
				}
				else
				{
					day--;
					return *this;
				}
			}
			else {
				second = 59;
				minute = 59;
				hour--;
				return *this;
			}
		}
		else {
			second = 59;
			minute--;
			return *this;
		}
	}
	else {
		second--;
		return *this;
	}
}
Time Time::operator --(int)
{
	Time old(year, month, day, hour, minute, second);
	if (second == 0) {
		if (minute == 0) {
			if (hour == 0) {
				second = 59;
				minute = 59;
				hour = 23;
				if (day == 1) {
					if (month == 5 || month == 7 || month == 10 || month == 12) {
						day = 30;
						month--;
						return old;
					}
					else {
						if (month == 3) {
							if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
								month = 2;
								day = 29;
								return old;
							}
							else {
								month = 2;
								day = 28;
								return old;
							}
						}
						else if (month == 1) {
							day = 31;
							month = 12;
							year--;
							return old;
						}
						else {
							day = 31;
							month--;
							return old;
						}
					}
				}
				else
				{
					day--;
					return old;
				}
			}
			else {
				second = 59;
				minute = 59;
				hour--;
				return old;
			}
		}
		else {
			second = 59;
			minute--;
			return old;
		}
	}
	else {
		second--;
		return old;
	}
	return old;
}
Time operator+(int h, Time z)
{
	int a, b, c, e;
	if (h >= 0) {
		a = h + z.second;
		if (a >= 60) {
			b = a / 60 + z.minute;
			if (b >= 60) {
				z.second = a - 60 * (a / 60);
				z.minute = b - 60 * (b / 60);
				c = b / 60 + z.hour;
				z.hour = c - 24 * (c / 24);
				if (c >= 24) {
					e = c / 24 + z.day;
					if (z.month == 1 || z.month == 3 || z.month == 5 || z.month == 7 || z.month == 8 || z.month == 10 || z.month == 12) {
						if (e <= 31)
						{
							z.day = e;
							return z;
						}
						else {

							z.month++;
							z.day = e - 31;
							if (z.month > 12) {
								z.year++;
								return z;
							}
							else {
								return z;
							}

						}
					}
					else {
						if (z.month == 2) {
							if (z.year % 400 == 0 || (z.year % 100 != 0 && z.year % 4 == 0)) {
								if (e > 29) {
									z.day = e - 29;
									z.month++;
									return z;
								}
								else {
									z.day = e;
									return z;
								}
							}
							else {
								if (e > 28) {
									z.day = e - 28;
									z.month++;
									return z;
								}
								else {
									z.day = e;
									return z;
								}
							}
						}
						else {
							if (z.day > 30) {
								z.day = e - 30;
								z.month++;
								return z;
							}
							else {
								z.day = e;
								return z;
							}
						}

					}
				}
				else {
					z.minute = 59;
					z.second = 59;
					z.hour = c;
					return z;
				}
			}
			else {
				z.second = 59;
				z.minute = b;
				return z;
			}
		}
		else {
			z.second = a;
			return z;
		}
	}
	else {
		a = z.second + h;
		if (a < 0) {
			b = a / 60 + z.minute - 1;
			if (b < 0) {
				z.second = a - 60 * ((a / 60) - 1);
				z.minute = b - 60 * ((b / 60) - 1);
				c = b / 60 + z.hour;
				z.hour = c - 24 * ((c / 24) - 1);
				if (c <= 0) {
					e = c / 24 + z.day;
					if (z.month ==  5 || z.month == 7 || z.month == 10 || z.month == 12) {
						if (e > 0)
						{
							z.day = e;
							return z;
						}
						else {

							z.month--;
							z.day = e + 30;
							return z;

						}
					}
					else {
						if (z.month == 3) {
							if (z.year % 400 == 0 || (z.year % 100 != 0 && z.year % 4 == 0)) {
								if (e <= 0) {
									z.day = e + 29;
									z.month = 2;
									return z;
								}
								else {
									z.day = e;
									return z;
								}
							}
							else {
								if (z.day <= 0) {
									z.day = e + 28;
									z.month--;
									return z;
								}
								else {
									z.day = e;
									return z;
								}
							}
						}
						else if (z.month == 1) {
							if (z.day <= 0) {
								z.day = e + 31;
								z.month = 12;
								z.year--;
							}
						}
						else {
							if (z.day <= 0 ) {
								z.day = e + 31;
								z.month--;
								return z;
							}
							else {
								z.day = e;
								return z;
							}
						}

					}
				}
				else {
					z.minute = 59;
					z.second = 59;
					z.hour = c;
					return z;
				}
			}
			else {
				z.second = 59;
				z.minute = b;
				return z;
			}
		}
		else {
			z.second = a;
			return z;
		}
	}
}
//StudybarCommentBegin
int main()
{

	int year, month, day;
	int hour, minute, second;
	int number;
	int capacity = 0;
	Time t1(2016, 3, 31, 23, 45, 0), t2, t3(t1), t4;
	cin >> year >> month >> day >> hour >> minute >> second;
	t1.setTime(year, month, day, hour, minute, second);
	cin >> year >> month >> day >> hour >> minute >> second;
	t2.setTime(year, month, day, hour, minute, second);
	cin >> number;
	cout << endl;
	t3 = t1--;
	t3.printTime();
	t1.printTime();
	t4 = --t1;
	t4.printTime();
	t4 = number + t1;
	t4.printTime();
	//capacity = t2 - t1;
	//cout << capacity << endl;
}
//StudybarCommentEnd
