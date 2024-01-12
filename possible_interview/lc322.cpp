
// 输入：coins = [1, 2, 5], amount = 11
// 输出：3 
// 解释：11 = 5 + 5 + 1

#include<iostream>
#include<vector>
using namespace std;

//完全背包最小价值
// 物品体积 coins[i]  价值 1
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,0x3f3f3f3f);
    dp[0]=0;
    for(int i=0;i<coins.size(); i++){
        for(int j = coins[i];j<=amount;j++){
            dp[j]=min(dp[j-coins[i]]+1, dp[j]);//拿不拿
        }
    }
    return dp[amount];
}

int main(){
    vector<int> a ={1,2,5};
    cout << coinChange(a,11);
    return 0;
}