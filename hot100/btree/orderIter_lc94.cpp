
//前中后序迭代写法
#include <vector>
#include <stack>
#include<iostream>
#include<algorithm>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = nullptr;
    }
};

//前序  中左右
vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    if (root == nullptr)
    {
        return res;
    }
    
    st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);//根
        //为什么要先加入右孩子，再加入左孩子呢？ 因为这样出栈的时候才是中左右的顺序。
        if (node->right!=nullptr)//右
        {
            st.push(node->right);
        }
        if (node->left!=nullptr)//左
        {
            st.push(node->left);
        }
    }
    return res;
}

//中序  左中右
vector<int> middleOrderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> st;
    if (root==nullptr)
    {
        return res;
    }
    TreeNode* cur = root;
    while (!st.empty()|| cur)//栈不空或者右子节点未访问（第二次循环的cur是右子节点）
    {
        while (cur != nullptr)//找到最左侧节点，并把路径中的入栈，第一次出栈的是最左侧节点
        {
            st.push(cur);
            cur=cur->left;
        }
        cur = st.top();//第一次出栈最左侧节点
        st.pop();
        //最左侧节点，要么有右子树，要么没有右子树
        // a.有右子树，需要入栈，也符合左中右的顺序，最左侧节点相当于中，其右子结点相当于右
        // b.没有右子树，curl->right空指针，不会进入第二层while(),继续出栈
        res.push_back(cur->val);
        cur=cur->right;  
    }
    
    return res;
}

//后序  左右中
//前序是中左右， --->先变化成中右左--->再反转变成左右中
vector<int> postOrderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> st;
    if (root==nullptr)
    {
        return res;
    }
    st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);
        if (node->left!=nullptr)
        {
            st.push(node->left);//左
        }
        if (node->right!=nullptr)
        {
            st.push(node->right);//右
        }
    }
    reverse(res.begin(), res.end());//根右左，然后反转
    return res;
}
    
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);

    //vector<int> res = preOrderTraversal(root);
    vector<int> res = middleOrderTraversal(root);
    //vector<int> res = postOrderTraversal(root);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}

