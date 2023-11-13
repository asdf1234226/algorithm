//
// Created by SP on 2023/11/12.
//

// 请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans = -0x3f3f3f3f;
    int subSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (subSum>=0)
        {
            subSum+=nums[i];
            ans=max(subSum, ans);
        }
        else//前面“连续和”为负数的时候立刻放弃，从当前元素重新计算“连续和”，因为负数加上当前元素 “连续和”只会越来越小
        {
            subSum=nums[i];
        } 
    }
    return ans;
}


int main(){
    vector<int> a ={-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(a);
    return 0;
}