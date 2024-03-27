// 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

// 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 
// 子字符串
// ：
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...

// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出：true
// 示例 2：

// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出：false

#include<iostream>
#include<vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int n1=s1.size(),n2=s2.size(),n3=s3.size();
    if(n1+n2!=n3) return false;
    //s1的前i个和s2的前j个可以交错成s3的前i+j个
    //s3[i+j-1]==s[i-1]时， dp[i][j]=dp[i-1][j]
    //s3[i+j-1]==s[j-1]时   dp[i][j]=dp[i][j-1] 上面两种任意一个为true,dp[i][j]就是true
    vector<vector<bool>> dp = vector<vector<bool>>(n1+1, vector<bool>(n2+1));
    dp[0][0]=true;
    for (int i = 1; i <= n1&&s1[i-1]==s3[i-1]; i++)
    {
        dp[i][0]=true;//不相同直接终止
    }
    for (int j = 1; j <= n2&&s2[j-1]==s3[j-1]; j++)
    {
        dp[0][j]=true;//不相同直接终止
    }
    for (int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++){
            if (s3[i+j-1]==s1[i-1])
            {
                dp[i][j]=dp[i][j]||dp[i-1][j];
            }
            if (s3[i+j-1]==s2[j-1])
            {
                dp[i][j]=dp[i][j]||dp[i][j-1];
            }
        }
    }
    return dp[n1][n2];
}

int main(){
    return 0;
}