#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};


int maxDepth(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    int leftSize = minDepth(root->left);
    int rightSize = minDepth(root->right);
    if (root->left && root->right)
    {
        return 1+min(leftSize, rightSize);
    }
    if (root->left && !root->right)
    {
        return 1+leftSize;
    }
    if (root->right && !root->left)
    {
        return 1+rightSize;
    }
    return 1;
}