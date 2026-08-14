#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 


bool isSameTree(TreeNode* p, TreeNode* q) {
    
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;
    if(p->val != q->val) return false;

    bool r1 = isSameTree(p->left, q->left);
    bool r2 = isSameTree(p->right, q->right);

    return (r1 == true && r2 == true) ? true : false;
}

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool ans = isSameTree(p, q);
    cout << ans;
}