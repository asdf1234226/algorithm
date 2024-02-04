#include<iostream>
#include<vector>
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
//最近公共祖先
TreeNode* lowestCommonAncestor_err(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==nullptr)
    {
        return root;
    }
    
    if (root==p || root==q)
    {
        return root;
    }
    TreeNode* l = lowestCommonAncestor_err(root->left,p,q);
    TreeNode* r = lowestCommonAncestor_err(root->right,p,q);
    if (l==nullptr && r ==nullptr)
    {
        return root;
    }
    if (l)
    {
        return l;
    }
    if (r)
    {
        return r;
    }
    return nullptr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==nullptr)
    {
        return root;
    }
    
    if (root==p || root==q)//找到p或q就返回
    {
        return root;
    }
    TreeNode* l = lowestCommonAncestor(root->left,p,q);
    TreeNode* r = lowestCommonAncestor(root->right,p,q);
    if (l && r)
    {
        return root;
    }
    if (l)
    {
        return l;
    }
    if (r)
    {
        return r;
    }
    return nullptr;
}