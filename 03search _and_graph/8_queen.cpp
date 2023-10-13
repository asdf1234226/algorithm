//
// Created by SP on 2023/10/12.
//

//n皇后，行，列，45°对角线，135°对角线都不能有两个皇后
#include<iostream>
using namespace std;
const int N = 11;
char q[N][N];
bool col[N], dg[N], antidg[N]; //列，对角线，反对角线,同一条对角线的截距相同
int n;

void dfs(int u){//第u行
    if (u==n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << q[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        //dg: y=-x+b
        //antidg: y=x+b
        if (!col[i]&&!dg[i+u]&&!antidg[i-u+n]) //+n为了保证是正数
        {
            col[i]=dg[i+u]=antidg[i-u+n]=true;
            q[u][i]='Q';
            dfs(u+1);
            q[u][i]='.';
            col[i]=dg[i+u]=antidg[i-u+n]=false;
        }  
    }
}

int main(){
    n=4;
    //初始化
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[i][j]='.';
        }
    }
    dfs(0);
    return 0;

}