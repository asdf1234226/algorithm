//  https://www.acwing.com/problem/content/2/
// 0<n,m≤1000
// 0<vi,wi≤100

#include<iostream>
using namespace std;
int n; //物品个数
int m; //背包容量
const int N = 1010;
int w[N];//价值
int v[N];//体积
int dp[N];

int max_value(){
    for (int i = 1; i <= n; i++)
    {
        //*****************dp[i][j]只和dp[i-1][]有关，所以可以去除i这一维
        //*****************去除i这一维后，if(j<v[i]) dp[j]=dp[j]可以去掉，j从v[i]到m
        //*****************dp[i-1][j-v[i]]+w[i]，j-v[i]<j，在更新j时，使用的是已经更新的j-v[i]，
        //此时的dp[j-v[i]]等价于dp[i][j-v[i]]而不是i-1，所以要倒序
        for(int j=m;j>=v[i];j--){
            dp[j]=max(dp[j], dp[j-v[i]]+w[i]);
        }   
    }
    return dp[m];
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a,b;
        cin >> a>>b;
        v[i]=a;
        w[i]=b;
    }
    cout << max_value();
    return 0;
}