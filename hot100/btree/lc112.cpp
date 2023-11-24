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




bool hasPathSum(TreeNode* root, int sum){
    if (root==nullptr)
    {
        return false;
    }
    if (root->left==nullptr && root->right==nullptr)//叶子节点
    {
        return root->val==sum;
    }
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
    // if (root->left==nullptr && root->right==nullptr && root->val == sum)//叶子节点
    // {
    //     return true;
    // }


// if(cur->left){
//    if(traversal(cur->left, count-cur->left->val)) return true;
// }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    cout << hasPathSum(root, 6);
    return 0;
}