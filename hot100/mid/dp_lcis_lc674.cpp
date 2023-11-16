
// 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度
// 输入：nums = [1,3,5,4,7]
// 输出：3  //[1,3,5]

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//dp[i] 以i结尾的最长连续递增子序列长度
int findLengthOfLCIS(vector<int>& nums){
    int n = nums.size();
    int dp[n+1];
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for (int i = 1; i < n; i++)
    {
        if(nums[i]>nums[i-1]){
            dp[i]=dp[i-1]+1;
        }else
        {
            dp[i]=1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans=max(ans, dp[i]);
    }
    return ans;
}

int main(){
    vector<int> a = {1,3,5,4,7};
    cout << findLengthOfLCIS(a);
    return 0;
}