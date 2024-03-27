// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

// 输入：nums = [3,4,-1,1]
// 输出：2

#include<iostream>
#include<vector>
using namespace std;

//原地哈希
//让nums[i]=i+1，然后遍历遇到第一个不符合条件的就是，如果没有，就返回n+1
int firstMissingPositive(vector<int>& nums){
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while(nums[i]!=i+1 && nums[i]-1>=0 && nums[i]-1<n && nums[i]!=nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i]!=i+1)
        {
            return i+1;
        }
    }
    return n+1;
}