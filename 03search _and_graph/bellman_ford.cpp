//每条边进行松弛操作
//n个点，m条边, 不超过k条边

#include<iostream>
#include<cstring>
using namespace std;

const int M = 100010;//边
const int N = 510;//点
int dist[N];
int backup[N];
int n, m, k;
const int INF = 0x3f3f3f3f;

struct Edge {
    int a;
    int b;
    int c;
} edges[M];


void bellman_ford(){
	for (int i = 0; i < k; i++)
	{
		memcpy(backup, dist, sizeof dist);
		for(int j=0;j<m;j++)
		{
			int x = edges[i].a;
			int y = edges[i].b;
			int w = edges[i].c;
			if (dist[x]+w<dist[y])
			{
				dist[y]=dist[x]+w;
			}
		}	
	}
}

int main(){
    cin >> n >> m >> k;
	memset(dist, 0x3f, sizeof dist);
    bellman_ford();
    if (dist[N]>INF/2)
    {
        cout << "not";
    }
    else
    {
        cout << dist[n];
    }
    
    return 0;
}