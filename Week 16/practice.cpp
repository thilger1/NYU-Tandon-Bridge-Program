#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;


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