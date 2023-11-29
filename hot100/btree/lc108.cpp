//
// Created by SP on 2023/11/28.
//
//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helpBuild(nums, 0, nums.size()-1);
}
//因为高度平衡，二叉搜索数中序展开就是升序的nums数组
//所以尽可能选中间的点作为根节点
TreeNode* helpBuild(vector<int>& nums, int l, int r){
    if(l>r) return nullptr;//递归终止条件
    int mid = (l+r)>>1;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left=helpBuild(nums,l,mid-1);
    root->right=helpBuild(nums,mid+1,r);
    return root;
}