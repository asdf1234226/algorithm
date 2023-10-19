// 3 3
// 1 2 2
// 2 3 1
// 1 3 4
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100010;
int h[N];
int e[N], ne[N], idx, w[N];
int dist[N];
bool st[N];
int n, m;
typedef pair<int, int> PII;
priority_queue<PII> pq; //<距离，节点下标>

void add(int a, int b, int c) //存a到b的边，边权为c
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist); //初始化
    dist[1]=0;
    pq.push({0,1});
    while (!pq.empty()) //pq维护最小堆，每次取top就说最短的dist[]
    {
        PII p = pq.top();
        pq.pop();
        int d = p.first;//distance
        int index = p.second; //index
        if (st[index])
        {
            continue;
        }
        for (int i = h[index]; i !=-1; i=ne[i]) //遍历index为起点的所有边
        {    
            int j = e[i]; //index为起始点的边的另一个点
            if (dist[j]>d+w[i]) //如果这条边将到j的最小距离更新
            {
                dist[j]=d+w[i];
                pq.push({dist[j], j});
            }
        }
        st[index]=true;
    }
}


int main(){
    cin >>n >> m;
    memset(h,-1, sizeof h);
    while (m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
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