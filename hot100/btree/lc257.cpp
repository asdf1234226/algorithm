
//给定一个二叉树，返回所有从根节点到叶子节点的路径。

#include<iostream>
#include<vector>
using namespace std;



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
vector<string> ans;
vector<int> path;

void dfs(TreeNode* root){
    if (root->left==nullptr && root->right == nullptr)
    {
        string s;
        for(auto it: path){
            s+=std::to_string(it);
            s+="->";
        }
        if (!path.empty())
        {
            s = s.substr(0, s.size()-2);
        }
        ans.push_back(s);
        return;
    }
    if (root->left)
    {
        path.push_back(root->left->val);
        dfs(root->left);
        path.pop_back();//回溯
    }
    
    if (root->right)
    {
        path.push_back(root->right->val);
        dfs(root->right);
        path.pop_back();//回溯
    }
}

vector<string> binaryTreePaths(TreeNode* root){
    if (root==nullptr)
    {
        return ans;
    }
    path.push_back(root->val);
    dfs(root);
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
    vector<string> a = binaryTreePaths(root);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}