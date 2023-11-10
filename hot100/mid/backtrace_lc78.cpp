//
// Created by SP on 2023/11/6.
//

//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集
//        输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//https://programmercarl.com/0078.%E5%AD%90%E9%9B%86.html#%E6%80%9D%E8%B7%AF
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> path;
vector<vector<int>> ans;

void dfs(vector<int>& nums, int start){
    if (start==nums.size()+1)
    {
        return;
    }
    ans.push_back(path);
    for (int i = start; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        dfs(nums, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    dfs(nums,0);
    return ans;
}


int main(){
    vector<int> a = {1,2,3};
    vector<vector<int>> res = subsets(a);
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

//*************错误的写法，四不像，将排列过程中每个path状态加入set去重
//*************没有用set去重放ans的写法，就算能实现，复杂度也过大）

// struct Compare{//set存vector需要定义Compare，为了计算vector对象的hash
//     bool operator()(const vector<int>& a, const vector<int>& b) const{
//         return a<b;
//     }
// };
// set<vector<int>, Compare> vec_set;
// void dfs(vector<int>& nums, int u){
//     if (u==nums.size())
//     {
//         return;
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (!visit[i])
//         {
//             visit[i]=true;
//             path.push_back(nums[i]);
//             sort(path.begin(),path.end());
//             vec_set.insert(path);
//             dfs(nums, u+1);
//             visit[i]=false;
//             path.pop_back();
//         }
//     }
    
// }

// vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> ans;
//     int n = nums.size();
//     vec_set.insert(vector<int>{});
//     vec_set.insert(nums);
//     dfs(nums, 0);
//     for (auto it: vec_set)
//     {
//         ans.push_back(it);
//     }
//     return ans;
// }