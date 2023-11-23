//
// Created by SP on 2023/11/23.
//


int countNodes(TreeNode* root) {//普通二叉树求节点数
    if(root==nullptr) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

int countNodes(TreeNode* root) {//完全二叉树求节点数
    //如果判断是完全二叉树，向左遍历的深度 == 向右遍历的深度
    if(root==nullptr) return 0;
    //利用满二叉树性质,2^depth-1
    int l = 0;
    TreeNode* curleft = root->left;
    while(curleft){
        l++;
        curleft=curleft->left;
    }
    int r = 0;
    TreeNode* curright = root->right;
    while(curright){
        r++;
        curright=curright->right;
    }
    if(l==r) return (2<<l) -1;//如果是满二叉树
    return countNodes(root->left)+countNodes(root->right)+1;
}