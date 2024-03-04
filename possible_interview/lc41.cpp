// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

// 输入：nums = [3,4,-1,1]
// 输出：2
// 示例 3：

#include<iostream>
#include<vector>
using namespace std;

// 数组长度为N的话，[1,N]如果有缺失的x，就返回x； 如果没有缺失的，返回N+1
// 1放在下标0的位置，2放在下标1的位置，...即nums[0]=1, nums[1]=2
// 所有1~n的数都放在应该放的位置，找出第一个不符合条件的数
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        while (nums[i]>=1 && nums[i]<=n && nums[i] != i+1 && nums[i]!=nums[nums[i]-1])
        {
            swap(nums[i], nums[nums[i]-1]);
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]!=i+1){
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
