//
// Created by SP on 2023/11/12.
//

// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
// 输入：root = [4,2,7,1,3,6,9]
// 输出：[4,7,2,9,6,3,1]

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

TreeNode* invertTree(TreeNode* root) {
    //1.前序写法
    if (root==nullptr)
    {
        return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;

    //2.中序写法
    if (root==nullptr)
    {
        return root;
    }
    invertTree(root->left);
    swap(root->left, root->right);
    invertTree(root->left);//原来的右子树已经被翻转到左边
    return root;

    //3.后序写法
    if (root==nullptr)
    {
        return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;

    //4. 前序迭代写法
    stack<TreeNode*> st;
    if (root==nullptr)
    {
        return root;
    }
    st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        swap(node->left, node->right);//节点处理逻辑
        if (node->left)
        {
            st.push(node->left);
        }
        if (node->right)
        {
            st.push(node->right);
        }
    }
    return root;
}


int main(){
    TreeNode* root = new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);

}