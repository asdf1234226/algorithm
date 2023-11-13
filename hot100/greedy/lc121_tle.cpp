//
// Created by SP on 2023/11/13.
//

//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票

#include<iostream>
#include<vector>
using namespace std;


int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i < n-1; ++i) {
        //i天买入能获取的最大利润
        int profit_i = 0;
        for (int j = i+1; j < n; ++j) {
            profit_i = max(profit_i, prices[j]-prices[i]);
        }
        ans = max(ans, profit_i);
    }
    return ans;
}


int main(){
    vector<int> a = {7,1,5,3,6,4};
    cout << maxProfit(a);
    return 0;
}