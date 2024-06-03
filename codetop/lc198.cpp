// 输入：[2,7,9,3,1]
// 输出：12
// 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。

//不能偷相邻的

#include<iostream>
#include<vector>
using namespace std;
// 偷   dp[i]=nums[i]+dp[i-2]
// 不偷 dp[i]=dp[i-1]
int rob(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
    }
    return dp[n-1];
}

int main(){
    return 0;
}