

// 无限次地完成交易,但是每次有手续费
// 输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
// 输出: 8

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//持有 dp[i][0]   前一天持有，今天不操作；前一天不持有，今天买
//不持有 dp[i][1] 前一天不持有，今天不操作； 前一天持有，今天卖
int maxProfit(vector<int>& prices, int fee)
{
    int n = prices.size();
    int dp[n][2];
    memset(dp,0,sizeof dp);
    dp[0][0]=-prices[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]-fee);//卖出时多了手续费
    }
    return max(dp[n-1][0], dp[n-1][1]);//理论上不持有会更多利润，但是有了手续费
}

int main(){
    vector<int> a = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(a,2);
    return 0;
}