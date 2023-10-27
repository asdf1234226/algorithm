#include<iostream>
using namespace std;
int n,m;//n件物品，背包容积m
const int N = 1010;
int v[N], w[N], s[N]; //每件物品体积、价值、限制数量
int f[N];
int newv[N], neww[N], cnt;

// 4 5
// 1 2 3
// 2 4 1
// 3 4 3
// 4 5 2
//输出 10

int max_value(){
    for (int i = 1; i <= n; i++) //将s[i]转换为二进制表示（非常规意义的），进而转换为0 1背包问题
    // 11 = 1+2+4+4(从小到大的，不能转换为1+2+8,这样无法组合来表示1-11的全部数)
    {
        while (s[i])
        {
            cnt++;
            int k =1;
            newv[cnt]=v[i]*k;
            neww[cnt]=w[i]*k;
            s[i]-=k;
            k*=2;
        }
    }
    for (int i = 1; i <=cnt; i++)
    {
        for (int j = m; j >= newv[i]; j--)
        {
            f[j]=max(f[j],f[j-newv[i]]+neww[i]);
        }
        
    }
    return f[m];
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