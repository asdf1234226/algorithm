// 给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。
// 你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。



#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left=nullptr;
        right=nullptr;
    }
};

TreeNode* trimBST(TreeNode* root, int low, int high){
    
}