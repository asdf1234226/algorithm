//
// Created by SP on 2023/11/8.
//

//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;
bool vis[1010];

void dfs(vector<int>& nums, int u)
{
    if (path.size()==nums.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            vis[i]=true;
            path.push_back(nums[i]);
            dfs(nums, u+1);
            path.pop_back();
            vis[i]=false;
        } 
    }
}

vector<vector<int>> permute(vector<int>& nums){
    dfs(nums,0);
    return ans;
}

void print_v(vector<vector<int>>& a){
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    } 
}

int main(){
    vector<int> a ={1,2,3};
    vector<vector<int>> res = permute(a);
    print_v(res);
    return 0;
}