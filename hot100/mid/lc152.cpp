//
// Created by SP on 2023/11/12.
//

//找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积
//要求连续
//输入: nums = [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//dp[i]以 i 下标结尾的最大乘积
//dp[i]由两种情况转移而来   a.如果dp[i-1]乘第i个数 >  dp[i-1]，则更新dp[i]
//                       b.如果不是   dp[i]=第i个数

//enhance
//因为有负数，两个负数的乘积也可能是很大的正数，所以还要维护"最小子数组和"
//[-2,3,-4]
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int dp_max[n];
    int dp_min[n];
    memset(dp_max,-0x3f,sizeof dp_max);
    memset(dp_min,0x3f,sizeof dp_min);
    dp_max[0]=nums[0];
    dp_min[0]=nums[0];
    for (int i = 1; i < n; ++i) {
        dp_max[i]=max(dp_min[i-1]*nums[i],max(dp_max[i-1]*nums[i], nums[i]));
        dp_min[i]=min(dp_max[i-1]*nums[i], min(dp_min[i-1]*nums[i], nums[i]));
    }
    int ans = -0x3f3f3f3f;
    for (int i = 0; i <n ; ++i) {
        ans = max(ans,dp_max[i]);
    }
    return ans;
}

int main(){
    vector<int> a = {-2,3,-4};
    cout << maxProduct(a);
    return 0;
}