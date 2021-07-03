//StudybarCommentBegin
#include <iostream>
#include<string>
using namespace std;
//StudybarCommentEnd
void f2()
{
    cout << "In f2 function" << endl;
    throw "Exception from f2";
}
int f1(int a, int b)
{
    if (b == 0)
        throw 4.2;
    else
    {
        try
        {
            f2();
        }
        catch (const char* c)
        {
            cout << c << endl;
        }
        cout << a << '%' << b << '=' << a % b << endl;
        cout << "In f1 function" << endl;
    }
}

int main()
{
    double m, n;
    int g, h;
    cin >> m >> n;
    try
    {
        for (int i = 0; i <= m; i++)
            g = i;
        for (int j = 0; j <= n; j++)
            h = j;
        if (m != g || n != h)
            throw - 1;
        else f1(m, n);
    }
    catch (int e)
    {
        cout << "Non-int was inputted, try again" << endl;
    }
    catch (double f)
    {
        cout << "You inputted:0" << endl;
    }
    cout << "In main function" << endl;

}
