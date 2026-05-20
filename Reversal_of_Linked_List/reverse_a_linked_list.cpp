#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* reverseList(ListNode* head) {

   ListNode* curr = head;
   ListNode* prev = NULL;

   while(curr != NULL) {
       ListNode* nex = curr->next;

       curr->next = prev;
       prev = curr;
       curr = nex;
   }

   return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = reverseList(head);
    cout << ans;
    return 0;
}

