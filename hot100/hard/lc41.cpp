// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案

// 输入：nums = [3,4,-1,1]
// 输出：2

#include<iostream>
#include<vector>
using namespace std;


//原地哈希
//1. 保证 1 出现在 nums[0] 的位置上，2 出现在 nums[1] 的位置上，…，
//n 出现在 nums[n - 1] 的位置上。不在 [1, n] 范围内的数不用动。[3,4,-1,1] 将会被预处理成 [1,-1,3,4]

//2.遍历 nums，找到第一个不在应在位置上的 [1, n] 的数。如果没有找到，说明数据连续，答案为 n + 1


int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i =0;i<n;i++){
        //为什么用while，数组为[3, 4, 2, 1]，在i=0时，3和2会被交换，得到[2, 4, 3, 1]，2也要放到正确的位置
        //用[3,4,-1,1]模拟，i=0时[-1,4,3,1]，i=1时[-1,1,3,4]---还要再交换一次[1,-1,3,4]
        while (nums[i]>=1&&nums[i]<=n && nums[i]!=i+1 && nums[i]!=nums[nums[i]-1])//如果nums[i]在[1,n]范围内，且不在应该放的位置
        {
            swap(nums[i], nums[nums[i]-1]);
        }
    }
    //所有1~n的数都放在应该放的位置，找出第一个不符合条件的数
    for (int i = 0; i < n; i++)
    {
        if (nums[i]!=i+1)
        {
            return i+1;
        }
        
    }
    return n+1;
}

int main(){
    vector<int> a = {3,1,3,4,2};
    cout << firstMissingPositive(a);
    return 0;
}

