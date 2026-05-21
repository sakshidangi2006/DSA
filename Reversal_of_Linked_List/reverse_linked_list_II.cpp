#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {

    if(!head || left == right) return head;

    ListNode* curr = head;
    ListNode* before = NULL;
    int pos = 1;

    while(pos < left) {
        before = curr;
        curr = curr->next;
        pos++;
    }

    ListNode* tail = curr; 
    ListNode* prev = NULL;

    while(pos <= right) {
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        pos++;
    }

    tail->next = curr;

    if(before != NULL) {
        before->next = prev;
        return head;
    }
    return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = reverseBetween(head,2,4);
    cout << ans;
    return 0;
}