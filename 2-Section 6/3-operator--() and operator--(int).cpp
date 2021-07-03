#include <iostream>
using namespace std;
class  Cmytime
{
private:
  int hour; int min; int sec;
public:;
  Cmytime(int h = 0, int m = 0, int s = 0) {};
  void Show() {
    if (0 <= hour && hour <= 23 && 0 <= min && sec <= 60)
      cout << hour << ":" << min << ":" << sec;
  };
  int Set(int h, int m, int s)
  { if (0 <= h && h <= 23 && 0 <= m && s <= 60)
    {   hour = h, min = m, sec = s; return 1;}
    else return 0;
  };
  Cmytime & operator--() {
    if (hour == 0 && min == 0 && sec == 0) {
      hour = 23, min = 59, sec = 59; return *this;
    }
    if (min == 0 && sec == 0) {
      hour = hour - 1, min = 59, sec = 59; return *this;
    }
    if (sec == 0) {min = min - 1, sec = 59; return *this;}
    else {sec = sec - 1; return *this;  }
  };

  Cmytime operator--(int) {
    Cmytime old = *this;
    --(*this);//调用前置“++”运算符
    return old;//返回++之前的值。
  };

};
//StudybarCommentBegin
int main(void) {
  int h, m, s;
  cin >> h >> m >> s;

  Cmytime t1, t2, t3;
  t1.Set(h, m, s);
  t1.Show();
  cout << endl << t1.Set(24, 0, 0) << "\n";
  t1.Show();

  t2 = --t1;
  t3 = t1--;

  cout << endl;
  t1.Show();
  cout << endl;
  t2.Show();
  cout << endl;
  t3.Show();


  return 0;
}
//StudybarCommentEnd