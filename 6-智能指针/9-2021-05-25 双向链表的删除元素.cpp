
//StudybarCommentBegin
#include <iostream>
using namespace std;
class Node
{
public:
	int dat;
	Node *pre;	//前一个元素
	Node *next;	//后一个元素
	Node(int val)
	{
		dat = val;
		pre = next = NULL;
	}
};
class TList
{
private:
	Node* first;
	Node* end;
public:
	TList()
	{
		first = end = NULL;
	}
	void append(int val);	// 链尾增加一个元素
	void travalList()const;	// 从头节点遍历输出链表
	void retravalList()const;	// 从尾节点遍历输出链表
	void insertNode(int pos, int val);	//在指点位置添加一个元素
	void deleteNode(int pos);			//在指点位置删除一个元素

	~TList()
	{
		Node *p;
		Node *t;
		p = this->first;
		while (p)
		{
			t = p;
			p = p->next;
			delete t;
		}
		first = end = NULL;
	}
};
//StudybarCommentEnd

void TList::deleteNode(int pos) {
	if (first == NULL && end == NULL) {

	}
	else if (pos == 1) {
		first = first->next;

		first->pre = NULL;
	}
	else {
		int a = 0;
		Node *p;
		p = first;
		for (; p->next != NULL;) {
			a++;
			p = p->next;
		}
		if (pos > a) {
			end = end->pre;

			end->next = NULL;
		}
		else {
			Node *p2;
			Node *p1;

			p2 = first;
			for ( int i = 0 ; i < pos - 1 ; i++ ) {
				p2 = p2->next;
			}
			p1 = p2->next;
			p1 = p1->next;
			p2->next = p1;
			p1->pre = p2;

		}
	}
}
void TList::travalList()const
{
	Node *ptemp = this->first;
	if (this->first == NULL)
	{
		cout << "empty" << endl;
	}
	while (ptemp != NULL)
	{
		cout << ptemp->dat << " ";
		ptemp = ptemp->next;
	}
	cout << endl;
}
void TList::retravalList()const
{
	Node *ptemp = this->end;
	if (this->end == NULL)
	{
		cout << "empty" << endl;
	}
	while (ptemp)
	{
		cout << ptemp->dat << " ";
		ptemp = ptemp->pre;
	}
	cout << endl;
}
void TList::append(int val)
{
	Node* node = new Node(val);
	if (this->first == NULL)
	{
		first = node;
	}
	else
	{
		node->pre = end;
		end->next = node;
	}
	end = node;
}
void TList::insertNode(int pos, int val) {
	if (pos == 0) {
		Node *add = new Node(val);
		add->next = first;
		first->pre = add;
		first = add;
	}
	else
	{
		Node *add = new Node(val);
		int a = 0;
		Node *p;
		p = first;
		for (; p->next != NULL;) {
			a++;
			p = p->next;
		}
		if (pos > a) {
			end->next = add;
			add->pre = end;
			end = add;
		}
		else {
			Node *p2;
			Node *p1;

			p2 = first;
			for ( int i = 0 ; i < pos - 1 ; i++ ) {
				p2 = p2->next;
			}
			p1 = p2->next;
			p2->next = add;
			add->pre = p2;
			p1->pre = add;
			add->next = p1;
		}
	}

}

//StudybarCommentBegin
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	TList t;
	t.append(4);
	t.append(3);
	t.append(2);
	t.append(1);
	t.insertNode(a, b);
	t.travalList();
	t.deleteNode(c);
	t.travalList();
	return 1;
}
//StudybarCommentEnd