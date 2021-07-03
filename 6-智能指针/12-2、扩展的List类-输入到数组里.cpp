#include <iostream>
#include <vector>
using namespace std;
class List
{
private:
	int data;
	List *link;
public:
	List();
	void getLength();
	List(vector<int> t);
	List(const List &t);
	void append(int val);
	void insertElement(int pos, int val);
	void deleteElement(int val);
	void travalList() const;
};
void List::getLength()
{
	int i = 1;
	List *p = this;
	for (; p->link != NULL;)
	{
		i++;
		p = p->link;
	}
	cout << "The length of this List is " << i << "." << endl;
}
List::List(const List &t)
{	this->data = 0;
	this->link = NULL;
	List *p = t.link;
	this->append(t.data);
	for (; p->link != NULL;)
	{
		this->append(p->data);
		p = p->link;
	}
	append(p->data);
}
List::List(vector<int> t)
{	this->data = 0;
	this->link = NULL;
	int i, size = t.size();
	for (i = 0; i < size; i++)
	{
		this->append(t[i]);
	}
}
void List::travalList() const
{
	List *p = this->link;
	cout << "->" << this->data;
	for (; p->link != NULL;)
	{
		cout << "->" << p->data;
		p = p->link;
	}
	cout << "->" << p->data << endl;
}
void List::deleteElement(int val)
{	int i = 0;
	List *p = this;
	List *s;
	for (; p->link != NULL;)
	{	if (p->data == val)
		{	i = 1;
			break;
		}
		s = p;
		p = p->link;
	}
	if (i == 0)
		cout << "Element " << val << " not Found." << endl;
	else
	{
		s->link = p->link;
		delete p;
	}
}
List::List()
{
	data = 0;
	link = NULL;
}
void List::append(int val)
{	if (this->data == 0)
	{	this->data = val;
	}
	else
	{	List *p = new List();
		p->data = val;
		List *tmp = this;
		for (; tmp->link != NULL;)
			tmp = tmp->link;
		tmp->link = p;
	}
}
void List::insertElement(int pos, int val)
{
	int i;
	List *p = this;
	for (i = 0; i < pos + 1; i++)
	{
		p = p->link;
	}
	List *tmp = p->link;
	List *s = new List();
	s->data = val;
	p->link = s;
	s->link = tmp;
}

//StudybarCommentBegin
int main(void)
{
	int n;
	List  listA;

	cin >> n;
	while (n != -1)
	{
		listA.append(n);
		cin >> n;
	}

	listA.travalList();
	List listB(listA);
	listA.append(250);
	listB.getLength();
	listB.travalList();
}
//StudybarCommentEnd