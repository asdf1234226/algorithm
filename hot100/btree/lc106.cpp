//给定两个整数数组 postorder 和 inorder ，其中 postorder 是二叉树的后序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。



#include<iostream>
#include<vector>
#include<map>
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
map<int, int> mp;//存储中序数组每个元素的下标

//后序   左右根
//中序   左根右
TreeNode* build(vector<int>& postorder,int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd){
    if (postStart> postEnd || inStart > inEnd)
    {
        return nullptr;
    }
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);
    int leftSize = (mp[rootVal]-1) - inStart + 1;
    root->left =  build(postorder, postStart, postStart+leftSize-1, inorder, inStart, mp[rootVal]-1);
    root->right =  build(postorder, postStart+leftSize, postEnd-1, inorder, mp[rootVal]+1, inEnd);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    
    return build(postorder,0,postorder.size()-1, inorder, 0 ,inorder.size()-1);
}