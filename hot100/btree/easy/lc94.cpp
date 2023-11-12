//
// Created by SP on 2023/11/12.
//

#include <vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode* node, vector<int>& res) {
    if (node != nullptr) {
        if (node->left != nullptr) {
            helper(node->left, res);
        }
        res.push_back(node->val);
        if (node->right != nullptr) {
            helper(node->right, res);
        }
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
}
    


int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = inorderTraversal(root);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}

