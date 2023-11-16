//
// Created by SP on 2023/11/15.
//


//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


//第 i 天的状态，要么持有股票，要么没有股票， dp[i][0]表示i天持有股票的最大利润， dp[i][1]表示没有股票的最大利润

// 1.对于 dp[i][0]（第i天结束时持有股票的最大利润），它可以由以下两种状态转移而来：
//       a. 前一天也持有股票，即 dp[i-1][0]。
//       b. 前一天没有股票，但是在第i天买入，即 -prices[i]。

// 2.对于 dp[i][1]（第i天结束时没有股票的最大利润），它可以由以下两种状态转移而来：
//       a. 前一天也没有股票，即 dp[i-1][1]。
//       b. 前一天持有股票，但是在第i天卖出，即 dp[i-1][0]+ prices[i]。


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp[n+1][2];
    memset(dp,0,sizeof dp);
    dp[0][0]=-prices[0];
    dp[0][1]=0;
    for (int i = 1; i < n; i++)
    {
        //当第i天买入股票的时候，所持有的现金没有之前的利润
        dp[i][0] = max(dp[i-1][0], -prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
    }
    return dp[n-1][1];//最后肯定是不持有股票利润更多
}



int main(){
    vector<int> a = {7,1,5,3,6,4};
    cout << maxProfit(a);
    return 0;
}