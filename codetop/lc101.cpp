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

bool help(TreeNode* l1, TreeNode* l2){
    if (l1==nullptr && l2==nullptr)
    {
        return true;
    }
    if (l1 && l2==nullptr)
    {
        return false;
    }
    if (l1==nullptr&&l2)
    {
        return false;
    }
    if (l1->val!=l2->val)
    {
        return false;
    }
    return help(l1->left, l2->right) && help(l1->right,l2->left);
}

bool isSymmetric(TreeNode* root){
    if (root==nullptr)
    {
        return true;
    }
    return help(root->left, root->right);
    
}