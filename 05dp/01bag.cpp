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
int dp[N][N];

//dp[i][j], i表示只从前i个物品中选，j表示总体积<=j， dp[i][j]表示属性是最大值


int max_value(){
    for (int i = 1; i <= n; i++)
    {
        for(int j=0;j<=m;j++){
            if (j<v[i])  //装不下
            {
                dp[i][j]=dp[i-1][j];
            }
            else //能装，判断取最大值（不放和放的）
            {
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
            }
        }   
    }
    return dp[n][m];
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