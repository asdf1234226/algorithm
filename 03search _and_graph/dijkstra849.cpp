//n个点m条边，1<=n<=500, 1<=m<=1e5
// 3 3
// 1 2 2
// 2 3 1
// 1 3 4

#include<iostream>
#include<cstring>
using namespace std;
const int N = 510;
int g[N][N];//邻接矩阵
int dist[N];//存储每个点到出发点的最短路径
int n, m;
bool st[N]; //每个点的最短距离是否已确定
const int INF = 0x3f3f3f3f;

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    for (int i = 1; i <= n-1; i++) //1节点确定，每次找一个最小的节点，还要n-1次
    {
        int min_index = -1;
        for (int j = 1; j <=n; j++) //在还没确定最短距离的点，找最小距离的min_index
        {
            if (!st[j] &&(min_index == -1 || dist[j]<dist[min_index]))
            {
                min_index=j;
            }
        }
        
        for (int j = 1; j <=n; j++){ //min_index 更新其他点
            dist[j]=min(dist[j],dist[min_index]+g[min_index][j]);
        }
        st[min_index]=true;
    }
}
int main(){
    memset(g,0x3f,sizeof g);//初始化邻接矩阵
    cin >>n >>m;
    while (m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b]=min(g[a][b],c); //可能有重边
    }
    dijkstra();
    if (dist[n]==INF)
    {
        cout << "-1";
    }else
    {
        cout << dist[n];
    }
    return 0;
}


