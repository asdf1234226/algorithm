// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')

#include<iostream>
#include<vector>
using namespace std;

//dp[i][j]表示word1的前i个和word2的前j个的最小距离
//            word1[i-1]==word2[j-1]  dp[i][j]=dp[i-1][j-1]
//                      !=            删除 dp[i][j]=dp[i-1][j]+1;
//                                    替换 dp[i][j]=dp[i-1][j-1]+1;
//                                    插入 dp[i][j]=dp[i][j-1]+1;
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <= m; i++)
    {
        dp[i][0]=i;
    }
    for (int j = 1; j <= n; j++)
    {
        dp[0][j]=j;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1;  j<=n; j++)
        {
            if (word1[i-1]==word2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }else
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
        }
    }
    return dp[m][n];
}

int main(){
    cout << minDistance("horse", "ros");
    return 0;
}