#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

template <class T>
class LListNode{
    T data;
    LListNode<T>* next;
public:
    LListNode(T newdata = T(), LListNode<T>* newNext = nullptr) :
        data(newdata), next(newNext) {}
    friend class LList <T>;
};


ListNode* reverse_linked_list(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;

    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}