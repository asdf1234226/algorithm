// 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格
// 可以多次交易，但卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

// 输入: [1,2,3,0,2]
// 输出: 3
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

// 持有股票的最大利润    dp[i][0]
// 不持有股票的最大利润
//      a. 今天卖出                    dp[i][1]
//      b. 保持卖出股票的状态（两天前就卖出了股票，度过一天冷冻期。或者是前一天就是卖出股票状态，一直没操作）  dp[i][2]
//      c. 今天是冷冻期（前一天卖过）  dp[i][3]

// dp[i][0]由 前一天就持有， 前一天冷冻期（今天买） 前一天保持卖出股票（今天买） 转移而来  
//  max(dp[i-1][0], dp[i-1][3]-prices[i], dp[i-1][2]-prices[i])
// dp[i][1]由 前一天持有（今天卖） 转移而来  dp[i-1][0]+prices[i]
// dp[i][2] 由 前一天还是保持卖出， 前一天是冷冻期 转移而来 dp[i-1][2], dp[i-1][3]
// dp[i][3] 由 前一天卖出转移,今天没操作     dp[i-1][1]

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    int dp[n][4];
    memset(dp,0,sizeof dp);
    dp[0][0]=-prices[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0]=max(max(dp[i-1][0], dp[i-1][3]-prices[i]), dp[i-1][2]-prices[i]);
        dp[i][1]=dp[i-1][0]+prices[i];
        dp[i][2]=max(dp[i-1][2], dp[i-1][3]);
        dp[i][3]=dp[i-1][1];
    }
    return max(max(dp[n-1][1], dp[n-1][2]),dp[n-1][3]); //不持有的最大利润
}

int main(){
    vector<int> a = {1,2,3,0,2};
    cout << maxProfit(a);
    return 0;
}