
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
    path.push_back(root->val);
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
        path.pop_back();//因为要return，所以要弹出
        return;
    }
    if (root->left)
    {
        dfs(root->left);
    }
    if (root->right)
    {
        dfs(root->right);
    }
    path.pop_back();//弹出，回溯
}

vector<string> binaryTreePaths(TreeNode* root){
    if (root==nullptr)
    {
        return ans;
    }
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