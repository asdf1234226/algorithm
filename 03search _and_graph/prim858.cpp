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
#include<cstring>
using namespace std;
const int N = 510;
int g[N][N]; //存边
int dist[N]; //存到连通图的距离
bool st[N];//是否被加入生成树
int pre[N];//记录前驱节点
int n, m;

void prim(){
    int res=0;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for (int i = 0; i < n; i++) {//n次循环，每次选出一个点t加入生成树
        int t=-1;
        for (int j = 1; j <=n ; j++) {
            if(!st[j] && (t==-1 || dist[t]>dist[j])){
                t=j;
            }
        }
        if (dist[t]==0x3f3f3f3f){
            cout << "impossible";
            return;
        }
        st[t]= true;
        res+=dist[t];
        for (int j = 1; j <=n ; ++j) { //用t更新生成树外点到生成树距离
            if (!st[j] && (dist[j]>g[t][j])){//t已经加入生成树，所以j到生成树距离是两者较小值
                dist[j]=g[t][j];
                pre[j]=t; //********j的前驱节点变成t
            }
        }
    }
    cout << "res: " <<res << endl;
}

void getPath(){
    for (int i=n;i>1;i--){//n-1条边
        cout << i <<" " << pre[i] << " "<< endl;
    }
}

int main(){
    cin >>n >> m;
    memset(g,0x3f,sizeof g);
    while (m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c); //重边
    }
    prim();
    getPath();
    return 0;
}