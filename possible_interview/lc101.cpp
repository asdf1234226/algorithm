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

bool help(TreeNode* left, TreeNode* right){
    if (left==nullptr && right==nullptr)
    {
        return true;
    }else if ((left==nullptr&&right) || (right==nullptr&&left))
    {
        return false;
    }else
    {
        if (left->val != right->val)
        {
            return false;
        }
        return help(left->left,right->right) && help(left->right, right->left);
    }
    
}

//TODO 要熟悉一下
bool isSymmetric(TreeNode* root) {
    if (root==nullptr)
    {
        return true;
    }
    return help(root->left, root->right);
    
    
}