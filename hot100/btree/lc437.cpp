//
// Created by SP on 2023/11/29.
//

//给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
//路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的
int count=0;

void dfs(TreeNode* root, long sum){
    sum-=root->val;
    if(sum==0){
        ////不要return,因为不要求到叶节点结束,所以一条路径下面还可能有另一条
        count++;
    }
    if (root->left){
        dfs(root->left,sum);
    }
    if (root->right){
        dfs(root->right, sum);
    }
}
int pathSum(TreeNode* root, int targetSum) {
    if (root==nullptr)
    {
        return 0;
    }
    dfs(root, targetSum);//以root为起始点查找路径
    pathSum(root->left,targetSum);//左子树递归
    pathSum(root->right,targetSum);
    return count;
}