#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
	T data;
	Node* next;
};


template <typename T>
class MyList
{
	Node<T>* head;
public:
	MyList() {
		head = NULL;
	}
	~MyList() {
	};
	void Push_back(const T&x) {
		Node<T> *newhead = new Node<T>;
		newhead->data = x;
		newhead->next = NULL;
		if (head == NULL)5
			head = newhead;
		else
		{	Node<T>* temp = head;
			while (temp->next != NULL)
			{	temp = temp->next;
			}
			temp->next = newhead;
		}
	};
	void Show() {
		Node<T>* temp = head;
		// printf("List is: ");
		while (temp != NULL) {
			printf(" %d", temp->data);
			temp = temp->next;
		}
		printf("\n");
	};
	void Delete(const T&x) {
		Node<T> *temp, *temp1;
		if (x == 0)
		{
			head = head->next;
			// cout << "finished";
		}
		else
		{
			int Index = 1;
			temp = head;
			while (Index != x )
			{
				Index++;
				temp = temp->next;
			}
			temp1 = temp->next;

			temp->next = temp1->next;
			// printf("finished ");
		}


	};
	T& operator[](int i) {
		int Index;
		Node<T> *temp = head;
		while (temp != NULL)
		{	if (Index == i)
				return temp->data;
			temp = temp->next;
			Index++;
		}
		return temp->data;
	};
};

int main(int argc, char const *argv[])
{
	int number, shurushuzi;
	cin >> number;
	MyList<int> Name;
	for (int i = 0; i < number; ++i)
	{
		cin >> shurushuzi;
		Name.Push_back(shurushuzi);
	}
	// Name.Show();
	int deletenumbers, shanchudesuoyinzhi;
	cin >> deletenumbers;
	for (int i = 0; i < deletenumbers; ++i)
	{
		cin >> shanchudesuoyinzhi;
		Name.Delete(shanchudesuoyinzhi);
		Name.Show();
	}
	return 0;
}





