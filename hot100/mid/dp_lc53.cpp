

// 请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


//连续子数组，所以定义dp[i]是以第i个元素为结尾的最大和
//dp[i]只能从dp[i-1]转移而来，或者第i个数作为新的开始
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int dp[n+1];
    memset(dp, -0x3f, sizeof dp);
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        dp[i]=max(dp[i-1]+nums[i-1], nums[i-1]);//第i个数下标i-1
        ans=max(ans, dp[i]);
    }
    return ans;
    
}


int main(){
    vector<int> a ={-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(a);
    return 0;
}