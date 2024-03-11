// 找出该数组中满足其总和大于等于 target 的长度最小的 连续
// 子数组
//  [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//  输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组

#include<iostream>
#include<vector>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int start = 0;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        while()
    }

}