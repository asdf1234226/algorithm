//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

//


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> a,b;
    dfs(root,p,a);
    dfs(root,q,b);
    TreeNode* ans = nullptr;
    //遍历路径找到最后一个相同的节点
    for(int i=0;i<a.size() && i< b.size();i++){
        if(a[i]==b[i]){
            ans=a[i];
        }
    }
    return ans;
}
//从根节点cur到 t的路径
bool dfs(TreeNode* cur, TreeNode* t, vector<TreeNode*>& path) {
    if (!cur) return false;
    path.push_back(cur);
    if (cur == t) {
        return true;
    }
    if(dfs(cur->left, t,path) || dfs(cur->right,t,path)){
        return true;
    }
    path.pop_back();
    return false;
}
