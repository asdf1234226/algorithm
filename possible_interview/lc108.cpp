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

TreeNode* help(vector<int>& nums, int l, int r){
    if(l>r) return nullptr;// TODO   需要注意这个判断
    int mid = (l+r)>>1;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = help(nums,l,mid-1);
    root->right = help(nums,mid+1,r);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return help(nums,0,nums.size()-1);
}

int main(){
    return 0;
}