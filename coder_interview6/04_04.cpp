// 实现一个函数，检查二叉树是否平衡。在这个问题中，
// 平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left= nullptr;
        right= nullptr;
    }
};

int max_depth(TreeNode* root){
    if (root==nullptr)
    {
        return 0;
    }
    return max(max_depth(root->left), max_depth(root->right))+1;
}
bool isBalanced(TreeNode* root) {
    if (root==nullptr)
    {
        return true;
    }
    if (abs(max_depth(root->left)-max_depth(root->right))>1)
    {
        return false;
    }
    return isBalanced(root->left)&&isBalanced(root->right);
}