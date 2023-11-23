//二叉树的最小深度
//
//当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点

//输入：root = [3,9,20,null,null,15,7]
//输出：2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left=nullptr;
        right=nullptr;
    }
};

//方法1. 后序求高度，和最大深度的区别在于，最小深度要判断左右孩子都空（才是遍历到叶子节点）
//方法2. 层序遍历
int minDepth(TreeNode* root) {//根节点的最小高度
    if (root== nullptr) return 0;
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    if (root->left != nullptr && root->right != nullptr){
        return 1+ min(leftDepth,rightDepth); ////左右子树都不空时才能选最小值
    } else if (root->left== nullptr && root->right!= nullptr){
        return 1+rightDepth;
    } else if (root->left!= nullptr && root->right == nullptr){
        return 1+leftDepth;
    } else{ //root->left = nullptr  root->right = nullptr   这时才是叶子节点
        return 1;
    }
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout << minDepth(root);
    return 0;
}