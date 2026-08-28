#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;  
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    
    if (root == nullptr)
        return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            level.push_back(node->val);
            
            if (node->left)
                q.push(node->left);
            
            if (node->right)
                q.push(node->right);
        }
        
        ans.push_back(level);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(20);
    root -> right = new TreeNode(9);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    vector<vector<int>> ans = levelOrderBottom(root);
    cout<<"[";
    for(auto &a : ans) {
        cout<<"[";
        for(int b : a) {
            cout << b<<" ";
        }
        cout<<"] ";
    }
    cout<<"] ";
    return 0;
}