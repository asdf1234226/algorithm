#include<iostream>
#include<climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};
int ans =INT_MIN;

//二叉树最大高度变形
//1. 为什么之前写法有问题： 之前写法定义为root为根节点的最大路径，dfs(root->left)和dfs(root->right)会有重叠，且不一定能组成一条路径
//    所以要定义为root往下延伸能取得的最大路径和
//    递归函数返回值，可能会是向左延伸root->val + dfs(root->left)或向右延伸root->val+dfs(root->right)
//    由于节点值可能为负值，所以返回值还可能是root->val； 所以返回值max(root->val, max(root->val+l, root->val+r))
//2. 调用一次dfs已经能完成树的遍历，所以只需要在遍历过程中求以某node节点为根的最大路径和
//            所以维持一个全局变量ans在遍历到某node时更新
int dfs(TreeNode* root){
    if(root==nullptr) return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    int res = root->val;
    if(l>=0){
        res+=l;
    }
    if(r>=0){
        res+=r;
    }
    ans=max(res,ans);
    return max(root->val, max(root->val+l, root->val+r));
}

int maxSum(TreeNode* root){
    dfs(root);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(-1);
    root->right->right=new TreeNode(4);
    cout << maxSum(root);
    //输出10
    return 0;
}