#include<vector>
#include <iostream>
using namespace std;

class List
{
private:
	int data;	// 存储元素
	List *link;	// 下一元素结构的指针
public:
	List();
	List(vector<int> c);
	List(List &L);//拷贝构造函数
	void append(int val);	// 链尾增加一个元素
	void insertElement(int pos, int val);	// 在指定位置添加一个元素
	void deleteElement(int val);	// 删除元素
	void travalList()const;	// 从头节点遍历输出链表
	void connect(List &L);
	bool isEqual(List &L);
	int getLength();
};


List::List()
{
	this->link = NULL;
}

List::List(vector<int> c)
{
	this->link = NULL;
	for (int i = 0; i < c.size(); i++)
	{
		append(c[i]);
	}
}

List::List(List &L)
{
	this->link = NULL;
	List *p = new List;
	p = L.link;
	while (p)
	{
		append(p->data);
		p = p->link;
	}
}

void List::append(int val)
{
	List *s = new List;
	List *p = this;
	s->data = val;
	s->link = NULL;
	if (this->link == NULL) { //空链表
		p->link = s;
	}
	else
	{
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = s;
	}
}

void List::insertElement(int pos, int val)
{
	List *s = new List;
	List *p = this->link;
	s->data = val;
	s->link = NULL;
	if (pos == 0) { //空链表
		p = s;
	}
	int i = -1;
	while (i < pos - 1 || !p)
	{
		p = p->link;
		i++;
	}
	if (!p)
	{
		append(val);
	}
	else
	{
		s->link = p->link;
		p->link = s;
	}
}

void List::deleteElement(int val) //按值删除
{
	List *p, *s;

	if (this->link->data == val) { //如果要删除头结点
		s = this->link;
		if (s)  // 如果不为空
		{
			this->link = s->link;
		}
		else
			return;
		delete s;   // 释放被删除结点
		return;
	}
	p = this->link;
	while (p->link && p->link->data != val)
	{
		p = p->link;
	}
	if (!p->link)
	{
		cout << "Element " << val << " not Found." << endl;
	}
	else {
		s = p->link;    // s 指向第 i 个结点
		p->link = s->link;  //从链表删除
		delete s;  // 释放被删除结点
	}
}

void List::travalList() const
{
	List *p = this->link;
	if (!p)
		cout << "NULL";
	while (p)
	{
		cout << "->" << p->data;
		p = p->link;
	}
	cout << endl;
}

bool List::isEqual(List &L)
{
	List *p = this->link;
	List *s = L.link;
	while (p || s)
	{
		if (p->data != s->data || p == NULL || s == NULL)
			return 0;
		p = p->link;
		s = s->link;
	}
	return 1;
}

void List::connect(List &L)
{
	cout << "After connect:" << endl;
	List *p = new List;
	p = L.link;
	while (p)
	{
		append(p->data);
		p = p->link;
	}
}

int List::getLength()
{
	List *p = this->link;
	int i = 0;
	while (p)
	{
		i++;
		p = p->link;
	}
	cout << "The length of this List is " << i << "." << endl;
	return i;
}



//StudybarCommentBegin
int main(void)
{
	int a;
	vector<int> in1, in2;
	while (cin >> a)
	{
		in1.push_back(a);
		if (getchar() == '\n')
			break;
	}
	while (cin >> a)
	{
		in2.push_back(a);
		if (getchar() == '\n')
			break;
	}
	List listA(in1), listB(in2);
	listA.travalList();
	listB.travalList();
	if (listA.isEqual(listB))
		cout << "They are the same LinkList." << endl;
	else
		cout << "They are different LinkList." << endl;
	listA.connect(listB);
	listA.getLength();
	listA.travalList();
}
//StudybarCommentEnd


