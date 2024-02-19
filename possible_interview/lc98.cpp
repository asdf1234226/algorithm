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
//用long是为了判断特例
long max_v = LONG_MIN;//左子树最大值
bool isValidBST(TreeNode* root){
    if (root==nullptr)
    {
        return true;
    }
    bool l = isValidBST(root->left);
    if (max_v<root->val)
    {
        max_v=root->val;
    }else
    {
        return false;
    }
    bool r = isValidBST(root->right);
    return l && r;
}