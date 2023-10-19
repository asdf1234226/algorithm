//每条边进行松弛操作
//n个点，m条边, 不超过k条边

//3 3 1
//1 2 1
//2 3 1
//1 3 3
//输出3

#include<iostream>
#include<cstring>
using namespace std;

const int M = 100010;//边
const int N = 510;//点
int dist[N];
int backup[N]; //备份
int n, m, k;
const int INF = 0x3f3f3f3f;

struct Edge {
    int a;
    int b;
    int c;
} edges[M];


void bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
	for (int i = 0; i < k; i++) //k条边，第一次遍历获得边数为1的最短路径，第二次遍历获得边数为2的最短路径
	{
		memcpy(backup, dist, sizeof dist); //每一轮迭代只基于上一轮迭代的结果
		for(int j=0;j<m;j++)
		{
			int x = edges[j].a;
			int y = edges[j].b;
			int w = edges[j].c;
			if (backup[x]+w<dist[y])
			{
				dist[y]=backup[x]+w; //dist[j]要由上一轮的backup更新
			}
		}	
	}
}

int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >>b >>c;
        edges[i]={a,b,c};
    }
    bellman_ford();
    if (dist[n]>INF/2) //为什么是>INF/2,如果a,b不可达,a和b的边权-2， INF-2
    {
        cout << "impossible";
    }
    else
    {
        cout << dist[n];
    }
    return 0;
}