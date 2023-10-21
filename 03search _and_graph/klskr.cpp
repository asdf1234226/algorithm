//
// Created by SP on 2023/10/21.
//
//4 5
//1 2 1
//1 3 2
//1 4 3
//2 3 2
//3 4 4
//输出6
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int p[N];//保存并查集
int cnt;
int n,m;
int res;
struct Edge{
    int a;
    int b;
    int w;
    bool operator <(const Edge& other){  // 重载小于运算符，用于排序
        return w<other.w;
    }
} edges[N];

int find_p(int a){//并查集找祖宗节点
    if(p[a]!=a){
        p[a]= find_p(p[a]);
    }
    return p[a];
}
void klskr(){
    sort(edges,edges+m);//按边权排序
    for (int i = 0; i <m ; i++) {//尝试加入每条边
        int pa= find_p(edges[i].a);
        int pb= find_p(edges[i].b);
        if(pa!=pb){//a,b不在一个集合，可以加入这条边
            p[pa]=pb;
            res+=edges[i].w;
            cnt++;
        }
    }

}

int main(){
    cin >>n >> m;
    for (int i = 1; i <=n ; i++) {//初始化并查集
        p[i]=i;
    }
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        edges[i]={a,b,c};
    }
    klskr();
    if (cnt<n-1){//加入的边<n-1，不能连通
        cout << "impossible";
    } else{
        cout << res;
    }
    return 0;
}