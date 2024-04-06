#include<iostream>
#include<vector>
#include<map>
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
map<int,int> mp;
//根 左 右
//左 根 右
// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]
TreeNode* helpBuild(vector<int>& preorder, int prest, int preed,vector<int>& inorder, int inst, int ined){
    if(prest>preed || inst>ined) return nullptr;
    TreeNode* root = new TreeNode(preorder[prest]);
    int index = mp[preorder[prest]];
    int lsize = index-inst;
    root->left = helpBuild(preorder,prest+1,prest+lsize, inorder,inst,index-1);
    root->right = helpBuild(preorder,prest+lsize+1,preed,inorder,index+1,ined);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    return helpBuild(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}