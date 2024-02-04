#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root==nullptr)
    {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> a;
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            a.push_back(node->val);
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        res.push_back(a);
    }
    return res;
}

int main(){
    return 0;
}