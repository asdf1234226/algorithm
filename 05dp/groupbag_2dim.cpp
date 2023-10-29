//
// Created by SP on 2023/10/29.
//

#include<iostream>
using namespace std;
int n,m;
const int N =1010;
int v[N][N]; // v[i][j] 第i组第j个物品
int w[N][N];
int s[N]; //记录第i组的物品个数
int f[N][N];

int max_value(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j]=f[i-1][j];//不选
            for (int k = 1; k <= s[i]; k++)
            {
                if (j>=v[i][k])//选1~s[i]的某一个
                {
                    f[i][j] = max(f[i][j], f[i-1][j-v[i][k]]+w[i][k]);
                }
            }
        }
    }
    return f[n][m];

}


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }
    cout << max_value();
    return 0;


}