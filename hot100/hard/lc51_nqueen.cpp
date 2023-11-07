//
// Created by SP on 2023/11/5.
//

//n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> ans;
vector<string> s;
const int N = 30;
bool col[N], diag[2*N], anti_diag[2*N]; //y=-x+b(b=x+y), y=x+b(b=y-x)
void dfs(int u, int n){
    if (u==n)
    {
        ans.push_back(s);
    }
    //每行放一个，并且对每个位置进行尝试
    for (int j = 0; j < n; j++)//[u,j]
    {
        if (!col[j] && !diag[u+j] && !anti_diag[j-u+n])
        {
            col[j]=diag[u+j]=anti_diag[j-u+n]=true;
            s[u][j]='Q';
            dfs(u+1,n);
            col[j]=diag[u+j]=anti_diag[j-u+n]=false;
            s[u][j]='.';
        }
    }
    
}

vector<vector<string>> solveNQueens(int n) {
    for (int i = 0; i < n; i++)//初始化一个n*n的矩阵用于搜索
    {
        string str = "";
        for (int j = 0; j < n; j++)
        {
            str+=".";
        }
        s.push_back(str);
    }
    dfs(0,n);
    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);
    for(auto it: ans){
        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i] << endl;
        }
        cout << "next....."<<endl;
    }
    
    return 0;
}