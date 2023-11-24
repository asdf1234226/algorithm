
//计算给定二叉树的所有左叶子之和。


#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left= nullptr;
        right= nullptr;
    }
};

//左叶子节点的条件
//node->left!=nullptr && node->left的左右子节点为空，则node->left就是左叶子结点
int sumOfLeftLeaves_err(TreeNode* root) {
    if(root==nullptr || root->left == nullptr) return 0;
    //root and root->left不空
    int value = 0;
    if (root->left->left==nullptr && root->left->right==nullptr)
    {
        value=root->left->val;//符合条件
    }
    //前序遍历，在计算当前节点的左叶子结点值后，加上左子树和右子树的递归值
    return value+sumOfLeftLeaves_err(root->left)+sumOfLeftLeaves_err(root->right);
}


//虽然root->left为空，但右子树可能有左叶子节点的
int sumOfLeftLeaves(TreeNode* root) {
    if(root==nullptr) return 0;
    int value = 0;
    if (root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr)
    {
        value=root->left->val;//符合条件
    }
    //前序遍历，在计算当前节点的左叶子结点值后，加上左子树和右子树的递归值
    return value+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
}


int main(){
    TreeNode* root = new TreeNode(1);
    //root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    //root->left->left=new TreeNode(3);
    //root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    cout << sumOfLeftLeaves(root);
    return 0;
}