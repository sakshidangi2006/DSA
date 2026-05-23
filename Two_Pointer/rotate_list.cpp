#include <iostream>
using namespace std;

struct ListNode {
    int val ;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* rotateRight(ListNode* head, int k) {

    if(head == nullptr || head->next == nullptr || k == 0)
        return head;

    int n = 1;
    ListNode* tail = head;

    while(tail->next != nullptr) {
        tail = tail->next;
        n++;
    }

    k = k % n;
    if(k == 0)
        return head;

    tail->next = head;
    int steps = n - k - 1;
    ListNode* newTail = head;

    while(steps--) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = rotateRight(head,2);
    cout <<ans->val;
    return 0;
}