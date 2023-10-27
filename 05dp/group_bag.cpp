// 3 5
// 2
// 1 2
// 2 4
// 1
// 3 4
// 1
// 4 5
//3组物品，背包容量5，第一组物品2个，体积和价值分别为1 2和2 4
//第二组物品物品1个，体积和价值为3 4
//同一组物品最多选一个
#include<iostream>
using namespace std;
int n,m;
const int N =1010;
int v[N][N]; // v[i][j] 第i组第j个物品
int w[N][N];
int s[N]; //记录第i组的物品个数
int f[N];

int max_value(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= s[i]; k++)
            {
                if (j>=v[i][k])
                {
                    f[j] = max(f[j], f[j-v[i][k]]+w[i][k]);
                }
                
            }     
        }   
    }
    return f[m];

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