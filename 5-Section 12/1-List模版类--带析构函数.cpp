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
    ListNode<T>* p = Head, *psave = p;
    while (p != NULL)    {
        psave = p;
        cout << "The data " << psave->data << " will be deleted!" << endl;
        p = p->link;
    }
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










//StudybarCommentBegin
int main(void)
{
    List<int> list1;
    list1.append(10.5);
    list1.append(8.5);
    list1.append(12.9);
    list1.append(100.9);
    list1.append(8.9);
    list1.travalList();

    List<double> list2;
    list2.append(10.5);
    list2.append(8.5);
    list2.append(12.5);
    list2.append(100.5);
    list2.append(8.5);
    list2.travalList();

    List<char> list3;
    list3.append('I');
    list3.append('L');
    list3.append('O');
    list3.append('V');
    list3.append('E');
    list3.append('U');
    list3.travalList();

    List<float> list4;
    list4.append('I' * 1.2);
    list4.append('L');
    list4.append('O');
    list4.append('V');
    list4.append('E');
    list4.append('U');
    list4.travalList();

    List<string> list5;
    list5.append("编程");
    list5.append("数学");
    list5.append("计算系统（计算工具本身）");
    list5.append("健康快乐生活");
    list5.append("培养方案");
    list5.travalList();

}
//StudybarCommentEnd
