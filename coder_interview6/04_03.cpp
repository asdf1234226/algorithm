// 给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表
// （比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

// 输入：[1,2,3,4,5,null,7,8]

//         1
//        /  \ 
//       2    3
//      / \    \ 
//     4   5    7
//    /
//   8

// 输出：[[1],[2,3],[4,5,7],[8]]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};

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

vector<ListNode*> listOfDepth(TreeNode* tree) {
    queue<TreeNode*> q;
    vector<ListNode*> res;
    q.push(tree);
    while (!q.empty())
    {
        int size = q.size();
        while (size>0)
        {
            vector<int> vec;
            size--;
            ListNode* pre = nullptr;
            ListNode* cur = pre;
            for (int i = 0; i < size; i++)
            {
                TreeNode* nod = q.front();
                q.pop();
                if(nod->left){
                    q.push(nod->left);
                }
                if (nod->right)
                {
                    q.push(nod->right);
                }
                vec.push_back(nod->val);
                cur->next=new ListNode(vec[i]);
            }
            cur->next=nullptr;
            res.push_back(pre->next);
        }
        return res;
    }
}