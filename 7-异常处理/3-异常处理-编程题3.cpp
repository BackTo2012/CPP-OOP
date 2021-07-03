//StudybarCommentBegin
#include <iostream>
#include<string>
using namespace std;
//StudybarCommentEnd
class MyString
{
private:
    char* s;
public:
    MyString(int a)
    {
        try
        {
            if (a > 10000000)
            {
                s = new char[10];
                s[1] = 1;
                throw - 1;
            }
            else
            {
                cout << "Constructing..." << endl;
                cout << "Construction finished." << endl;
                s = new char[a];
            }
        }
        catch (int e)
        {
            cout << "Constructor abnormal." << endl;
        }

    }
    ~MyString()
    {
        if (s[1] != 1)
        {
            cout << "Destruction finished." << endl;
        }

    }
    void ShowStr()
    {
        if (s[1] != 1)
        {
            cin >> s;
            cout << s << endl;

        }
    }
};
//StudybarCommentBegin
int main() {
    long a;
    cin >> a;
    try {
        if (a > 0) {
            MyString str1(a);   //生成容纳a个字符的字符串
            str1.ShowStr();
        }
        else
        {
            char* c = "Array length error.";
            throw c;
            //  throw "Array length error.";   work in VC not GCC

        }
    }
    catch (char* c) {
        cout << c << endl;
    }
    catch (...) {
        cout << "Other failures." << endl;
    }
    cout << "Main finished." << endl;
    return 0;
}
//StudybarCommentEnd