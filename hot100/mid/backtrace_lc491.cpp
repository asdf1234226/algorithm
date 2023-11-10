//
// Created by SP on 2023/11/8.
//

//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
//数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况
//
//输入：nums = [4,6,7,7]
//输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;
bool used[1010];


void dfs(vector<int> nums, int start){
    if (path.size()>=2)
    {
        ans.push_back(path);
    }
    for (int i = start; i < nums.size(); i++)
    {
        if (i>0 && nums[i]==nums[i-1] && used[i-1]==false)//去重同一树层
        {
            continue;
        }
        if (path.size()==0 || path.size()>=1 && nums[i]>=path[path.size()-1])
        //只有nums[i]作为第一个元素  或  nums[i]>=上一个加入的元素时，才会将nums[i]放入path
        {
            used[i]=true;
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
            used[i]=false;
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
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
    vector<int> a = {4,6,7,7};
    vector<vector<int>> res = findSubsequences(a);
    print_v(res);
    return 0;
}