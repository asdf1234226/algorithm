#include<iostream>
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

int res = 0;
//最大深度的变形题，求最大深度的同时更新直径
int maxDepth(TreeNode* root){
    if (root==nullptr)
    {
        return 0;
    }
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    res = max(res, l+r);
    return 1 + max(l, r);
}


// 做一次遍历，每个节点计算一下左子树的最大深度，右子树最大深度， +1  ---->点数，直径要-1
int diameterOfBinaryTree(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    maxDepth(root);
    return res;
}