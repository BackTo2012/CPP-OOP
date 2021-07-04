#include <iostream>
#include <cmath>
using namespace std;
class Point
{
protected:
	double x, y;
public:
	void SetPoint(double x = 0, double y = 0) {
		this->x = x, this->y = y;
	}
	double GetX() const {return x;}
	double GetY() const {return y;}
	void Move(double xOff, double yOff) {
		x += xOff, y += yOff;
	}
};
class Rectangle: public Point
{
public:
	void SetRect(double x, double y, double w, double h) {
		SetPoint(x, y); this->w = w; this->h = h;
	}
	double DistOfTwoR(const Rectangle& R) {
		double tmpx = x - R.x;
		double tmpy = y - R.y;
		return sqrt(tmpx * tmpx + tmpy + tmpy);
	}
	double GetW() const {	return w;	}
	double GetH() const {	return h;	}
private:
	double w, h;
};
//StudybarCommentBegin
int main()
{
	Rectangle rect, rect2;
	rect.SetRect(0, 0, 1, 1);
	rect.Move(3, 2);
	cout << "sizeof(Point):" << sizeof(Point) << " and sizeof(rect):"
	     << sizeof(rect) << ", (x,y,w,h) is (" << rect.GetX() << ","
	     << rect.GetY() << "," << rect.GetW() << "," << rect.GetH() << ")";
	rect2.SetRect(1, 1, 1, 1);
	rect2.Move(2, 3);
	cout << endl << rect2.DistOfTwoR(rect);
	return 0;
}
//StudybarCommentEnd