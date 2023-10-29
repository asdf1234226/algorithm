// description: 相邻石子可以合并，成本为a[i]+a[j]，最后合并成一堆，求最少cost
// 4
// 1 3 5 2
// 输出 22
// 4 5 2(4)---> 4 7(11)--->22

#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N = 1010;
int a[N];
int f[N][N];//f[i][j]为从i到j下标的石子合并的最小代价
int presum[N];

int min_cost(){
    for (int i = 1; i <= n; i++)
    {
        presum[i]=presum[i-1]+a[i];
    }
    memset(f,0x3f,sizeof f);
    for (int i = 1; i <= n; i++)
    {
        f[i][i]=0;
    }
    
    for (int len = 2; len <= n; len++)
    {
        for(int i=1;i+len-1<=n;i++){
            int l=i,r=i+len-1;
            for (int k = l; k+1 <= r; k++) {
                f[l][r] =min(f[l][r], f[l][k]+f[k+1][r]+presum[r]-presum[l-1]);
            }
        }
    }
    return f[1][n];
}


int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << min_cost();
    return 0;
}