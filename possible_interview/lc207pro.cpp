// 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
// 输出：false
// 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，
// 你还应先完成课程 1 。这是不可能的。

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 5010;  ////N要比边数多
int degree[N];//记录每个点入度
int e[N], ne[N], h[N];
int idx;

void add(int a, int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    memset(h,-1,sizeof h);//记得初始化
    for(auto item: prerequisites){
        degree[item[1]]++;
        add(item[0], item[1]);
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++){//入度为0的入队
        if(degree[i]==0){
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty())
    {
        // for(int i=0;i<q.size();i++){
        int index = q.front();
        q.pop();
        res.push_back(index);
        for(int i=h[index];i!=-1; i=ne[i]){//遍历index开头的链
            degree[e[i]]--;
            if (degree[e[i]]==0)
            {
                q.push(e[i]);
            }
        }
        //}
    }
    // for (int i = 0; i < 2; ++i) {
    //     cout << res[i] << " ";
    // }
    return res.size()==numCourses;
}

int main(){
    vector<vector<int>> prerequisites;
    prerequisites.push_back(vector<int>{1,0});
    if (canFinish(2,prerequisites)){
        cout << "yes";
    }

    return 0;

}