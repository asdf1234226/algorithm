//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

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

vector<int> ans;
void dfs(TreeNode* root){
    if (root==nullptr)
    {
        return;
    }
    dfs(root->left);
    ans.push_back(root->val);
    dfs(root->right);
}

int getMinimumDifference(TreeNode* root){
    dfs(root);
    int res = 0x3f3f3f3f;
    for (int i = 0; i < ans.size()-1; i++)
    {
        res = min(ans[i+1]-ans[i], res);
    }
    return res;
}
