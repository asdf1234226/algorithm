
// 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度

// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// 输出：3
// 解释：长度最长的公共子数组是 [3, 2, 1] 。


//**********区别LCS问题*************
//因为是连续子序列，所以可以定义为i个元素结尾
//dp[i][j]为 A的第i个元素结尾，B的第j个元素结尾的最长子数组长度
//A[i-1]==B[j-1]，长度+1， 不然为0
//dp[i][j]只和dp[i-1][j-1]有关，和dp[i][j-1],dp[i-1][j]无关，每次两边都要推进1


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int findLength(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof dp);
    dp[0][0]=0;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (nums1[i-1]==nums2[j-1])//如果A的第i个和B的第j个相同
            {
                dp[i][j]=dp[i-1][j-1]+1;
                ans = max(ans, dp[i][j]);
            }else
            {
                dp[i][j]=0;
            } 
        }
    }
    return ans;
}

int main(){
    vector<int> a = {1,2,3,2,1};
    vector<int> b = {3,2,1,4,7};
    cout << findLength(a,b);
    return 0;
}