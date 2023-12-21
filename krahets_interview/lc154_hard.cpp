//
// Created by SP on 2023/12/14.
//

// 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
// 若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
// 若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
// 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

// 给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

// 你必须尽可能减少整个过程的操作步骤。

// 示例 1：
// 输入：nums = [1,3,5]
// 输出：1
// 示例 2：
// 输入：nums = [2,2,2,0,1]
// 输出：0

#include<iostream>
#include<vector>
using namespace std;

//找旋转点
//前半段满足>=nums[0]，后半段满足<=nums[0](如果旋转点值就是nums[0]可能会出现这种情况，如[2,2,0,1,2])
//需要去掉后半段==nums[0]的属性，恢复二段性
int findMin(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    int l=0, r=n-1;
    while (r>=0&&nums[r]==nums[0]){
        r--;
    }
    if(r==-1){
        return nums[0];
    }
    //寻找旋转点
    while(l<r){
        int mid = (l+r+1)>>1;
        if(nums[mid]>=nums[0]){
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    int index = l==n-1?0:l+1;//应该返回nums[l+1],但是l=n-1时会数组越界，需要返回0
    return nums[index];
}

int main(){
    vector<int> a = {1,3,5};
    cout << findMin(a);
    return 0;
}