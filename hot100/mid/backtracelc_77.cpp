//
// Created by SP on 2023/11/7.
//

//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
// n=4,k=2
//输出：[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4],]

#include<iostream>
#include<vector>
using namespace std;


//   第一层1 2 3
//   第二层 1下{2,3}， 2下{3}， 3下{}，用i+1去重实现

vector<vector<int>> ans;
vector<int> path;//记录路径
void dfs(int n, int k, int start){
    if (path.size()==k)
    {
        ans.push_back(path);
        return;
    }
    for (int i = start; i <= n; i++) //  控制树的横向遍历
    {
        path.push_back(i);
        dfs(n,k,i+1);//i+1保证该树枝的下一层递归会从i+1及后元素中选
        //如果是i，则i可重复选择，下一层递归会从i及i后元素中选
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    dfs(n,k,1);
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
    vector<vector<int>> a = combine(4,2);
    print_v(a);
    return 0;
    
}