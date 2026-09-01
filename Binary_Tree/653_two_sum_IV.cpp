#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int k;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : k(x), left(nullptr), right(nullptr) {}
};
 

stack<TreeNode*> ascending;
stack<TreeNode*> descending;

TreeNode* getSmall() {
    if (ascending.empty())
        return nullptr;

    TreeNode* small = ascending.top();
    ascending.pop();

    TreeNode* rightChild = small->right;

    while (rightChild) {
        ascending.push(rightChild);
        rightChild = rightChild->left;
    }

    return small;
}

TreeNode* getLarge() {
    if (descending.empty())
        return nullptr;

    TreeNode* large = descending.top();
    descending.pop();

    TreeNode* leftChild = large->left;

    while (leftChild) {
        descending.push(leftChild);
        leftChild = leftChild->right;
    }

    return large;
}



bool findTarget(TreeNode* root, int k) {
    if (root == nullptr)
        return false;

    TreeNode* node = root;

    while (node) {
        ascending.push(node);
        node = node->left;
    }

    node = root;

    while (node) {
        descending.push(node);
        node = node->right;
    }

    TreeNode* i = getSmall();
    TreeNode* j = getLarge();

    while (i && j && i != j && i->k < j->k) {
        int sum = i->k + j->k;

        if (sum == k)
            return true;

        if (sum < k)
            i = getSmall();
        else
            j = getLarge();
    }

    return false;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);


    int k = 9;
    bool ans = findTarget(root, k);
    cout << ans;
    return 0;
}