#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

//左中右
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> ans;
    if(root==nullptr) return ans;
    while(root || !st.empty()){
        while (root)
        {
            st.push(root);
            root=root->left;
        }
        //出栈时添加结果
        TreeNode* nod = st.top();
        ans.push_back(nod->val);
        st.pop();
        //指向右节点
        root=nod->right;
    }
    return ans;
}

int main(){
    return 0;
}