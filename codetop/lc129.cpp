#include<iostream>
#include<vector>
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
//所有路径的和
//  1 
// 2  3
//4  5  
// (1*10+2)*10+4

//TODO  不熟悉
int help(TreeNode* root, int preLevel){
    if (root==nullptr)
    {
        return 0;//空节点返回0，不然只有一个节点时，这个节点值会被计算多次
    }
    int tmp = root->val+preLevel*10;
    if (root->left==nullptr && root->right==nullptr)
    {
        return tmp;
    }
    return help(root->left, tmp)+help(root->right, tmp);
}

int sumNumbers(TreeNode* root){
    return help(root,0);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout << sumNumbers(root);

}