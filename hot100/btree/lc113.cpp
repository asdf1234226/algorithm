//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

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

//TODO  和所有路径对比
vector<vector<int>> ans;
vector<int> path;

void dfs(TreeNode* root, int sum){
    if (root==nullptr)
    {
        return;
    }
    if (root->left==nullptr && root->right==nullptr)//到叶子节点
    {
        if (sum==0)
        {
            ans.push_back(path);
        }
        return;
    }
    if (root->left)
    {
        path.push_back(root->left->val);
        dfs(root->left, sum-root->val);
        path.pop_back();
    }
    if (root->right)
    {
        path.push_back(root->right->val);
        dfs(root->right, sum-root->val);
        path.pop_back();
    }
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum){
    if (root==nullptr)
    {
        return ans;
    }
    path.push_back(root->val);
    dfs(root, sum);
    return ans;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    cout << pathSum(root, 7).size();
    return 0;
}