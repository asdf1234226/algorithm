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
//    1              1
//  2   3          3    2
// 4 5 6 7       7  6  5  4
TreeNode* invertTree(TreeNode* root) {
    if (root==nullptr)
    {
        return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
}