#include <iostream>
using namespace std;
class Cmycomplex
{
private:
    int re, im;

public:
    Cmycomplex();
    Cmycomplex(int c);
    Cmycomplex(int c , int d );
    void Set(int c, int d);
    void Show();
    Cmycomplex operator+(const Cmycomplex& z);
    friend Cmycomplex operator+(int temp,  Cmycomplex &a);
    friend Cmycomplex operator+( Cmycomplex &a, const int temp);
};
Cmycomplex::Cmycomplex()
{
    re = 0;
    im = 0;
};
Cmycomplex::Cmycomplex(int c)
{
    re = c;
    im = 0;
};
Cmycomplex::Cmycomplex(int c , int d )
{
    re = c;
    im = d;
};
void Cmycomplex::Set(int c, int d) { re = c, im = d; };
void Cmycomplex::Show()
{
    if (im > 0)
        cout << "(" << re << "+" << im << "i)";
    else
        cout << "(" << re << im << "i)";
};
Cmycomplex Cmycomplex::operator+(const Cmycomplex& z)
{
    Cmycomplex temp;
    temp.re = re + z.re;
    temp.im = im + z.im;
    return temp;
}
Cmycomplex operator+(int temp,  Cmycomplex &a)
{
    Cmycomplex news;
    news.re = a.re + temp;
    news.im = a.im;
    return news;
}
Cmycomplex operator+( Cmycomplex &a, const int temp)
{
    Cmycomplex news;
    news.re = a.re + temp;
    news.im = a.im;
    return news;
}
//StudybarCommentBegin
int main()
{
    Cmycomplex z1(3, 4), z2(7), z3, z4(z1);
    double x, y;
    cin >> x >> y;
    z3.Set(x, y);
    cout << endl;
    z3 = z3 + z2;
    z3.Show();
    z4 = 2 + z4;
    cout << endl;
    z4.Show();
    z4 = z4 + 2;
    cout << endl;
    z4.Show();
}
//StudybarCommentEnd
