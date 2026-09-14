#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    bool nullFound = false;

    if(root == nullptr) return true;

    q.push(root);

    while(!q.empty()) {
        TreeNode* t = q.front();
        q.pop();

        if(t == nullptr) {
            nullFound = true;

        }
        else {

            if(nullFound == true) return false;
            q.push(t->left);
            q.push(t->right);
        }
    }
    return true;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    
    bool ans = isCompleteTree(root);
    cout << ans;
    return 0;
}
