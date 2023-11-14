//
// Created by SP on 2023/11/11.
//

//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    //完全背包
    int f[amount+1];
    memset(f, 0x3f, sizeof f);
    f[0]=0;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j<= amount; j++)
        {
            f[j]=min(f[j], f[j-coins[i]]+1);
        }  
    }
    return f[amount]==0x3f3f3f3f?-1:f[amount];
}


int main(){
    vector<int> a ={1,2,5};
    cout << coinChange(a,11);
    return 0;
}