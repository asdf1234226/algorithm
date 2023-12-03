//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

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

//由底向上，所以后序遍历
//root==nullptr，或者root==p 或root==q则返回
//终止条件其实是找到p或q就返回
//如果l !=nullptr，r!=nullptr，那么左子树找到一个，右子树找到另一个，所以root是
//如果l和r中其中一个nullptr，那么说明在非空的子树上
//结合图理解，如果找到p或者q，就会往上层传递，总会在某个节点上左边为p右边为q(或者左q右p)
//有可能 1 2 3（中序顺序），p为1，q为3,这样在某个节点的左右
//也有可能是-1 1 0 2 4 3（中序），p是-1，q是4，在左子树1上会返回-1，右子树3返回4（底向上传递），仍然在2节点的左右
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==nullptr)
    {
        return nullptr;
    }
    if (root==p || root==q)
    {
        return root;
    }
    TreeNode* l = lowestCommonAncestor(root->left, p,q);
    TreeNode* r = lowestCommonAncestor(root->right,p,q);
    if(l && r){
        return root;
    }else if (l && r ==nullptr)
    {
        return l;
    }else if (l==nullptr && r)
    {
        return r;
    }
    else
    {
        return nullptr;
    }
}