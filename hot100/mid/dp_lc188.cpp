
//最多完成k次交易

// 输入：k = 2, prices = [3,2,6,5,0,3]
// 输出：7 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 
// 这笔交易所能获得利润 = 6-2 = 4。随后，在第 5 天 (股票价格 = 0) 的时候买入，
// 在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//最多两次的情况
// dp[i][0] = max(dp[i-1][0], -prices[i]);
// dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
// dp[i][2] = max(dp[i-1][2], dp[i-1][1]-prices[i]);
// dp[i][3] = max(dp[i-1][3], dp[i-1][2]+prices[i]);

int maxProfit(int k, vector<int>& prices){
    int n = prices.size();
    int dp[n][2*k];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < k; i++)
    {
        dp[0][2*i] = -prices[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 2*k; j++)
        {
            if(j==0){
                dp[i][j] = max(dp[i-1][0], -prices[i]);
            }else if (j%2==1)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+prices[i]);
            }else//j%2==0
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]-prices[i]);
            }
        }  
    }
    return dp[n-1][2*k-1];
}

int main(){
    vector<int> a = {3,3,5,0,0,3,1,4};
    cout << maxProfit(2, a);
    return 0;
}