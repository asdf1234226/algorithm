//
// Created by SP on 2023/11/27.
//

//给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
//
//创建一个根节点，其值为 nums 中的最大值。
//递归地在最大值 左边 的 子数组前缀上 构建左子树。
//递归地在最大值 右边 的 子数组后缀上 构建右子树

//可以借鉴105
int findMaxIndex(vector<int>& nums, int l, int r){
    int max_v = nums[l];
    int index= l;
    for(int i = l+1; i<=r;i++){
        if(nums[i]>max_v){
            max_v=nums[i];
            index=i;
        }
    }
    return index;
}
//参考lc105
TreeNode* build(vector<int>& nums, int l ,int r){
    if(l>r) return nullptr;//递归终止条件
    int index = findMaxIndex(nums,l,r);
    TreeNode* root =new TreeNode(nums[index]);
    root->left=build(nums,l,index-1);
    root->right=build(nums,index+1,r);
    return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums,0,nums.size()-1);
}