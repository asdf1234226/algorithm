//
// Created by SP on 2023/11/12.
//

//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//输入：[2,7,9,3,1]
//输出：12
//解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//偷窃到的最高金额 = 2 + 9 + 1 = 12 。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int rob(vector<int>& nums) {
    if (nums.size()==1)
    {
        return nums[0];
    }
    if (nums.size()==2)
    {
        return max(nums[0], nums[1]);
    }
    int n = nums.size();
    int dp[n+1];
    memset(dp,0,sizeof dp);
    // dp[i]中第i个房间，要么偷，要么不偷
    // 偷对应dp[i-2]+nums[i], 不偷对应dp[i-1]
    dp[0]=nums[0];
    dp[1]=max(dp[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[n-1];
}

int main(){
    vector<int> a = {2,7,9,3,1};
    cout << rob(a);
    return 0;
}