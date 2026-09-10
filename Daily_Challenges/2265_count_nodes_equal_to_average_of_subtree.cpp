#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = 0;

pair<int,int> countingNodes(TreeNode* root) {
    int count = 0;
    int sum = 0;
    int average = 0;

    if(root == nullptr) return {0,0};

    auto left = countingNodes(root->left);
    auto right = countingNodes(root->right);

    sum += left.first + right.first + root->val;
    count += left.second + right.second + 1;

    average = sum / count;

    if(average == root->val) ans++;
    return{sum,count};
}
    
int averageOfSubtree(TreeNode* root) {
    countingNodes(root);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int ans = averageOfSubtree(root);
    cout << ans;
    return 0;
}
