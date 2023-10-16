//
// Created by SP on 2023/10/15.
//
#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
const int N = 100010;
int e[N], ne[N], idx;
int h[N];
int n,m;
queue<int> q;
int dis[N]; //记录从1到每个节点的距离


void add(int a, int b){//存图
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void bfs(int u){
    memset(dis,-1,sizeof dis);//初始化距离
    q.push(u);
    dis[u]=0;
    while (!q.empty()){
        int p = q.front();
        q.pop();
        for (int i = h[p]; i!=-1; i=ne[i]) {
            int j =e[i];  //下一个节点的值
            if (dis[j]==-1){//没访问过
                q.push(j);
                dis[j]=dis[p]+1;//p->j，所以j距离+1
            }
        }
    }
}



int main(){
    cin >>n >> m;
    memset(h,-1,sizeof h); //初始化h
    while (m--){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    bfs(1);
    cout << dis[n];
    return 0;
}