#include <iostream>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next; 
    ListNode(int x) : val(x), next(nullptr) {}
};
 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (!list1) return list2;
    if (!list2) return list1;

    ListNode dummy(0);
    ListNode* temp = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1 != NULL)
        temp->next = list1;
    else
        temp->next = list2;

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);


    ListNode* ans = mergeTwoLists(list1, list2);

    printList(ans);

    return 0;
}
