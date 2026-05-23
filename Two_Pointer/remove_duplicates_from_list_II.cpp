#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    
    while(curr != NULL) {

        if(curr->next != NULL && curr->val == curr->next->val) {
            int duplicate = curr->val;

            while(curr != NULL && curr->val == duplicate) {
                curr = curr->next;
            }

            prev->next = curr;
            
        }

        else {

            prev = prev->next;
            curr = curr->next;
        }
    }
    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);

    ListNode* ans = deleteDuplicates(head);
    cout << ans->val;
    return 0;

}