// 请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

#include<iostream>
#include<vector>
using namespace std;

//dp[i]是i下标结尾的最大和
//dp[i]=max(nums[i], dp[i-1]+nums[i])
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    int ans=nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i]=max(dp[i-1]+nums[i], nums[i]);
        ans=max(ans, dp[i]);
    }    
    return ans;
}

int main(){
    vector<int> a ={-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(a);
    return 0;
}