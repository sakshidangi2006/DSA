#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* merge(ListNode* left, ListNode* right){

    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while(left && right){

        if(left->val < right->val){
            tail->next = left;
            left = left->next;
        }
        else{
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if(left)
        tail->next = left;

    if(right)
        tail->next = right;

    return dummy.next;
}

ListNode* sortList(ListNode* head) {

    if(head == NULL || head->next == NULL)
        return head;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = slow->next;
    slow->next = NULL;

    ListNode* left = sortList(head);
    ListNode* right = sortList(second);

    return merge(left, right);
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);

    head = sortList(head);

    printList(head);

    return 0;
}
