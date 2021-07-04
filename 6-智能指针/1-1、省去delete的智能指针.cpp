//StudybarCommentBegin
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
inline void SAFE_DELETE(T *  &p)   //&不能省略，否则 p=NULL无效。 但#define 那种宏替换可以，因为是字符替换。这也是inline 和#define的区别的重要案例
{   if (p != NULL )
    { delete p; p = NULL; }
}
//KRefCount是一个多线程安全的计数器对象，大家仅关注其外部接口（功能），不用关心内部实现。
class KRefCount
{
public:
    KRefCount(): m_nCount(0) {}

public:
    long AddRef() { return InterlockedIncrement(&m_nCount); } //给m_nCount加一，用InterlockedIncrement是多线程安全。
    long Release() { return InterlockedDecrement(&m_nCount); } //给m_nCount减一，用InterlockedIncrement是多线程安全。
    void Reset() { m_nCount = 0; }

private:
    volatile  long m_nCount;   //volatile 告诉编译器， m_nCount 这个变量不允许做寄存器优化。
};

template <typename T>
class SmartPtr
{
private:
    KRefCount* m_pReference;
    T* m_pData;
public:
    SmartPtr(T* pValue);
    ~SmartPtr(void);
};
//StudybarCommentEnd


template <typename T>
SmartPtr<T>::SmartPtr(T* pValue) {
    m_pReference = new KRefCount;
    m_pData = pValue;
    m_pReference->AddRef();
}

template <typename T>
SmartPtr<T>::~SmartPtr(void) {
    SAFE_DELETE( m_pData);
    SAFE_DELETE( m_pReference);
}


//StudybarCommentBegin
class CTest
{
public:
    CTest(int b) : a(b) {cout << "\n CTest(" << a << " ) is called";}
    ~CTest()  {cout << "\n ~CTest(" << a << ") is called";}
private:
    int a;
};

int main()
{
    SmartPtr<CTest> pSmartPtr1(new CTest(10));
    SmartPtr<CTest> pSmartPtr2 = new CTest(20);
    CTest *p = new CTest(30);
    return 0;
}
//StudybarCommentEnd