// 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k ，
// 返回到目标结点 target 距离为 k 的所有结点的值的数组
//Node.val 中所有值 不同
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x){
        val = x;
        left=nullptr;
        right=nullptr;
    }
};
const int N = 510;
int e[N], ne[N], h[N];
bool vis[N];
int idx;
void add(int a, int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

void dfs(TreeNode* root){
    if (root == nullptr) return;
    if (root->left)
    {
        add(root->val, root->left->val);
        add(root->left->val, root->val);
        dfs(root->left);
    }
    if (root->right)
    {
        add(root->val, root->right->val);
        add(root->right->val, root->val);
        dfs(root->right);
    }
}

//思路：如果题目是以图的形式给出，我们可以很容易通过「BFS / 迭代加深」找到距离为 k 的节点集
//树是特殊的图，所以对二叉树连通的节点（root, root.left和root.right）建立无向边

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    memset(h,-1,sizeof h);
    memset(ne,-1,sizeof ne);
    memset(vis,false,sizeof vis);
    dfs(root);
    vector<int> ans;
    queue<int> q;
    q.push(target->val);
    vis[target->val]=true;// 在加入队列之前标记为已访问
    while(!q.empty() && k >= 0){
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int nod = q.front();
            q.pop();
            if (k==0)
            {
                ans.push_back(nod);
                continue;
            }
            for (int i = h[nod]; i!= -1; i=ne[i])
            {
                if (!vis[e[i]])
                {
                    q.push(e[i]);
                    vis[e[i]]=true;
                }
            }
        }
        k--;
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right=new TreeNode(8);
    vector<int> ans = distanceK(root,root->left,2);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}