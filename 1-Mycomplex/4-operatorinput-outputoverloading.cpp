#include <iostream>
#include <iomanip>
using namespace std;
class ComplexNumber
{
private:
	double re, im;

public:
	ComplexNumber();
	ComplexNumber(double c);
	ComplexNumber(double c , double d );
	void Set(double c, double d);
	ComplexNumber operator+(const ComplexNumber& z);
	ComplexNumber operator-(const ComplexNumber& z);
	ComplexNumber operator*(const ComplexNumber& z);
	ComplexNumber operator/(const ComplexNumber& z);
	friend istream& operator>>(istream& , ComplexNumber& z);
	friend ostream& operator<<(ostream& , const ComplexNumber& z);
};
ComplexNumber::ComplexNumber()
{
	re = 0;
	im = 0;
};
ComplexNumber::ComplexNumber(double c)
{
	re = c;
	im = 0;
};
ComplexNumber::ComplexNumber(double c , double d )
{
	re = c;
	im = d;
};
void ComplexNumber::Set(double c, double d) { re = c, im = d; };
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z)
{
	return ComplexNumber(re + z.re, im + z.im);
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) {
	return ComplexNumber(re - z.re, im - z.im);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) {
	return ComplexNumber(re * z.re - im * z.im, re * z.im + im * z.re);
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& z) {
	return ComplexNumber((re * z.re + im * z.im) / (z.re * z.re + z.im * z.im), (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im));
}

istream& operator>>(istream& in, ComplexNumber& z) {
	in >> z.re >> z.im ;
	return in;
}
ostream& operator<<(ostream& out, const ComplexNumber& z) {
	if (z.im == 0)
	{
		if (z.im > 0)
		{
			out << z.re << "+" << z.im << "i";
			return out;

		}
		else
		{
			return out  << z.re << z.im << "i";
			return out;
		}
	}
	else {
		if (z.im > 0)
		{
			out << setiosflags(ios::fixed) << setprecision(2) << z.re << "+" << setiosflags(ios::fixed) << setprecision(2) << z.im << "i";
			return out;

		}
		else
		{
			out << setiosflags(ios::fixed) << setprecision(2) << z.re << setiosflags(ios::fixed) << setprecision(2) << z.im << "i";
			return out;
		}
	}



}





//StudybarCommentBegin
void CN() { //ComplexNumber
	ComplexNumber cn1, cn2;
	std::cin >> cn1 >> cn2;
	std::cout << cn1 + cn2 << std::endl;
	std::cout << cn1 - cn2 << std::endl;
	std::cout << cn1*cn2 << std::endl;
	std::cout << cn1 / cn2 << std::endl;
}
int main(void) {
	CN();
	return 0;
}
//StudybarCommentEnd