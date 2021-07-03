#include <iostream>
using namespace std;

//DynamicVector类：


template <class T>
class DynamicVector
{
private:
    T* array;  //指向分配空间的指针
    unsigned mallocSize;  //分配空间的大小
    unsigned numofItems;  //向量内已经存储的元素数量
    int virtualZero;  //数组起始下标，C++中通常数组下标是从0开始，这个数据属性可以让数组的下标从任意整数开始 ,让数组更加灵活
public:
    DynamicVector(int Vindex)  //构造函数
    {
        array = NULL;
        numofItems = 0;
        mallocSize = 0;
        virtualZero = Vindex;
    }
    DynamicVector(const DynamicVector<T> &anotherDA)  //拷贝构造函数
    {
        int i;
        array = new T[anotherDA.mallocSize];
        mallocSize = anotherDA.mallocSize;
        virtualZero = anotherDA.virtualZero;
        numofItems = anotherDA.numofItems;
        for (i = 0; i < mallocSize; i++)
        {
            array[i] = anotherDA.array[i];
        }
    }
    ~DynamicVector()   //析构函数
    {
        delete [] array;
    }
    inline void push_back(const T& newItem)  //push_back函数
    {
        if (numofItems < mallocSize)
        {
            array[numofItems] = newItem;
            numofItems++;
        }
        else if (numofItems == mallocSize)
        {
            int i;
            T* arrays = array;
            array = new T[2 * mallocSize + 1];
            mallocSize = 2 * mallocSize + 1;
            for (i = 0; i < numofItems; i++)
            {
                array[i] = arrays[i];
            }
            array[numofItems] = newItem;
            numofItems++;
            delete [] arrays;
        }
    }
    void push_back(const DynamicVector &t)  //push_back函数的重载
    {
        if (numofItems + t.numofItems <= mallocSize)
        {
            int i;
            for (i = numofItems; i < numofItems + t.numofItems; i++)
            {
                array[i] = t.array[i - numofItems];
            }
            numofItems = numofItems + t.numofItems;
        }
        else if (numofItems + t.numofItems > mallocSize)
        {
            int i;
            T* arrays;
            arrays = array;
            array = new T[2 * mallocSize + 1];
            mallocSize = 2 * mallocSize + 1;
            for (i = 0; i < numofItems; i++)
            {
                array[i] = arrays[i];
            }
            for (i = numofItems; i < numofItems + t.numofItems; i++)
            {
                array[i] = t.array[i - numofItems];
            }
            numofItems = numofItems + t.numofItems;
            delete [] arrays;
        }
    }
    DynamicVector<T> &operator = ( const DynamicVector<T> &anotherDA)  //深层赋值=重载
    {
        if ( this == & anotherDA)
        {
            return *this;
        }
        delete [] array;
        array = new T[anotherDA.mallocSize];
        mallocSize = anotherDA.mallocSize;
        virtualZero = anotherDA.virtualZero;
        numofItems = anotherDA.numofItems;
        int i;
        for (i = 0; i < anotherDA.mallocSize; i++)
        {
            array[i] = anotherDA.array[i];
        }
        return *this;
    }
    T& operator [] (int Vindex)  //[]重载
    {
        int _entry = Vindex - virtualZero;
        if (_entry < 0 || _entry >= numofItems)
        {
            cout << endl << "Out Of Range";
            exit(1);
        }
        return array[_entry];
    }
    bool operator == (const DynamicVector<T>& dv) const  //bool型==重载
    {
        int i;
        int flag = 1;
        for (i = 0; i < numofItems; i++)
        {
            if (array[i] != dv.array[i])
            {
                flag = 0;
            }
        }
        if (flag == 1 && numofItems == dv.numofItems)
            return true;
        else return false;
    }
    unsigned length() const  //返回向量内已经存储的元素数量
    {
        return numofItems;
    }
    unsigned capacity() const  //返回分配空间的大小
    {
        return this->mallocSize;
    }
    int firstIndex() const  //返回数组起始下标
    {
        return this->virtualZero;
    }
    friend ostream& operator << (ostream& out, DynamicVector<T> &t) //输出重载
    {
        if (t.numofItems == 0)
        {
            cout << "The arrray is empty." << endl;
        }
        else
        {
            int i;
            for (i = 0; i < t.numofItems; i++)
            {
                cout << t.array[i] << " ";
            }
        }
        return out;
    }
    void insert (int Vindex, const T &z)  //插入一个元素 z
    {
        Vindex = Vindex - virtualZero;
        mallocSize = mallocSize + 1;
        int i;
        for (i = numofItems; i != Vindex; i--)
        {
            array[i] = array[i - 1];
        }
        array[Vindex] = z;
        numofItems = numofItems + 1;
    }
    void remove()  //删除最后一个元素——(1)
    {
        T* arrays;
        arrays = array;
        array = new T[mallocSize];
        int i;
        for (i = 0; i < numofItems - 1; i++)
        {
            array[i] = arrays[i];
        }
        numofItems--;
    }
    void remove(int Vindex) //删除下标为Vindex的元素,要记得减初始下标 ——(2)
    {
        int i;
        T* arrays = array;
        array = new T[mallocSize];
        for (i = 0; i < Vindex - virtualZero; i++)
        {
            array[i] = arrays[i];
        }
        for (i = Vindex - virtualZero; i < numofItems - 1; i++)
        {
            array[i] = arrays[i + 1];
        }
        numofItems = numofItems - 1;
        delete [] arrays;
    }
    void remove(int Vfirst, int Vlast)   //删除[Vindex,Vlast)号元素。注意是左闭右开集合，即不删除Vlast元素——(3)
    {
        int i;
        int t = 0;
        T* array1 = array;
        array = new T[mallocSize];
        for (i = 0; i < Vfirst - virtualZero; i++)
        {
            array[t] = array1[i];
            t++;
        }
        for (i = Vlast - virtualZero; i < numofItems; i++)
        {
            array[t] = array1[i];
            t++;
        }
        numofItems = numofItems - Vlast + Vfirst;
        mallocSize = mallocSize - sizeof(T) * (Vlast - Vfirst);
        delete [] array1;
    }
    DynamicVector<T> operator() (int Vfirst, int Vlast) const //()重载
    {
        int v1, v2, i;
        v1 = Vfirst + 2;
        v2 = Vlast + 2;
        DynamicVector t(-2);
        t.numofItems = v2 - v1;
        t.mallocSize = 2 * t.numofItems + 1;
        t.array = new T[mallocSize];
        for (i = 0; i < t.numofItems; i++)
        {
            t.array[i] = array[v1];
            v1++;
        }
        return t;
    }
    void swap(DynamicVector<T> &dv)  //交换两个对象的内容的函数
    {
        int i, n, m;
        T* array1 = new T[dv.numofItems];
        for (i = 0; i < dv.numofItems; i++)
        {
            array1[i] = dv.array[i];
        }
        n = dv.numofItems;
        m = dv.mallocSize;
        delete [] dv.array;
        dv.array = new T[mallocSize];
        for (i = 0; i < numofItems; i++)
        {
            dv.array[i] = array[i];
        }
        dv.numofItems = numofItems;
        dv.mallocSize = mallocSize;
        delete [] array;
        array = new T[m];
        numofItems = n;
        array = array1;
    }
    T* begin() const
    {
        return &array[0];
    }
    T* end() const
    {
        return &array[numofItems];
    }
    DynamicVector(T* const first, T* const last, int Vindex = 0)
    {
        int i;
        numofItems = last - first;
        virtualZero = Vindex;
        mallocSize = 2 * numofItems + 1;
        array = new T[mallocSize];
        array[0] = 1.1;
        for (i = 1; i < numofItems; i++)
            array[i] = array[i - 1] + 1;
    }
};










