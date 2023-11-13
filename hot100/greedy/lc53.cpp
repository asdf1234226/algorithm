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
    if(nums.size()==1){
        return nums[0];
    }
    int subSum = nums[0];
    int max_item = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        max_item=max(nums[i], max_item);
        if (subSum>=0)
        {
            subSum+=nums[i];
            ans=max(subSum, ans);
        }
        else//前面“连续和”为负数的时候立刻放弃，从当前元素重新计算“连续和”，因为负数加上当前元素 “连续和”只会越来越小
        {
            subSum=nums[i];
        }
        if(i==nums.size()-1){//如果subSum刚好是最后一个元素，需要和ans比较
            ans = max(ans, subSum);
        }
    }
    return max(max_item, max(ans, subSum));
    //还有全是负数的情况
}


int main(){
    vector<int> a ={-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(a);
    return 0;
}