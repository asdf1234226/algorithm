// n个点m条边,k次查询(x到y的最短路径),边权可能负，存在重边自环
// 1<=n<=200
// 1<=k<=n^2
// 1<=m<=20000

// 3 3 2
// 1 2 1
// 2 3 2
// 1 3 1
// 2 1
// 1 3
// 输出 impossible
//      1
#include<iostream>
#include<cstring>
using namespace std;

const int N = 210;
int d[N][N];
int path[N][N]; //**************存路径
int n,m,k;
const int INF = 0x3f3f3f3f;


void floyd(){
    //u为起点，v为终点，如果能经由k更新，就更新d[u][v]
    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for(int v=1;v<=n;v++){
                if (d[u][k]+d[k][v]<d[u][v])
                {
                    d[u][v]=d[u][k]+d[k][v];
                    path[u][v] = k;
                }
            }
        }
    }
}

void print_path(int u, int v){
    int k = path[u][v];
    if (k==-1)
    {
        return;
    }
    print_path(u,k);
    cout << " " << k << " ";
    print_path(k,v);
}

int main(){
    cin>>n>>m>>k;
    memset(d,0x3f,sizeof d);//初始化
    memset(path, -1,sizeof path);
    for (int i = 1; i <= n; i++)
    {
        d[i][i]=0;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b]=min(d[a][b],c);
    }
    floyd();
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (d[x][y]>INF/2)
        {
            cout << "impossible" << endl;
        }else
        {
            cout << d[x][y] << endl;
            print_path(x,y);
        }   
    }
    return 0;
}