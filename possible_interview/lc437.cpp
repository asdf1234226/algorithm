// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
// -109 <= Node.val <= 109 
// -1000 <= targetSum <= 1000 
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
int ans;
void dfs(TreeNode* root, long sum){//以某个节点为根节点的路径和为sum
    if (root==nullptr)
    {
        return;
    }
    if (root->val == sum)
    {
        ans++;//不能return，因为再加上下面的某几个节点可能又能凑成
    }
    dfs(root->left, sum-root->val);
    dfs(root->right, sum-root->val);
}
int pathSum(TreeNode* root, int targetSum) {
    if (root==nullptr)
    {
        return 0;
    }
    dfs(root, targetSum);
    //pathSum(root->left, targetSum-root->val);
    //pathSum(root->right, targetSum-root->val);
    pathSum(root->left, targetSum);//对所有节点做
    pathSum(root->right, targetSum);
    return ans;
}

int main(){
    return 0;
}