#include <iostream>
using namespace std;
class Point
{
	double x, y;
public:
	void setPoint(double x = 0, double y = 0) {
		this->x = x, this->y = y;
	}
};
class Circle: public Point
{
	double radius;
public:
	void setRadius(double r) {radius = r;}
	double getArea() {
		return 3.1415926 * radius * radius;
	}
};

//StudybarCommentBegin
int main()
{
	Circle c;
	c.setPoint(1, 1);
	c.setRadius(2);
	cout << c.getArea();
}
//StudybarCommentEnd