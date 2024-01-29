#include<iostream>
#include<vector>
#include<stack>
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

vector<int> ans;
void dfs(TreeNode* root) {
    if (root==nullptr)
    {
        return;
    }
    dfs(root->left);
    ans.push_back(root->val);
    dfs(root->right);
}
vector<int> inorderTraversal(TreeNode* root) {
    dfs(root);
    return ans;
}

//左中右
vector<int> inorderTraversal_iter(TreeNode* root) {
    vector<int> res;
    if (root==nullptr)
    {
        return res;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur=cur->left;
        }
        cur=st.top();
        res.push_back(cur->val);
        st.pop();
        cur=cur->right;
    }    
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);

    vector<int> res = inorderTraversal(root);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}