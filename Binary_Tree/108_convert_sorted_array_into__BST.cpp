#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* build(vector<int>& nums, int left, int right) {

    if(left > right) return nullptr;

    int mid = left + (right - left)/2;

    TreeNode* root = new TreeNode(nums[mid]);

    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);

    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size()-1);
}

void print(TreeNode* root) {
    if(root == nullptr) return;

    print(root->left);
    cout << root->val <<"->";
    print(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    print(root);
    cout <<"NULL";
    return 0;
}