//StudybarCommentBegin
int main()
{

    DynamicVector<int> ra(-2);


    int i, n;
    cin >> n;

    cout << ra;

    ra.push_back(-3);
    ra.push_back(-2);
    ra.push_back(-1);
    for ( i = 0; i < n; i++)
    {
        ra.push_back(i);
    }
    cout << "\n malloSize is " << ra.capacity();
    cout << "\n numofItems is " << ra.length();
    cout << "\n StartIndex is " << ra.firstIndex() << endl;
    for ( i = -2; i < n + 1; i++)
    {
        cout << ra[i] << " ";
    }
    cout << endl;
    DynamicVector<int> raCopy(ra);
    cout << "\n malloSize is " << raCopy.capacity();
    cout << "\n numofItems is " << raCopy.length();
    cout << "\n StartIndex is " << raCopy.firstIndex() << endl;
    cout << endl;
    for ( i = -2; i < n + 1; i++)
    {   cout << ++ra[i] << " ";
    }
    cout << endl;
    for ( i = -2; i < n + 1; i++)
    {   cout << raCopy[i] << " ";
    }

    raCopy = ra;
    if (ra == raCopy)  cout << "\n ra == raCopy";
    else cout << "\n ra != raCopy";


    ra[-2] = 100;

    if (ra == raCopy)  cout << "\n ra == raCopy";
    else cout << "\n ra != raCopy";

    raCopy.push_back(ra);
    cout << endl;
    int firstI = raCopy.firstIndex();
    for ( i = 0; i < raCopy.length() ; i++)
    {   cout << raCopy[i + firstI ] << " ";
    }
    cout << endl;
    raCopy.insert(-2, 6);
    raCopy.insert(-1, 7);
    cout << raCopy;

    raCopy.remove();
    cout << endl;
    cout << raCopy << " remove()";


    raCopy.remove(-1);
    cout << endl;
    cout << raCopy << " remove(-1)";

    raCopy.remove(-1, 1);
    cout << endl;
    cout << raCopy << " remove(-1,1)";

    return 0;
}
//StudybarCommentEnd