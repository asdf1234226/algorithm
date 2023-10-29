//
// Created by SP on 2023/10/29.
//

//5 5
//1 2 3 4 5
//16 17 18 19 6
//15 24 25 20 7
//14 23 22 21 8
//13 12 11 10 9
// a[i][j]是滑雪场第i行第j列高度，每次可以上下左右任意一个方向滑动一个单位距离

#include<iostream>
#include<cstring>
using namespace std;

int n,m;
const int N = 1010;
int a[N][N];
int f[N][N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dfs(int x, int y){
    if (f[x][y]!=-1) return f[x][y];
    f[x][y]=1;
    for (int i = 0; i < 4; ++i) {
        int nx=x+dx[i],ny=y+dy[i];
        if (nx>0 && nx<=n && ny >0 && ny <=m && a[nx][ny]< a[x][y]){
            f[x][y]=max(f[x][y], dfs(nx,ny)+1);
        }
    }
    return f[x][y];
}

int main(){
    cin >> n >>m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=m ; ++j) {
            cin >> a[i][j];
        }
    }
    memset(f,-1,sizeof f);
    int res =0;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m ; ++j) {
            res=max(res,dfs(i,j));
        }
    }
    cout << res;
    return 0;
}