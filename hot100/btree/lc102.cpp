//
// Created by SP on 2023/11/12.
//
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。

// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left=nullptr;
        right=nullptr;
    }
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if (root==nullptr)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> res;//存储该层元素
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
            {
                q.push(node->left);//将i层元素的左右子节点加入下层（如果存在）
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        ans.push_back(res);
    }
    return ans;
}

void print_v(vector<vector<int>>& a){
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    vector<vector<int>> a = levelOrder(root);
    print_v(a);
    return 0;
}