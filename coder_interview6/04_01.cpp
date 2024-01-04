// 节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

// 示例1:
//  输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
//  输出：true
// 示例2:

//  输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], 
//  [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
//  输出 true


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e6+10;
int idx = 0;
int e[N], ne[N], h[N];//单向边，链表的数组写法
bool vis[N];

//头插法
void add(int a, int b){
    e[idx]=b; //e[]存储值
    ne[idx]=h[a];//ne相当于存储next指针
    h[a]=idx;//更新head为头节点
    idx++;
}

bool dfs(int start, int target){
    bool canReach =false;
    for (int i = h[start]; i !=-1; i=ne[i])//遍历从start出发的边
    {
        int j = e[i];
        if (vis[j])
        {
            continue;
        }
        vis[j]=true;
        if (j==target)
        {
            return true;
        }
        canReach |= dfs(j,target);
    }
    return canReach;
}
bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    memset(h,-1,sizeof h); //初始化链表指向-1（相当于nullptr）
    for(auto it: graph){//存图
        add(it[0],it[1]);
    }
    return dfs(start, target);
}


int main(){
    vector<vector<int>> a = {{0, 1}, {1, 2}, {1, 3}, {1, 10}, {1, 11}, {1, 4}, {2, 4}, {2, 6}, {2, 9}, {2, 10}, {2, 4}, {2, 5}, {2, 10}, {3, 7},{3, 7}, {4, 5}, {4, 11}, {4, 11}, {4, 10}, {5, 7}, {5, 10}, {6, 8},{7, 11}, {8, 10}};
    //vector<vector<int>> a = {{0, 1}, {0, 2}, {0, 4}, {0, 4}, {0, 1}, {1, 3},{1, 4}, {1, 3}, {2, 3}, {3, 4}};
    if (findWhetherExistsPath(12,a,2,3))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }
    return 0;
}