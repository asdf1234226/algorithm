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
//找到左子树的右下角
//将右子树拼接到右下角
//翻转到右子树，左子树置空
//继续下一个节点root=root->right(因为全翻到右边了)

void flatten(TreeNode* root) {
    while(root){
        if(root->left== nullptr){//如果没有左节点，就继续
            root=root->right;
        } else{
            TreeNode* pre = root->left;//有左节点
            while (pre->right){
                pre=pre->right;//左节点的最右子节点
            }
            pre->right=root->right;//拼接
            root->right=root->left;//转到右子树
            root->left= nullptr;//置左指针空
            root=root->right;
        }
    }
}
