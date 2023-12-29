// 给定一个有序整数数组，元素各不相同且按升序排列，
// 编写一个算法，创建一棵高度最小的二叉搜索树。

#include<iostream>
#include<vector>
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

TreeNode* help(vector<int>& nums, int l, int r){
    if (l>r)
    {
        return nullptr;
    }
    int mid = (l+r)>>1;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left=help(nums,l,mid-1);
    root->right=help(nums,mid+1,r);
    return root;
}

//二叉搜索树中序(左中右)有序
//选数组中点的数作为根节点
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return help(nums,0,nums.size()-1);
}

