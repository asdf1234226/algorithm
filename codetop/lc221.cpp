//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//输出：4

#include <iostream>
#include <vector>
using namespace std;

//TODO  一点记不起来了
//dp[i][j]以(i,j)为下标的最大正方形的边长
//dp[i][j]=min{dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}+1
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    int ans =0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j]=='0')
            {
                dp[i][j]=0;
            }else
            {
                if (i==0 || j==0)
                {
                    dp[i][j]=1;
                }else
                {
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]))+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
    }
    return ans*ans;
    
}