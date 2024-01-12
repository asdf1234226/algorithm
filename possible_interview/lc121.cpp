
// 输入：[7,1,5,3,6,4]
// 输出：5
// 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，
// 最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


//note:  由于只能买卖一次，所以下面的要改
int maxProfit(vector<int>& prices) {
    // dp[i][0]  持有状态的最大利润   前一天持有 dp[i-1][0]；前一天未持有，买入 dp[i-1][1]-prices[i]-->改成-prices[i]
    // dp[i][1]  未持有状态的最大利润 前一天未持有 dp[i-1][1]，前一天持有，卖出 dp[i-1][0]+prices[i]
    int n = prices.size();
    vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(2,0));
    dp[0][0]=-prices[0];
    dp[0][1]=0;
    for(int i = 1;i<n;i++){
        dp[i][0]=max(dp[i-1][0], -prices[i]);//只能买卖一次
        //dp[i][0]=max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1]=max(dp[i-1][1], dp[i-1][0]+prices[i]);
    }
    return dp[n-1][1];
}

int main(){
    vector<int> a = {7,1,5,3,6,4};
    cout << maxProfit(a);
    return 0;
}