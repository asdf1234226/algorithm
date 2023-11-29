//给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。

TreeNode* insertIntoBST(TreeNode* root, int val){
    if (root==nullptr)//终止条件
    {
        TreeNode* node = new TreeNode(val);
        return node;
    }
    if(val<root.val){
        root->left = insertIntoBST(root->left, val);//在左子树插入，要返回root
        return root;
    }
    else
    {
        root->right = insertIntoBST(root->right,val);//在右子树插入，返回root
        return root;
    }
}