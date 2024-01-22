// 输入：text1 = "abcde", text2 = "ace" 
// 输出：3  
// 解释：最长公共子序列是 "ace" ，它的长度为 3 。

#include<iostream>
#include<vector>
using namespace std;

//dp[i][j]text1的前i个和test2的前j个的LCS长度
// text1[i-1] == test2[j-1]  dp[i][j]=dp[i-1][j-1]+1;
// text1[i-1] != test2[j-1]  dp[i][j]=max(dp[i-1][j],dp[i][j-1])
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n=text2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i-1]==text2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }   
        }
    }
    return dp[m][n];
}

int main(){
    cout << longestCommonSubsequence("abcde","ace");
    return 0;
}