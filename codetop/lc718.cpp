// 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度

// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// 输出：3
// 解释：长度最长的公共子数组是 [3, 2, 1] 。

//dp[i][j] A的前i个和B的前j个的最长长度
// A[i]==B[j]   dp[i][j]=dp[i-1][j-1]+1
//     !=               = 0  子数组要求连续

#include<iostream>
#include<vector>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    if(m==0 || n==0) return 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (nums1[i-1]==nums2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans, dp[i][j]);
            }else
            {
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}