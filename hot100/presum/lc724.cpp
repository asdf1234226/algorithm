// 给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。
// 我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
// 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

// nums = [1, 7, 3, 6, 5, 6]
// 输出：3

#include <iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> preSum(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        preSum[i]=preSum[i-1]+nums[i-1];
    }
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        // i左边下标是i-1，下标i-1是第i个数，所以preSum[i]
        if (preSum[n]-preSum[i]-nums[i]==preSum[i])
        {
            index=i;
            break;
        }
    }
    return index;
    
}

int main(){
    vector<int> a = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(a);
    return 0;
}