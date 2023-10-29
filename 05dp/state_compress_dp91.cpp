//
// Created by SP on 2023/10/29.
//
//n个点的有权无向图，求0到n-1的最短Hamilton路径（0到n-1不重不漏恰好经过每个点一次）
//https://www.acwing.com/solution/content/18533/
//5
//0 2 4 5 1
//2 0 6 5 3
//4 6 0 8 3
//5 5 8 0 5
//1 3 3 5 0
//输出 18
//1<=n<=20
//0<=a[i,j]<=1e7

#include<iostream>
#include<cstring>
using namespace std;

int n;
const int N=21;
const int M = 1<<N;
int a[N][N];
int f[M][N]; //f[i][j]从0到j，走过的点是i的情况
//走过0，1，2，4这几个点的表示10111

int min_ham(){
    memset(f,0x3f,sizeof f);
    f[1][0]=0;
    for (int i = 0; i < 1<<n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i>>j &1){
                for (int k = 0; k < n; ++k) {
                    if (i>>k &1)
                        f[i][j]=min(f[i][j], f[i-(1<<j)][k]+a[k][j]);
                }
            }
        }
    }
    return f[(1<<n)-1][n-1];
}



int main(){
    cin >> n;
    for (int i = 0; i <n ; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << min_ham();
    return 0;
}
