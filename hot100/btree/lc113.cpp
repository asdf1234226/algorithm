//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

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

//TODO  和所有路径对比,记住树的回溯模板
vector<vector<int>> ans;
vector<int> path;

void dfs(TreeNode* root, int sum){
    path.push_back(root->val);
    sum-=root->val;
    if (root->left==nullptr && root->right==nullptr)//到叶子节点
    {
        if (sum==0)
        {
            ans.push_back(path);
        }
        path.pop_back();
        return;
    }
    if (root->left){
        dfs(root->left,sum);//已经将root->left->val加入过path，所以要弹出
        //path.pop_back();
    }
    if (root->right){
        dfs(root->right, sum);
        //path.pop_back();
    }
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum){
    if (root==nullptr)
    {
        return ans;
    }
    dfs(root, sum);
    return ans;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    cout << pathSum(root, 7).size();
    return 0;
}