#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};


ListNode* partition(ListNode* head, int x) {

    ListNode beforeDummy(0);
    ListNode afterDummy(0);

    ListNode* before = &beforeDummy;
    ListNode* after = &afterDummy;

    while (head != NULL) {

        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }

        head = head->next;
    }

    after->next = NULL;
    before->next = afterDummy.next;

    return beforeDummy.next;
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
    head->next->next->next->next->next = new ListNode(2);

    head = partition(head,3);

    printList(head);

    return 0;
}
