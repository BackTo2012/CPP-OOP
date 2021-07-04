#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
	T data;
	Node* next;
};
template <class T>
class List

{
	Node<T> *head, *tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	void push_back(const T& x) {
		Node<T> *newhead = new Node<T>;
		newhead->data = x;
		newhead->next = NULL;
		if (head == NULL)
		{
			head = newhead;
			tail = newhead;
		}
		else
		{
			tail->next = newhead;
			tail = newhead;
		}
	}
	T& operator[](int i) {
		int Index = 0;
		Node<T> *temp = head;
		while (temp->next != NULL)
		{
			if (Index == i)
				return temp->data;
			Index++;
			temp = temp->next;
		}
		return temp->data;
	}
	List(const List<T>& z) {
		head = z.head;
		tail = z.tail;
	}
	List<T>& operator=(const List<T>& x) {
		if (x.head == NULL)
		{
			head = NULL;
			tail = NULL;
			return *this;
		}
		else
		{
			head = NULL;
			tail = NULL;
			Node<T>*temp = x.head;
			while (temp->next != NULL) {
				push_back(temp->data);
				temp = temp->next;
			}
			push_back(temp->data);
			return *this;
		}
	}
};












//StudybarCommentBegin

int main() {
	int n;
	cin >> n;
	List<int> list;
	int i;
	for (i = 0; i < n; i++) {
		list.push_back(i);
	}
	List<int> list2(list);
	list2.push_back(123456);
	cin >> n;
	cout << list2[n - 2] << " " << list2[n];
	list = list2;
	list2[0] = n * 97;
	list[0] = n * 79;
	cout << " " << list[0] << " " << list2[0] << " " << list[n];
}
//StudybarCommentEnd