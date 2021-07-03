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
    {   if (0 <= h && h <= 23 && 0 <= m && s <= 60)
        {   hour = h;
            min = m;
            sec = s;
            return 1;
        }
        else return 0;
    };
    Cmytime SubOneSecond() {
        if (hour == 0 && min == 0 && sec == 0)
            return Cmytime(hour = 23, min = 59, sec = 59);
        if (min == 0 && sec == 0)
            return Cmytime(hour = hour - 1, min = 59, sec = 59);
        if (sec == 0)
            return Cmytime(hour, min = min - 1, sec = 59);
        else
            return Cmytime(hour, min, sec = sec - 1);
    };
};





//StudybarCommentBegin
int main(void) {
    int h, m, s;
    cin >> h >> m >> s;

    Cmytime t1;
    t1.Set(h, m, s);
    t1.Show();
    cout << endl << t1.Set(24, 0, 0) << "\n";
    t1.Show();

    t1.SubOneSecond();
    cout << endl;
    t1.Show();

    return 0;
}
//StudybarCommentEnd