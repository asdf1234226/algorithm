#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 2010;
queue<int> q;
vector<int> ans;



bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{   
    int degree[numCourses];
    memset(degree,0,sizeof degree);
    for (auto item: prerequisites)
    {
        degree[item[1]]++;
    }
    for (int i = 0; i < numCourses; i++)
    {
        if(degree[i]==0){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto& it: prerequisites)
        {
            if (it[0]==front)
            {
                degree[it[1]]--;
                if (degree[it[1]]==0)
                {
                    q.push(it[1]);
                }  
            }

        } 
    }
    return ans.size()==numCourses;
    
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
    for (int i = 0; i < 2; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}