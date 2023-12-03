//
// Created by SP on 2023/11/12.
//

//二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
//输入：root = [1,2,3,4,5]
//输出：3
//解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。


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

////第一次尝试  左孩子的最大深度 + 右孩子的最大深度，就是直径
//存在的问题： 最大直径不一定经过根节点
////  正确解法，遍历所有节点，在求最大深度的基础上，计算每个节点的直径
int ans = 0;
int maxDepth(TreeNode* root){
    if (root== nullptr) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    ans= max(ans,l+r);////计算每个节点的直径
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);
    return ans;
}


int main(){
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout << diameterOfBinaryTree(root);
    return 0;
}