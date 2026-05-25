#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* reverse(ListNode* head, int k) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(k--) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* temp = head;

    for(int i = 0; i < k; i++) {
        if(temp == NULL)
            return head;
        temp = temp->next;
    }

    ListNode* newHead = reverse(head, k);
    head->next = reverseKGroup(temp, k);
    return newHead;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(5);

    ListNode* ans = reverseKGroup(head,2);
    cout<<ans;
    return 0;
}