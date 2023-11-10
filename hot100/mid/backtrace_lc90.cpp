//
// Created by SP on 2023/11/8.
//

//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> path;
vector<vector<int>> ans;
bool used[1010];

void dfs(vector<int>& nums, int start){
    ans.push_back(path);
    for (int i = start; i < nums.size(); i++)
    {
        if (i>0 && nums[i]==nums[i-1] && !used[i-1])
        {
            continue;
        }
        used[i]=true;
        path.push_back(nums[i]);
        dfs(nums, i+1);
        path.pop_back();
        used[i]=false;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    dfs(nums, 0);
    return ans;
}


int main(){
    vector<int> a = {1,2,2};
    vector<vector<int>> res = subsetsWithDup(a);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << res.size();
}