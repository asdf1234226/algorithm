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
    
    for (int i = 1; i <= n-1; i++)
    {
        for(int j=i+1;j<=n;j++){
            if (j==i+1)
            {
                f[i][j]=a[i]+a[j];
            }
            else
            {
                for (int k = i; k+1 <= j; k++)
                {
                    f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]+presum[j]-presum[i-1]);
                }
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