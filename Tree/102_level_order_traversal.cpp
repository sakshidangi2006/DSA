#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    
    if (root == nullptr) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> temp;

        while (levelSize--) {
            TreeNode* t = q.front();
            q.pop();

            temp.push_back(t->val);

            if (t->left != nullptr) {
                q.push(t->left);
            }

            if (t->right != nullptr) {
                q.push(t->right);
            }
        }

        ans.push_back(temp);
    }

    return ans;
}


int main() {
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(20);
    root -> right = new TreeNode(9);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    vector<vector<int>> ans = levelOrder(root);
    for(auto &a : ans) {
        for(int b : a) {
            cout << b<<" ";
        }
    }
    return 0;
}