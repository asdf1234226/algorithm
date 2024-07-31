// 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，
// 其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。

// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了
// 如果不可能完成所有课程，返回 一个空数组 。

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//入度，先遍历所有边，计算点的入度
//将入度为0的入队
//出队，并且遍历这个点出发的所有边，将
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<int> degree(numCourses,0);
    for (auto it: prerequisites)
    {
        degree[it[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (degree[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        ans.push_back(val);
        for(auto it: prerequisites){
            if (it[0]==val)
            {
                degree[it[1]]--;
            }
            if (degree[it[1]]==0)
            {
                q.push(it[1]);
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}