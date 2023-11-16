
// 最多可以完成 两笔 交易。

// 输入：prices = [3,3,5,0,0,3,1,4]
// 输出：6 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，
// 这笔交易所能获得利润 = 3-0 = 3 。随后，在第 7 天（股票价格 = 1）的时候买入，
// 在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//第 i 天持有或不持有，因为有两次操作
// 第一次持有       0  买入
// 第一次不持有     1 卖出
// 第二次持有       2  买入
// 第二次不持有     3  卖出

// dp[i][0]  a. 之前就有dp[i-1][0];  b. 今天买入-prices[i]
// dp[i][1]  a. 之前就没有dp[i-1][1]; b.今天卖出 dp[i-1][0]+prices[i]
// dp[i][2]  a. 之前就有dp[i-1][2]; b. 今天第二次买入，要算上第一次利润 dp[i-1][1]-prices[i]
// dp[i][3]  a. 之前就没有dp[i-1][3]; b.今天第二次卖出 dp[i-1][2]+prices[i]
 
                                                               

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp[n+1][4];
    memset(dp,0,sizeof dp);
    dp[0][0]=-prices[0];
    dp[0][1]=0;
    dp[0][2]=-prices[0];//第0天先买再卖，完成第一次，再第二次买
    dp[0][3]=0;
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = max(dp[i-1][0], -prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
        dp[i][2] = max(dp[i-1][2], dp[i-1][1]-prices[i]);
        dp[i][3] = max(dp[i-1][3], dp[i-1][2]+prices[i]);
    }
    return dp[n-1][3];
}



int main(){
    vector<int> a = {3,3,5,0,0,3,1,4};
    cout << maxProfit(a);
    return 0;
}