#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

queue<int> q;
const int N = 100010;
int e[N], ne[N], idx;
int h[N];
int n, m;
int degree[N]; //存储节点的入度
vector<int> ans; //存储队列中入度为0的点

void add(int a, int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
// 3 3
// 1 2
// 2 3
// 1 3
// 输出1 2 3

bool topoSort(){
    for (int i = 1; i <= n; i++) //1~n节点所有入度为0的节点入队
    {
        if (degree[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        ans.push_back(p);
        for (int i = h[p]; i != -1; i=ne[i])
        {
            int j = e[i];
            degree[j]--;
            if (degree[j]==0)  //将入度为0的点入队
            {
                q.push(j);
            }  
        }
    }
    return ans.size()==n; //如果全部节点都入队过，可以拓扑排序
}

int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h); //不要忘了初始化
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        add(a,b);
        degree[b]++; //b入度+1
    }
    if (topoSort())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "-1";
    }
    
    return 0;
    

}