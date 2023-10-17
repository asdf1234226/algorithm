//
// Created by SP on 2023/10/17.
//
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 2010;
int pre[N][N]; //邻接矩阵
int degree[N]; //每个节点的入度
queue<int> q;
vector<int> ans;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    memset(pre,-1,sizeof pre);
    int n =numCourses;
    for (auto t: prerequisites) {
        pre[t[0]][t[1]]=1;
        degree[t[1]]+=1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        cout << "degree " << degree[i];
    }
    for (int i = 0; i < n; i++) {
        if (degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int p = q.front();
        q.pop();
        ans.push_back(p);
        for (int i = 0; i < n; i++) {
            if (pre[p][i]!=-1){//p可以到达的点
                degree[i]--;
                if(degree[i]==0){
                    q.push(i);
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    ans.reserve(n);
    return ans.size()==n;
}

int main(){
    vector<vector<int>> prerequisites;
    prerequisites.push_back(vector<int>{1,0});
//    prerequisites.push_back(vector<int>{2,0});
//    prerequisites.push_back(vector<int>{3,1});
//    prerequisites.push_back(vector<int>{3,2});
    if (canFinish(2,prerequisites)){
        cout << "yes";
    }
    cout << ans.size();
    for (int i = 0; i < 2; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}