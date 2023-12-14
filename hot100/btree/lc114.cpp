// 给你二叉树的根结点 root ，请你将它展开为一个单链表：

// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，
// 而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同

// 输入：root = [1,2,5,3,4,null,6]
// 输出：[1,null,2,null,3,null,4,null,5,null,6]


#include<iostream>
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

void flatten(TreeNode* root) {
    while(root){
        if(root->left== nullptr){
            root=root->right;
        } else{
            TreeNode* pre = root->left;
            while (pre->right){
                pre=pre->right;
            }
            pre->right=root->right;
            root->right=root->left;
            root->left= nullptr;
            root=root->right;
        }
    }
}
