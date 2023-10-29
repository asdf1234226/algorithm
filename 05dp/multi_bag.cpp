#include<iostream>
using namespace std;
int n,m;//n件物品，背包容积m
const int N = 1010;
int v[N], w[N], s[N]; //每件物品体积、价值、限制数量
int f[N][N];

// 4 5
// 1 2 3
// 2 4 1
// 3 4 3
// 4 5 2
//输出 10

int max_value(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
            for (int k = 0; k<=s[i]&&k*v[i] <= j; k++)//和完全背包朴素版多了数量限制
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        } 
    }
    return f[n][m];
}

int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i]>>w[i]>>s[i];
    }
    cout << max_value();
    return 0;
}