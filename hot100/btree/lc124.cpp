//
// Created by SP on 2023/11/29.
//

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

int ans = -0x3f3f3f3f;
//以root往下延申所能取得的最大路径和
int dfs(TreeNode* root){
    if (root== nullptr) return 0;
    int left = dfs(root->left);//可能为负值
    int right =dfs(root->right);
    //*****计算当前节点是路径最高点的最大路径
    int t =root->val;
    if (left>0) t+=left;
    if(right>0) t+=right;
    ans=max(ans, t);
    //*************end*******
    return max(root->val, root->val+max(left,right));
}

int maxPathSum(TreeNode* root) {
    dfs(root);
    return ans;
}