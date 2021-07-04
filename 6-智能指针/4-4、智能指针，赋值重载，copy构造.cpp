//StudybarCommentBegin
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
inline void SAFE_DELETE(T * & p) //&不能省略，否则 p=NULL无效。 但#define 那种宏替换可以，因为是字符替换。这也是inline 和#define的区别的重要案例
{	if (p != NULL )
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
	inline T& operator*();
	inline T* operator->();

	SmartPtr<T>& operator=(const SmartPtr<T>& sp);
	SmartPtr(const SmartPtr<T>& sp);
	SmartPtr<T>& operator=(T* pValue);
};
//StudybarCommentEnd





template <typename T>
SmartPtr<T>::SmartPtr(T* pValue) {
	m_pReference = new KRefCount;
	m_pReference->AddRef();
	m_pData = pValue;
}

template <typename T>
SmartPtr<T>::~SmartPtr(void) {
	if (m_pReference && m_pReference->Release() == 0)
	{
		SAFE_DELETE(m_pData);
		SAFE_DELETE(m_pReference);
	}
}

template <typename T>
inline T& SmartPtr<T>::operator*() {
	return *m_pData;
}
template <typename T>
inline T* SmartPtr<T>::operator->() {
	return m_pData;
}
template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& sp) {
	if (this != &sp)
	{
		if (m_pReference && m_pReference->Release() == 0)
		{
			SAFE_DELETE(m_pData);
			SAFE_DELETE(m_pReference);
		}

		m_pData = sp.m_pData;
		m_pReference = sp.m_pReference;
		m_pReference->AddRef();
	}
	return *this;
}
template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& sp) {
	m_pData = sp.m_pData;
	m_pReference = sp.m_pReference;
	m_pReference->AddRef();
}
template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(T* pValue) {
	if (m_pReference && m_pReference->Release() == 0)
	{
		SAFE_DELETE(m_pData);
		SAFE_DELETE(m_pReference);
	}

	m_pData = pValue;
	m_pReference = new KRefCount;
	m_pReference->AddRef();
	return *this;
}




//StudybarCommentBegin
class CTest
{
public:
	CTest(int b) : a(b) {cout << "\n CTest(" << a << " ) is called";}
	~CTest()  {cout << "\n ~CTest(" << a << ") is called";}
	void ShowAddOne() {cout << "\n++a= " << ++a;}
private:
	int a;
};

int main()
{	int x;
	cin >> x;
	SmartPtr<CTest> pSmartPtr1(new CTest(x));
	SmartPtr<CTest> pSmartPtr2 = new CTest(20);
	SmartPtr<CTest> pSmartPtr3(pSmartPtr1);
	CTest *p = new CTest(30);
	pSmartPtr1 = pSmartPtr2;  //pSmartPstr1 原所指对象，不被释放掉。因为pSmartPtr3 还指向 new CTest(x)，因此这时 CTest(x)仍然有效。
	pSmartPtr1->ShowAddOne();
	pSmartPtr3 = p;  //pSmartPtr3 原来所指的对象应该被释放掉，因为 CTest(x)的引用计数已经为0，如果不被释放将有内存泄漏
	(*pSmartPtr3).ShowAddOne();

}
//StudybarCommentEnd