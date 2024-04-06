// 路径和 是路径中各节点值的总和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

#include<iostream>
#include<vector>
using namespace std;

//TODO 不熟
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

//以root向下延伸能取得的最大值，最大高度的变形
//为什么不能定义为root为根节点的最大路径，dfs(root->left)和dfs(root->right)会有重叠
int dfs(TreeNode* root){
    if (root==nullptr)
    {
        return 0;
    }
    int l = dfs(root->left);
    int r = dfs(root->right);
    //****计算当前节点为根节点的最大路径
    int res = root->val;
    if (l>=0)
    {
        res+=l;
    }
    if (r>=0)
    {
        res+=r;
    }
    ans=max(ans,res);
    //*********
    return max(root->val, max(l,r)+root->val);
}
int maxPathSum(TreeNode* root) {
    dfs(root);
    return ans;
}