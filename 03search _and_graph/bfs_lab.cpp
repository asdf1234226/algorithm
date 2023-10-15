//
// Created by SP on 2023/10/15.
//
#include <iostream>
#include <cstring>
#include <queue>
using  namespace std;
const int N = 110;
typedef pair<int, int> PII;  //队列中的(x,y)
int g[N][N],d[N][N]; //g存储地图，d存储距离
PII Prev[N][N];  //记录路径

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue<PII> q;
int n,m;

void bfs(int a, int b){
    memset(d,-1, sizeof d);//初始化为-1，可以标志是否访问过
    q.push({a,b});
    d[0][0]=0;
    while(!q.empty()){
        PII p = q.front();
        q.pop();
        int x = p.first, y=p.second;
        for (int i = 0; i < 4; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (nx>=0 && nx <n && ny>=0 && ny<m && g[nx][ny]==0 && d[nx][ny]==-1)//d[nx][ny]初始化-1，可以标志是否访问过
            {
                Prev[nx][ny]= p;
                q.push({nx,ny});
                d[nx][ny]=d[x][y]+1;
            }
        }
    }
    int x=n-1,y=m-1;  //打印路径（逆序）
    while (x||y){
        cout << x << " " << y << endl;
        auto t = Prev[x][y];
        x = t.first,y=t.second;
    }
}

int main(){
    cin >> n >>m;
    for (int i = 0; i < n; i++) {
        for (int j=0;j<m;j++) {
            cin>>g[i][j];
        }
    }
    bfs(0,0);
    cout << d[n-1][m-1];
    return 0;

}
