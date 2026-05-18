#include <iostream>
#include <stack>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){};
};

ListNode* removeNodes(ListNode* head) {

    stack<ListNode*>st;
    ListNode* temp = head;

    while(temp != NULL) {
        st.push(temp);
        temp = temp->next;
    }

    ListNode* ans = NULL;
    int maxi = INT_MIN;

    while(!st.empty()) {

        ListNode* node = st.top();
        if(node->val >= maxi) {
            maxi = node->val;
            node->next = ans;
            ans = node;
        } 

        st.pop();
    }

    return ans;
}

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    ListNode* ans = removeNodes(head);
    while(ans != NULL) {
    cout << ans->val<<" ";
    ans = ans->next;
    }
    return 0;
   
}
    
