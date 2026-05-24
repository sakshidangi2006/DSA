#include <iostream>
using namespace std;

struct ListNode  {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* swapPairs(ListNode* head) {

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    while(prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }

    return dummy.next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    ListNode* ans = swapPairs(head);
    cout << ans;
    return 0;
}
