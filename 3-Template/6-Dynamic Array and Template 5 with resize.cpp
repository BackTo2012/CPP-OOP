#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0)
	{		x = a, y = b;		cout << "\nPoint is called!";	}
	~Point() {		cout << "\n~Point is called!";	}
	friend ostream& operator<<(ostream& output, const Point& p)
	{
		output << "(" << p.x << "," << p.y << ")";
		return output;
	}

};


template <typename T>
class DynamicArray {
private:
	T* array; //pointer
	unsigned int mallocSize; //
public:
	DynamicArray(unsigned length, const T& content)
	{	mallocSize = length;
		cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
		array = new T[mallocSize];
		for (int i = 0; i < mallocSize; i++)
			array[i] = content;
	}
	DynamicArray(const DynamicArray<T> & anotherDA ) {
		this->mallocSize = anotherDA.mallocSize;
		array = new T[anotherDA.mallocSize];
		for (int i = 0; i < anotherDA.mallocSize; i++)
			this->array[i] = anotherDA.array[i];
		cout << endl << "Copy Constructor is called";
	};
	~DynamicArray()
	{	cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
		delete[] array;
	}
	unsigned int capacity() const
	{	return this->mallocSize;
	}
	T& operator[](unsigned const int& i)
	{	return this->array[i];
	};
	DynamicArray<T> & operator= (const DynamicArray<T> & another )
	{	cout << endl << "operator = is called";
		delete[] this->array;
		this->mallocSize = another.mallocSize;
		this->array = new T[this->mallocSize];
		for (size_t i = 0; i < this->mallocSize; ++i)
			this->array[i] = another.array[i];
		return *this;
	};
	// int resize(unsigned int newSize, const T& ValOfNewItems) {
	// 	Point temp = array[0];
	// 	cout << "\nresize is called";
	// 	if ( newSize >  mallocSize) {
	// 		array = new T [newSize];
	// 		array[0] = Point(3);
	// 		for (int i = 1; i < newSize; ++i)
	// 			array[i] = ValOfNewItems;
	// 		return 1;
	// 	}
	// 	else if ( newSize == mallocSize ) {
	// 		return 0;
	// 	}
	// 	else if ( newSize < mallocSize  )
	// 	{
	// 		T* a ;
	// 		int i;
	// 		a = new T[newSize]();
	// 		for (i = 0; i < newSize; i++)
	// 		{
	// 			a[i] = array[i];
	// 		}
	// 		delete []array;
	// 		mallocSize = newSize;
	// 		array = a;
	// 		return -1;
	// 	}

	int resize(unsigned int newSize, const T& ValOfNewItems)
	{
		cout << "\nresize is called";
		if (newSize >  mallocSize)
		{
			T* a ;
			int i;
			a = new T[newSize];
			for (i = 0; i < mallocSize; i++)
				a[i] = array[i];
			for (i = mallocSize; i < newSize; i++)
				a[i] = ValOfNewItems;
			delete []array;
			mallocSize = newSize;
			array = a;
			return 1;
		}
		if (newSize ==  mallocSize)
			return 0;
		if (newSize <  mallocSize)
		{

			T* a ;
			int i;
			a = new T[newSize];
			for (i = 0; i < newSize; i++)
				a[i] = array[i];
			delete []array;
			mallocSize = newSize;
			array = a;
			return -1;
		}
	}
};
//StudybarCommentBegin
int main()
{
	int length, i;
	cin >> length;

	DynamicArray<Point> iarray(length, Point(3));

	cin >> length;

	cout << endl << iarray.resize(length, Point(1, 2));

	cout << endl;
	for (i = 0; i < length; i++) {
		cout << iarray[i] << " ";
	}

	return 0;
}
//StudybarCommentEnd