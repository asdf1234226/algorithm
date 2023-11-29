//
// Created by SP on 2023/11/27.
//

//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。



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

//前序   根左右
//中序   左根右
TreeNode* build(vector<int>& preorder,int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
    if (preStart>preEnd || inStart>inEnd)
    {
        return nullptr; //终止条件
    }
    
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);//根节点
    int leftSize = (mp[rootVal]-1) - inStart + 1;//通过根节点在inorder的位置可以得到左子树的大小
    root->left = build(preorder, preStart+1, preStart + leftSize, inorder, inStart, mp[rootVal]-1);
    root->right = build(preorder,preStart+leftSize+1, preEnd, inorder, mp[rootVal]+1,inEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    
    return build(preorder,0,preorder.size()-1, inorder, 0 ,inorder.size()-1);
}



















public TreeNode buildTree(int[] preorder, int[] inorder) {
    return build(preorder,0,preorder.length-1,inorder,0,inorder.length-1);
}
public TreeNode build(int[] preorder,int preStart,int preEnd,
                      int[] inorder,int inStart,int inEnd){
    if(preStart>preEnd){
        return null;
    }
    int rootVal=preorder[preStart];
    int index=-1;
    for(int i=inStart;i<=inEnd;i++){
        if(rootVal==inorder[i]){
            index=i;
            break;
        }
    }
    int leftSize=index-inStart;
    TreeNode root=new TreeNode(rootVal);
    root.left=build(preorder,preStart+1,preStart+leftSize,
                    inorder,inStart,index-1);
    root.right=build(preorder,preStart+leftSize+1,preEnd,
                     inorder,index+1,inEnd);
    return root;
}