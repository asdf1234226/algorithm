
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

vector<int> ans;



void dfs(TreeNode* root){
    if (root==nullptr)
    {
        return;
    }
    dfs(root->left);
    ans.push_back(root->val);
    dfs(root->right);
}
bool isValidBST(TreeNode* root){
    dfs(root);
    for (int i = 0; i < ans.size()-1; i++)
    {
        if (ans[i]>=ans[i+1])
        {
            return false;
        }
    }
    return true;
}

long long maxVal = LONG_MIN;
bool isValidBST_1(TreeNode* root){
    if (root==nullptr)
    {
        return true;
    }
    bool l = isValidBST_1(root->left);
    if (maxVal<root->val)//记录左子树最大值
    {
        maxVal=root->val;
    }else
    {
        return false;
    }
    bool r = isValidBST_1(root->right);
    return l && r;
    
}
int main(){
    return 0;
}