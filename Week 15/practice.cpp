#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <class T>
class LListNode {
    LListNode<T>* head;
    LListNode<T>* recursiveCopy(LListNode<T>* rhs);
public:
    LList() :head(nullptr) {}
    LList(const LList& rhs) :head(nullptr) { *this = rhs; }
    ~LList() { clear(); }
    void insertAtHead(T newdata);
    T removeFromHead();
    bool isEmpty()const { return head == nullptr; }
    void clear();
    void insertAtEnd(T newdata);

    void insertAtPoint(LListNode<T>* ptr, T newdata)
    int size() const;
};