#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }
    return false;
}

void printListSafe(ListNode* head, int limit = 10) {
    int count = 0;
    while (head && count < limit) {
        cout << head->val << " -> ";
        head = head->next;
        count++;
    }
    cout << (head ? "..." : "NULL") << endl;
}


int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
   
    bool cycle = hasCycle(head);
    cout << (cycle ? "Cycle detected" : "No cycle") << endl;
    
    if(!cycle) printListSafe(head,5);
    return 0;


}