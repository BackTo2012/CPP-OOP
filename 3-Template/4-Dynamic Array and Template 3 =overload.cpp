#include <iostream>
using namespace std;

template <typename T>
class DynamicArray
{
private:
	T* array; //pointer  ，
	unsigned int mallocSize; //

public:
	DynamicArray(unsigned length, const T &content) {
		mallocSize = length;
		array = new T[mallocSize];
		for (unsigned int i = 0; i < mallocSize; i++)
			array[i] = content;
		cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize *sizeof(T) << " bytes memory in heap";
	}
	~DynamicArray() {
		delete []array;
		cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize *sizeof(T) << " bytes memory in heap";
	}
	unsigned int capacity() const {
		return mallocSize;
	}
	T& operator[](unsigned int i) {
		return array[i];
	}



	DynamicArray(const DynamicArray<T> & anotherDA ) {
		mallocSize = anotherDA.mallocSize;
		array = new T[mallocSize];
		for (unsigned int i = 0; i < mallocSize; i++)
			array[i] = anotherDA.array[i];
		cout << endl << "Copy Constructor is called";
	}
	DynamicArray<T> & operator= (const DynamicArray<T> & anotherDA )
	{
		cout << endl << "operator = is called";
		if (this == &anotherDA)
			return *this;
		else
		{
			mallocSize = anotherDA.mallocSize;
			array = new T[mallocSize];
			for (unsigned int i = 0; i < mallocSize; i++)
				array[i] = anotherDA.array[i];
			return *this;
		}
	}
};











































//StudybarCommentBegin
int main()
{
	int length, i;
	cin >> length;

	DynamicArray<int> iarray(length, -1);

	DynamicArray<int> iarray2(iarray), iarray3(iarray2);

	cout << endl;
	for (i = 0; i < length; i++) {
		cout << iarray3[i] << " ";
		iarray[i] = i * 1.1;
	}
	iarray3 = iarray2 = iarray;
	cout << endl;
	for (i = 0; i < length; i++) {
		cout << iarray3[i] << " ";
	}

	return 0;
}
//StudybarCommentEnd