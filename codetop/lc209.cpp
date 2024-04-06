#include<iostream>
#include<vector>
using namespace std;
// 找出该数组中满足其总和大于等于 target 的长度最小的 连续
// 子数组
//  [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 
// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int start = 0;
    int sum = 0;
    int minlen = 0x3f3f3f;
    for(int end=0;end<n;end++){
        sum+=nums[end];
        while (sum>=target)
        {
            minlen=min(minlen,end-start+1);
            sum-=nums[start];
            start++;
        }
    }
    return minlen==0x3f3f3f3f?0:minlen;
}

int main(){
    vector<int> a = {2,3,1,2,4,3};
    cout << minSubArrayLen(7,a);
    return 0;
}