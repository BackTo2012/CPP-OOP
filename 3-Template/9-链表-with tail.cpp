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
	cin >> n;
	cout << list[n - 2] << " " << list[n];
}

//StudybarCommentEnd