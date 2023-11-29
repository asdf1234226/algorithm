//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// 输出: 6
// 解释: 节点 2 和节点 8 的最近公共祖先是 6。


#include<iostream>
#include<vector>
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root==nullptr)
    {
        return nullptr;
    }
    if (root==p || root==q)
    {
        return root;
    }
    //遍历顺序无所谓，不涉及中节点的处理逻辑（不会根据左子树和右子树的返回值判断返回什么）
    if (p->val<root->val && q->val>root->val)
    {
        return root;
    }
    else if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left,p,q);
    }
    else if (p->val>root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right,p,q);
    }
    else
    {
        return root;
    }

}

int main(){
    TreeNode* root = new TreeNode(6);
    root->left=new TreeNode(2);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(3);
    root->left->right->right=new TreeNode(5);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);
    cout << lowestCommonAncestor(root,root->left, root->left->right)->val;
    return 0;

}