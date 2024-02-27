// 路径和 是路径中各节点值的总和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

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

int ans = -0x3f3f3f3f;
//以root为根节点往下延伸能取得的最大值
int dfs(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    int left = dfs(root->left);
    int right = dfs(root->right);
    //**********计算当前节点是路径最高点的最大路径
    int t = root->val;
    if (left>0)
    {
        t+=left;
    }
    if(right>0){
        t+=right;
    }
    ans=max(ans,t);
    //************
    return max(root->val, max(left, right)+root->val);
}
int maxPathSum(TreeNode* root) {
    dfs(root);
    return ans;
}
