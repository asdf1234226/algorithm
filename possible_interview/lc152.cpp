// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数
// 组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积
// 。  测试用例的答案是一个 32-位 整数。  
// 子数组 是数组的连续子序列。

// 输入: nums = [2,3,-2,4] 输出: 6 
// 解释: 子数组 [2,3] 有最大乘积 6。

#include<iostream>
#include<vector>
using namespace std;
int maxProduct(vector<int>& nums){
    //dp[i]=max(nums[i], dp[i-1]*nums[i])
    int n = nums.size();
    vector<int> dp(n,1);
    dp[0]=nums[0];
    int ans = -0x3f3f3f3f;
    for(int i=1;i<n;i++){
        dp[i]=max(nums[i],dp[i-1]*nums[i]);
    }
    for(int i=1;i<n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;

}

int main(){
    vector<int> a = {2,3,-2,4};
    cout << maxProduct(a);
    return 0;
}