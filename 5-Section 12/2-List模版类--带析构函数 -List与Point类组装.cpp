//StudybarCommentBegin
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct ListNode {
    T data;
    ListNode *link;
};

template <typename T>
class List {
private:
    ListNode<T>* Head;
public:
    List();
    ~List();
    void append(T val);    // 链尾增加一个元素
    void travalList()const;    // 从头节点遍历输出链表
};

template <typename T>
List<T>::List() {
    this->Head = NULL;
}

template <typename T>
void List<T>::travalList()const {
    ListNode<T>* p = Head, *psave = p;
    while (p != NULL) {
        psave = p;
        cout << "->" << psave->data;
        p = p->link;
    }
    cout << "\n";
}
//StudybarCommentEnd



template <typename T>
List<T>::~List() {
    cout << "~List is called!  Its sizeof(ListNode<T>) is " << sizeof(ListNode<T>) << ", sizeof(T) is " << sizeof(T) << endl;
    ListNode<T>* x, *psave;
    x = Head;
    while (x != NULL)
    {
        psave = x->link;
        cout << "The data " << x->data << " will be deleted!" << endl;
        delete x;
        x = psave;
    }
    Head = NULL;
}
template <typename T>
void List<T>::append(T val) {
    ListNode<T>* p = new ListNode<T>;
    p->data = val;
    p->link = NULL;
    if (Head == NULL)
        Head = p;
    else
    {
        ListNode<T>* tmpp = Head;
        while (tmpp->link != NULL) {
            tmpp = tmpp->link;
        }
        tmpp->link = p;
    }
}   // 链尾增加一个元素





class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0): x(x), y(y) { //cout<<"this="<<this<<" ";
        cout << " Point(" << x << "," << y << ") is called" << endl;
    }
    Point(const Point  &p): x(p.x), y(p.y) { //cout<<"this="<<this<<" ";
        cout << "Copy constructor Point(" << p << ") is called" << endl;
    }
    Point & operator = (const Point  &p) {//cout<<"this="<<this<<" "; cout<<"&p="<<&p<<" ";
        cout << "Point's operator =(" << p << ") is called" << endl;
        x = p.x; y = p.y; return *this;
    }
    ~Point() {//cout<<"this="<<this<<" ";
        cout << "~Point(" << x << "," << y << ") is called" << endl;
    }
    friend ostream & operator << (ostream &, Point const & p);
};
ostream & operator << (ostream &out, Point const & p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
//StudybarCommentBegin
int main(void)
{
    List<Point> list6;
    Point p1(1, 2);
    list6.append(p1);
    list6.append(Point(2, 3));
    list6.append(Point(3, 4));
    list6.travalList();
}
//StudybarCommentEnd