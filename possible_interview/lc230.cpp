// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，
// 请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

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

vector<int> nums;
void dfs(TreeNode* root){
    if (root==nullptr)
    {
        return;
    }
    dfs(root->left);
    nums.push_back(root->val);
    dfs(root->right);
}
int kthSmallest(TreeNode* root, int k) {
    dfs(root);
    return nums[k-1];
}