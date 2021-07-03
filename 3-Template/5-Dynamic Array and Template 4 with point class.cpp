#include <iostream>
using namespace std;
template <typename T>
class DynamicArray
{
private:
	T* array; //pointer
	unsigned int mallocSize; //

public:
	DynamicArray(unsigned length = 1, const T& content = 0) {
		mallocSize = length;
		cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize *sizeof(T) << " bytes memory in heap";
		array = new T[mallocSize];
		for (unsigned int i = 0; i < mallocSize; i++)
			array[i] = content;
	}

	~DynamicArray() {
		cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize *sizeof(T) << " bytes memory in heap";
		delete []array;
	}

	DynamicArray(const DynamicArray<T> & anotherDA ) {
		cout << endl << "Copy Constructor is called";
		mallocSize = anotherDA.mallocSize;
		array = new T[mallocSize];
		for (unsigned int i = 0; i < mallocSize; i++)
			array[i] = anotherDA.array[i];
	}

	unsigned int capacity() const {
		return this->mallocSize;
	}

	T& operator[](unsigned  const int i) {
		return this->array[i];
	}

	DynamicArray<T>& operator= (const DynamicArray<T> & anotherDA )
	{
		cout << endl << "operator = is called";
		// if (this == &anotherDA)
		// 	return *this;
		// else
		// {
		delete []this->array;
		this->mallocSize = anotherDA.mallocSize;
		this->array = new T[anotherDA.mallocSize];
		for (unsigned int i = 0; i < this->mallocSize; i++)
			this->array[i] = anotherDA.array[i];
		return *this;
		// }
	}


};
class Point
{
	int x, y;
public:
	//constructor， cout<<"\nPoint is called!";
	Point(int m = 0, int n = 0) : x(m), y(n) {
		cout << "\nPoint is called!";
	}


	//deconstructor，    cout<<"\n~Point is called!";
	~Point() {
		cout << "\n~Point is called!";
	}
	//cout <<  overload        "("<<p.x<<","<<p.y<<")";
	friend ostream& operator<<(ostream& output, const Point& p)
	{
		output << "(" << p.x << "," << p.y << ")";
		return output;
	}
};


//StudybarCommentBegin
int main()
{
	int length, i;
	cin >> length;

	DynamicArray<Point> iarray(length, Point(3));

	DynamicArray<Point> iarray2(iarray), iarray3(iarray2);

	cout << endl;
	for (i = 0; i < length; i++) {
		cout << iarray3[i] << " ";
		iarray[i] = Point(i, i + 1);
	}
	iarray3 = iarray2 = iarray;
	cout << endl;
	for (i = 0; i < length; i++) {
		cout << iarray3[i] << " ";
	}

	return 0;
}
//StudybarCommentEnd