// 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
// 使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

//二叉搜索树中序是升序的，即 左 中 右 升序，那么右 中 左 降序

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

//创建一个新的树，try
int sum = 0;
TreeNode* dfs(TreeNode* root){
    if (root==nullptr)
    {
        return nullptr;
    }
    TreeNode* r = dfs(root->right);//右左中
    sum+=root->val;
    TreeNode* node = new TreeNode(sum);
    TreeNode* l = dfs(root->left);
    node->left=l;
    node->right=r;
    return node;
}

TreeNode* convertBST(TreeNode* root){
    if (root==nullptr)
    {
        return nullptr;
    }
    return dfs(root);
}

//原地
int sum = 0;
void dfs(TreeNode* root){
    if (root==nullptr)
    {
        return;
    }
    dfs(root->right);//右中左
    root->val = root->val+sum;
    sum = root->val;
    dfs(root->left);
}

TreeNode* convertBST(TreeNode* root){
    if (root==nullptr)
    {
        return nullptr;
    }
    return dfs(root);
}