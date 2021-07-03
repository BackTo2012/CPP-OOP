//StudybarCommentBegin
#include <iostream>
using namespace std;

typedef struct tagNode
{
    int value;
    tagNode *pNext;
} Node;

class JTList
{
public:
    JTList() : m_pHead(NULL), m_pTail(NULL) {};
    ~JTList();
    Node *First() const;
    Node *Last() const;
    void Append(const int &);
private:
    Node *m_pHead;
    Node *m_pTail;
    long m_lCount;
};

JTList::~JTList()
{
    Node *pCurrent = m_pHead;
    Node *pNextNode = NULL;
    while (pCurrent)
    {
        pNextNode = pCurrent->pNext;
        delete pCurrent;
        pCurrent = pNextNode;
    }
}

void JTList::Append(const int &value)
{   // Create the new node
    Node *pInsertNode = new Node;
    pInsertNode->value = value;
    pInsertNode->pNext = NULL;
    // This list is empty
    if (m_pHead == NULL)
    {   m_pHead = m_pTail = pInsertNode;
    }
    else
    {   m_pTail->pNext = pInsertNode;
        m_pTail = pInsertNode;
    }
    ++m_lCount;
}
//StudybarCommentEnd

Node* JTList::First() const
{
    return this->m_pHead;
}
Node* JTList::Last() const
{
    return this->m_pTail;
}
class Iterator
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Node* CurrentItem() const = 0;
};

class JTListIterator : public Iterator
{
public:
    JTListIterator(JTList* pList) : m_pJTList(pList), m_pCurrent(NULL) {}
    void First()
    {
        m_pCurrent = m_pJTList->First();
    }
    void Next()
    {
        m_pCurrent = m_pCurrent->pNext;
    }
    bool IsDone() const
    {
        if (m_pCurrent == NULL)
        {
            return 1;
        }
        return 0;
    }
    Node* CurrentItem() const
    {
        return m_pCurrent;
    }
private:
    JTList* m_pJTList;
    Node* m_pCurrent;
};
class ArrayIterator : public Iterator
{
public:
    ArrayIterator(Node* pList, int n) : m_pJTList(pList), m_pCurrent(NULL), sum(n) {}
    void First()
    {
        index = 0;
        m_pCurrent = &m_pJTList[index];
    }
    void Next()
    {
        index++;
        m_pCurrent = &m_pJTList[index];
    }
    bool IsDone() const
    {
        if (index >= sum)
        {
            return 1;
        }
        return 0;
    }
    Node* CurrentItem() const
    {
        return m_pCurrent;
    }

private:
    Node* m_pJTList;
    Node* m_pCurrent;
    int index;
    int sum;
};


//StudybarCommentBegin
int findValue(Iterator *pIterator, int value)
{   int i = 0;
    for (pIterator->First(); !pIterator->IsDone(); pIterator->Next())
    {   if (pIterator->CurrentItem()->value == value) {return i;}
        i++;
    }
    return -1;
}

int main()
{   //This is a List
    JTList *pJTList = new JTList;
    int i;
    for (i = 0; i < 20; i++)
    {   pJTList->Append(i * 10);
    }
    //This is an Array
    Node temp[10] = {{0, NULL}, {9, NULL}, {8, NULL}, {7, NULL}, {6, NULL}, {5, NULL}, {4, NULL}, {3, NULL}, {2, NULL}, {1, NULL}};

    Iterator *pListIterator = new JTListIterator(pJTList);
    Iterator *pArrayIterator = new ArrayIterator(temp, 10);
    int x, y;
    cin >> x >> y;
    cout << "\nIn the list, findValue give the index: " << findValue(pListIterator, x);
    cout << "\nIn the Array, findValue give the index: " << findValue(pArrayIterator, y);

    delete pListIterator;
    delete pJTList;
    delete pArrayIterator;

    return 0;
}

//StudybarCommentEnd
