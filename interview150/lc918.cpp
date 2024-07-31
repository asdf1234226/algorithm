//给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
// 输入：nums = [5,-3,5]
// 输出：10
// 解释：从子数组 [5,5] 得到最大和 5 + 5 = 10

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


//lc53变形题
//最开始的思路是类似lc53，用两个数组拼接模拟环形数组，并且连续子数组长度不能超过原数组长度n
//存在问题：[5,-3,5]模拟一下，发现数组拼接后的和原问题不等价
int maxSubarraySumCircular_err(vector<int>& nums){
    int osize = nums.size();
    for(int i=0;i<osize;i++){
        nums.push_back(nums[i]);
    }
    int n = nums.size();
    int ans = nums[0];
    vector<vector<int>> dp(n, vector<int>(2,0));
    dp[0][0]=nums[0], dp[0][1]=0;
    for(int i=1;i<n;i++){
        if(dp[i-1][0]>0){
            if(i-dp[i-1][1]+1<=osize){
                dp[i][0]=dp[i-1][0]+nums[i];
                dp[i][1]=dp[i-1][1];
            }
            else{
                //超过原数组长度，不许再加
                dp[i][0]-=nums[dp[i-1][1]];
                dp[i][1]=dp[i-1][1]+1;
            }
        }else{
            dp[i][0]=nums[i];
            dp[i][1]=i;
        }
        ans=max(ans,dp[i][0]);
    }
    return ans;
}

//正确思路：分情况讨论
//子数组在nums中间，计算的是lc53同款maxS
//子数组会跨过边界，子数组和+其余元素和=sum（常数），  其他元素是nums中间，所以转换为其他元素最小值minS
//结果就是max{maxS, sum-minS}
int maxSubarraySumCircular(vector<int>& nums){
    int n = nums.size();
    vector<int> dp_max(n,0);
    dp_max[0]=nums[0];
    vector<int> dp_min(n,0);
    dp_min[0]=nums[0];
    int maxS = dp_max[0], minS = dp_min[0], sum =nums[0];
    for(int i=1;i<n;i++){
        sum+=nums[i];
        dp_max[i]=max(dp_max[i-1],0)+nums[i];
        maxS = max(maxS, dp_max[i]);
        dp_min[i]=min(dp_min[i-1],0)+nums[i];
        minS = min(minS, dp_min[i]);
    }
    //如果最小数组是整个数组，那么跨边界的最大子数组是空的===>这种不被允许，这种情况下要返回maxS
    if(minS==sum){
        return maxS;
    }
    return max(maxS, sum-minS);
}