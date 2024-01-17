// 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
// 输出：false
// 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，
// 你还应先完成课程 1 。这是不可能的。

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 2010;
int degree[N];
//TODO   这个忘了应该用入度来做了
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for(auto item: prerequisites){
        degree[item[1]]++;
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
        for(auto it: prerequisites){
            if (it[0]==index)
            {
                degree[it[1]]--;
                if (degree[it[1]]==0)
                {
                    q.push(it[1]);
                }
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
    prerequisites.push_back(vector<int>{0,1});
//    prerequisites.push_back(vector<int>{3,1});
//    prerequisites.push_back(vector<int>{3,2});
    if (canFinish(2,prerequisites)){
        cout << "yes";
    }

    return 0;

}