//
// Created by SP on 2023/11/12.
//
//给你一个二叉树的根节点 root ， 检查它是否轴对称
//输入：root = [1,2,2,3,4,4,3]
//输出：true



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


bool compare1(TreeNode* left, TreeNode* right){
    if (left== nullptr && right== nullptr) return true;
    else if (left== nullptr || right== nullptr) return false;
    else if (left->val != right->val) return false;
    //剩余left->val== right->val
    bool outside = compare1(left->left, right->right);
    bool inside = compare1(left->right, right->left);
    return outside&&inside;
}
//左右节点都空         true
//一空一不空 或 两个不同       false
//左右值相同时，还要看下一层的值是否对称，内外侧都要相同；外侧指左的左和右的右；内测指左的右和右的左
bool isSymmetric(TreeNode* root) {
    if (root== nullptr) return true;
    return compare1(root->left, root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    cout << isSymmetric(root);
    return 0;

}