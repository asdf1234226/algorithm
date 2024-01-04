// 实现一个函数，检查一棵二叉树是否为二叉搜索树。

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

//中序遍历有序
long long maxVal = LONG_MIN;
bool isValidBST(TreeNode* root) {
    if (root==nullptr)
    {
        return true;
    }
    bool l = isValidBST(root->left);
    if (root->val>maxVal)//记录左子树最大值
    {
        maxVal=root->val;
    }else
    {
        return false;
    }
    bool r = isValidBST(root->right);
    return l && r;
    
    
    
}