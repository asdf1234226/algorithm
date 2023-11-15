
// 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
// nums = [1, 2, 3]
// target = 4
// 所有可能的组合为： (1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (1, 3) (2, 1, 1) (2, 2) (3, 1)

// 请注意，顺序不同的序列被视作不同的组合

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//完全背包求排列数
int combinationSum4(vector<int>& nums, int target){
    int n = nums.size();
    int dp[target+1];
    memset(dp,0, sizeof dp);
    dp[0]=1;
    //外层循环容量，内层循环物品，求排列数
    for (int j = 0; j <= target; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j>=nums[i])
            {
                dp[j]+=dp[j-nums[i]];
            } 
        }
    } //对每个容量，都可以选择不同的coins[i]
    return dp[target];
}

int main(){
    vector<int> a = {1, 2, 3};
    cout << combinationSum4(a,4);
    return 0;
}




// for (int i = 0; i < coins.size(); i++) { // 遍历物品
//     for (int j = coins[i]; j <= amount; j++) { // 遍历背包容量
//         dp[j] += dp[j - coins[i]];
//     }
// }
// 假设：coins[0] = 1，coins[1] = 5。
// 首先考虑面值为1的硬币，然后考虑所有可能的数量，从而得到所有可能的金额组合。
// 然后，再考虑面值为5的硬币，再次得到所有可能的金额组合。
// 首先考虑了面值为1的硬币，然后才考虑面值为5的硬币，所以我们不会考虑先使用5再使用1的情况

// for (int j = 0; j <= amount; j++) { // 遍历背包容量
//     for (int i = 0; i < coins.size(); i++) { // 遍历物品
//         if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
//     }
// }
// 背包容量的每一个值，都是经过 1 和 5 的计算，包含了{1, 5} 和 {5, 1}两种情况。

// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。