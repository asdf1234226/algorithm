#include<iostream>
#include<vector>
using namespace std;

//TODO  不熟悉

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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==nullptr)
    {
        return root;
    }
    if (root==p || root==q)
    {
        return root;
    }
    TreeNode* l = lowestCommonAncestor(root->left,p,q);
    TreeNode* r = lowestCommonAncestor(root->right,p,q);
    if (l && r)
    {
        return root;
    }else if (l && r==nullptr)
    {
        return l;
    }else if (r && l==nullptr)
    {
        return r;
    }else
    {
        return nullptr;
    }
}