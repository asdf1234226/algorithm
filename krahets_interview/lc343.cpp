//
// Created by SP on 2023/12/21.
//

// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
// 返回 你可以获得的最大乘积 。
// 输入: n = 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

#include<iostream>
#include<vector>
using namespace std;

int integerBreak(int n){
    vector<int> dp(n+1,0);
    dp[2]=1;
    for(int i=3;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i]=max(dp[i], max(dp[j]*(i-j),j*(i-j)));
            // j*(i-j)对应拆分两个数； 
            //dp[j]*(i-j)对应拆分成三个及以上的数，因为dp[j]就对应了两个及以上，再加上(i-j)就是三个及以上
        }
    }

}

int main(){
    cout << integerBreak(10);
    return 0;
}