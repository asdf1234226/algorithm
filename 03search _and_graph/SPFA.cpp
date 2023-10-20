// 3 3
// 1 2 5
// 2 3 -3
// 1 3 4
// 输出2

//n个点m条边有向图，可能重边和自环，边权可能负，求1到n的最短距离，无法走到输出impossible
//1<=n,m<=1e5
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N =1e5+10;
int dist[N];
int e[N], ne[N], w[N], idx;
int h[N];
int n, m;
queue<int> q;
bool inq[N]; //存放是否在队列中

void add(int a, int b, int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

void spfa(){
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    q.push(1);
    inq[1]=true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        inq[p]=false; //p不在队列中
        for (int i = h[p]; i !=-1; i=ne[i]) //遍历t能到底的所有点
        {
            int j = e[i]; //边的另一个点
            if(dist[p]+w[i]<dist[j]) //如果j的距离被更新
            {
                dist[j]=dist[p]+w[i];
                if(!inq[j]){
                    q.push(j);
                    inq[j]=true;
                }
            }
        }  
    } 
}

int main(){
    cin >> n >>m;
    memset(h,-1,sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >>c;
        add(a,b,c);
    }
    spfa();
    if (dist[n]>0x3f3f3f3f/2) //也可以写成dist[n]==0x3f3f3f3f; 相当于BFS，遍历到的所有节点都与源点连通
    //所以不会存在Bellman ford的a-->n，a不可达，dist[a]=INF,但是a和n之间边-2，dist[n]=INF-2的情况（不会遍历此边）
    {
        cout << "impossible";
    }
    else
    {
        cout << dist[n];
    }
    return 0;
}