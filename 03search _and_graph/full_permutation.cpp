//
// Created by SP on 2023/10/12.
//

//全排列，输入数字n，输出全排列
#include<iostream>
#include <stack>
using namespace std;
const int N = 20;
bool vis[N];
int path[N];
int n;

void dfs(int u){
    if (u==n)
    {
        for(int i=0;i<n;i++){
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <=n; i++) //遍历所有元素
    {
        if (!vis[i])
        {
            path[u]=i;
            vis[i]=true;
            dfs(u+1);
            vis[i]=false;
        } 
    }
}
int main(){
    n = 3;
    dfs(0);
    return 0;
}