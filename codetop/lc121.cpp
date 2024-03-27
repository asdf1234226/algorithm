// 输入：[7,1,5,3,6,4]
// 输出：5
// 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，
// 最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

//TODO  不熟悉

#include<iostream>
#include<vector>
using namespace std;

// dp[i][0]  持有股票的最大利润  dp[i][0]=max(dp[i-1][0], -prices[i])  //note 只能买卖一次
// dp[i][1]  没持有              dp[i][1]=max(dp[i-1][1], dp[i-1][0]+prices[i])
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2,0));
    dp[0][0]=-prices[0];
    dp[0][1]=0;
    for (int i = 1; i < n; i++)
    {
        dp[i][0]=max(dp[i-1][0], -prices[i]);
        dp[i][1]=max(dp[i-1][1], dp[i-1][0]+prices[i]);
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

int main(){
    vector<int> a = {7,1,5,3,6,4};
    cout << maxProfit(a);
    return 0;
}