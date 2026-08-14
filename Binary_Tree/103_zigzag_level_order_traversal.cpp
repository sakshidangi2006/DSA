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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    queue<TreeNode*> q;
    vector<vector<int>>ans;

    if(root == nullptr){
        return ans;
    }

    q.push(root);
    int leftToRight = 1;

    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> temp(levelSize);
        int first = 0;
        int last = temp.size()-1;

        while(levelSize--) {
            TreeNode* t = q.front();
            q.pop();
            
            if(leftToRight == 1){
                temp[first] = t->val;
                first++;
            }
            else{
                temp[last] = t->val;
                last--;
            }

            if(t->left != nullptr) q.push(t->left);
            if(t->right != nullptr) q.push(t->right);
        }
        ans.push_back(temp);
        leftToRight = 1 - leftToRight;
    }
    return ans;
    
}


int main() {
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(20);
    root -> right = new TreeNode(9);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    vector<vector<int>> ans = zigzagLevelOrder(root);
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