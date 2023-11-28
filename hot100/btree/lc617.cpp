//合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left=nullptr;
        right=nullptr;
    }
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1==nullptr && t2==nullptr)
    {
        return nullptr;
    }
    else if (t1==nullptr && t2!=nullptr)
    {
        return t2;
    }
    else if (t1!=nullptr && t2==nullptr)
    {
        return t1;
    }
    else
    {
        TreeNode* root = new TreeNode(t1->val+t2->val);
        root->left=mergeTrees(t1->left,t2->left);
        root->right=mergeTrees(t1->right, t2->right);
        return root;
    }
}