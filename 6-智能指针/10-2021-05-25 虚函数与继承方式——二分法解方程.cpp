#include <iostream>
using namespace std;
class CEquation {
public:
	virtual double fun (double x) {
		return CEquation::fun(x);
	}
	double bisectionSolve (double a , double b) {
		double m;
		if (fun(a)*fun(b) > 0) {
			cout << "error";
			return 0;
		}
		for (; b - a > 0.000001 || a - b > 0.0000001;) {
			m = (a + b) / 2;
			if (fun(a)*fun(m) < 0)
				b = m;
			else
				a = m;
		}
		return a;
	}
};

//StudybarCommentBegin
class newEquation: public CEquation
{
	virtual double fun (double x) {return x * x * x * x * x * x - 20 * x * x - 1;}
};
double slove(CEquation *pbase)
{
	return pbase->bisectionSolve(0, 10) ;
}
int main(int argc, char* argv[])
{
	newEquation  b;
	cout << slove(&b) << endl;
	return 0;
}
//StudybarCommentEnd