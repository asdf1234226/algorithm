//
// Created by SP on 2023/11/12.
//

#include <vector>
#include<iostream>
using namespace std;

//前中后序递归写法
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//前序
//1.递归参数和返回值，参数传TreeNode节点，还有vector记录已经遍历过的
//2.终止条件    空节点
//3.每次递归应该怎么做
void preOrder(TreeNode* node, vector<int>& res) {
    if (node==nullptr)
    {
        return;
    }
    res.push_back(node->val);
    preOrder(node->left, res);
    preOrder(node->right, res);
}
vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> res;
    preOrder(root, res);
    return res;
}

//中序
void middleOrder(TreeNode* node, vector<int>& res){
    if (node==nullptr)
    {
        return;
    }
    middleOrder(node->left,res);
    res.push_back(node->val);
    middleOrder(node->right,res);
}
vector<int> middleOrderTraversal(TreeNode* root){
    vector<int> res;
    middleOrder(root, res);
    return res;
}

//后序
void postOrder(TreeNode* node, vector<int>& res){
    if (node==nullptr)
    {
        return;
    }
    postOrder(node->left, res);
    postOrder(node->right, res);
    res.push_back(node->val);
}
vector<int> postOrderTraversal(TreeNode* root){
    vector<int> res;
    postOrder(root, res);
    return res;
}
    
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    //vector<int> res = preOrderTraversal(root);
    //vector<int> res = middleOrderTraversal(root);
    vector<int> res = postOrderTraversal(root);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}

