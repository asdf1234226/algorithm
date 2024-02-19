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

vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> res;
    if(root==nullptr) return res;//判空
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* nod = q.front();
            q.pop();
            if (i==size-1)
            {
                res.push_back(nod->val);
            }
            if (nod->left)
            {
                q.push(nod->left);
            }
            if (nod->right)
            {
                q.push(nod->right);
            }
        }
    }
    return res;
}

int main(){
    return 0;
}