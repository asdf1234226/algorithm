//
// Created by SP on 2023/11/23.
//
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//示例 1:
//给定二叉树 [3,9,20,null,null,15,7]
//返回 true 。

////最大深度的变形题
int maxDepth(TreeNode* root){
    if(root==nullptr) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if(abs(l-r)>1) return -1;
    return (l==-1 || r==-1)?-1:1+max(l,r);
}
bool isBalanced(TreeNode* root) {
    return maxDepth(root)==-1?false:true;
}
//或者写个求最大深度的函数
int maxDepth(TreeNode* root){
    if(root==nullptr) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1+max(l,r);
}
bool isBalanced(TreeNode* root) {
    if(root== nullptr) return true;
    if(!isBalanced(root->left)) return false;
    if(!isBalanced(root->right)) return false;
    return abs(maxDepth(root->left)- maxDepth(root->right))<=1;
}

int maxDepth(TreeNode* root){//求最大深度
    if(root==nullptr) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1+max(l,r);
}
bool isBalanced(TreeNode* root) {//后序 or 前序都可以
    if(root== nullptr) return true;
    if(abs(maxDepth(root->left)- maxDepth(root->right))>1){
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}