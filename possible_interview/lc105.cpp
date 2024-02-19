#include<iostream>
#include<vector>
#include<queue>
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

// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]

//前序   根左右
//中序   左根右
TreeNode* helpBuild(vector<int>& preorder,int prel, int prer, vector<int>& inorder, int inl, int inr){
    int rootV = preorder[prel];
    TreeNode* root = new TreeNode(rootV);
    int index = -1;
    //这个可以统一将inorder建一个map存储
    for(int i=inl;i<=inr;i++){
        //TODO  这个for循环是i=inl;i<=inr
        if (rootV==inorder[i])
        {
            index=i;
            break;
        }
    }
    int lsize = index-inl;
    root->left = helpBuild(preorder,prel+1, prel+lsize, inorder, inl, index-1);
    root->right = helpBuild(preorder, prel+lsize+1,prer, inorder, index+1, inr);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helpBuild(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1);
}