//
// Created by SP on 2023/11/12.
//

//给定一个二叉树 root ，返回其最大深度
//输入：root = [3,9,20,null,null,15,7]
//输出：3
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

//1. 后序求高度
//2. 层序遍历
int maxDepth(TreeNode* root) {//根节点的最大高度，后序求的是高度
    if (root== nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left,right)+1;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout << maxDepth(root);
    return 0;
}