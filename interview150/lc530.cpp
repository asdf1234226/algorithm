    //中序遍历，比较和前一个节点的差值
    int ans=INT_MAX;
	TreeNode* prev = nullptr;//
    int getMinimumDifference(TreeNode* root) {
		inorder(root);
		return ans;
	}

	void inorder(TreeNode* root){
		if(root==nullptr) return;
		inorder(root->left);
		if(prev!=nullptr){
			ans=min(ans,(root->val-prev->val));
		}
		prev=root;
		inorder(root->right);
	}