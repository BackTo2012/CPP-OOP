#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
	T data;
	Node* next;
	Node() {next = NULL;};
	Node(const T& x): data(x) , (next)  NULL{	};
	};
	template <class T>
	class List
{
	Node<T> *head, *tail;
public:
	List() {
		head = new Node<T>(0);
		tail = head;
		// head = NULL;
		// tail = NULL;
	}
	~List() {
		if (head->next != NULL)
		{
			Node<T>* temp = head->next;
			while (temp != NULL)
			{
				Node<T>* tmpp = temp;
				temp = temp->next;
				delete tmpp;
			}
		}
		delete head;
	}
	void push_back(const T& x) {
		// Node<T> *newhead = new Node<T>;
		// newhead->data = x;
		// newhead->next = NULL;
		// if (head == NULL)
		// {
		// 	head = newhead;
		// 	tail = newhead;
		// }
		// else
		// {
		// 	tail->next = newhead;
		// 	tail = newhead;
		// }
		Node<T> *p = new Node<T>(x);
		p->data = x;
		p->next = NULL;
		if (head == NULL)
		{
			head = p; tail = p;
		}
		else
		{
			Node<T> *tmpp = tail;
			tmpp->next = p;
			tail = p;
		}
	}
	T& operator[](int n) {
		// int Index = 0;
		// Node<T> *temp = head;
		// while (temp->next != NULL)
		// {
		// 	if (Index == i)
		// 		return temp->data;
		// 	Index++;
		// 	temp = temp->next;
		// }
		// return temp->data;
		int def = 0;
		if (head == NULL)
		{
			cout << "empty"; exit(0);
		}
		else
		{
			Node<T>* t = head;
			do
			{
				if (def > n)
					return t->data;
				t = t->next;
				def++;
			} while (t != NULL);
		}
	}
	List(const List<T>& list) {
		head = new Node<T>(0);
		tail = head;
		Node<T>* t = list.head;
		Node<T>* temp = head;
		while (t->next != NULL)
		{
			t = t->next;
			Node<T>* newnode = new Node<T>(t->data);
			temp->next = newnode;
			temp = newnode;
			tail = temp;
		}
		// head = z.head;
		// tail = z.tail;
		// if (head == NULL)
		// {
		// 	head = NULL;
		// 	tail = NULL;
		// }
		// else
		// {
		// 	head = NULL;
		// 	tail = NULL;
		// 	Node<T>*temp = head;
		// 	while (temp->next != NULL) {
		// 		push_back(temp->data);
		// 		temp = temp->next;
		// 	}
		// 	push_back(temp->data);
		// }
	}
	List<T>& operator=(const List<T>& l) {
		// 	if (x.head == NULL)
		// 	{
		// 		head = NULL;
		// 		tail = NULL;
		// 		return *this;
		// 	}
		// 	else
		// 	{
		// 		head = NULL;
		// 		tail = NULL;
		// 		Node<T>*temp = x.head;
		// 		while (temp->next != NULL) {
		// 			push_back(temp->data);
		// 			temp = temp->next;
		// 		}
		// 		push_back(temp->data);
		// 		return *this;
		// 	}
		// }
		if (this == &l) return *this;
		else {
			if (head->next != NULL)
			{
				Node<T>* list = head->next;
				while (list != NULL)
				{
					Node<T>* tmpp = list;
					list = list->next;
					delete tmpp;
				}
			}
			this->tail = this->head;
			Node<T>* t = l.head;
			Node<T>* temp = this->head;
			while (t->next != NULL)
			{
				t = t->next;
				Node<T>* newnode = new Node<T>(t->data);
				temp->next = newnode;
				temp = newnode;
				tail = temp;
			}
		}
	}
};
class Point {
	int x, y;
public:
	Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
		cout << "\nPoint(x=0,y=0 ) is called(" << x << "," << y << ")!";
	}
	Point(const Point & p) {
		x = p.x;
		y = p.y;
		cout << "\nPoint(const Point & p) is called(" << x << "," << y << ")!";
	}
	~Point() {
		cout << "\n~Point is called(" << x << "," << y << ")!";
	}
	friend ostream &operator<<(ostream &output, const Point &P);
};
ostream &operator<<(ostream &out, const Point &p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}


//StudybarCommentBegin

void fun()
{
	List<Point> plist;
	cout << "\n after constructor";
	plist.push_back(Point(1, 1));
	plist.push_back(Point(2, 2));
	List<Point> plist2(plist);
	cout << "\n after copy constructor";
	cout << plist2[1];
	plist2.push_back(Point(3, 3));
	plist2.push_back(Point(5, 5));
	plist = plist2;
	cout << "\n after = overload";
	cout << plist[3];
}


int main() {
	fun();
	cout << "\nFigure out the output of this program!";
	return 0;
}
//StudybarCommentEnd