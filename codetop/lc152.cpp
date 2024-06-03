// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数
// 组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积
// 。  测试用例的答案是一个 32-位 整数。  
// 子数组 是数组的连续子序列。

// 输入: nums = [2,3,-2,4] 输出: 6 
// 解释: 子数组 [2,3] 有最大乘积 6。

#include<iostream>
#include<climits>
#include<vector>
using namespace std;
// dp[i]以nums[i]为结尾的最大
// dp[i] = max(dp[i-1]*nums[i], nums[i], dp_min[i-1]*nums[i])
//如果只有正数，可以这么算，如果有负数，还要同时维护负数

int maxProduct(vector<int>& nums){
    int n = nums.size();
    vector<int> dp_max(n,INT_MIN);
    vector<int> dp_min(n,INT_MAX);
    dp_max[0]=nums[0];
    dp_min[0]=nums[0];
    for (int i = 1; i < n; i++)
    {
        dp_max[i] = max(dp_max[i-1]*nums[i],max(nums[i], dp_min[i-1]*nums[i]));
        dp_min[i] = min(dp_min[i-1]*nums[i], min(nums[i], dp_max[i-1]*nums[i]));
    }
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        ans=max(ans, dp_max[i]);
    }
    return ans;
}

int main(){
    vector<int> a = {2,3,-2,4};
    cout << maxProduct(a);
    return 0;
}