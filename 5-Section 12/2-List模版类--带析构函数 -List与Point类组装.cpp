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