#include <iostream>
using namespace std;
template <typename T>














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