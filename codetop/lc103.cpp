#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    if (root==nullptr)
    {
        return ans;
    }
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        vector<int> tmp;
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            tmp.push_back(node->val);
        }
        if(!flag){
            reverse(tmp.begin(), tmp.end());
        }
        ans.push_back(tmp);
        flag=!flag;
    }
    return ans;
}