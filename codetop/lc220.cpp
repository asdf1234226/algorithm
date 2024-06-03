// 在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，
// 且满足 i 和 j 的差的绝对值也小于等于 ķ 。
// 如果存在则返回 true，不存在返回 false。

// 示例 1:
// 输入: nums = [1,2,3,1], k = 3, t = 0
// 输出: true

// 示例 2:
// 输入: nums = [1,0,1,1], k = 1, t = 2
// 输出: true

// 示例 3:
// 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
// 输出: false


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// 桶哈希， 数据分到M个桶，每个桶之间任意两个数字的差值不会超过t
// 所以应该是nums[i]/(t+1)，余数0~t, 所以在一个桶内一定差值在t内；在相邻的桶也可能
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
    int n = nums.size();
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int index = nums[i]/(t+1);
        //在同一个桶中
        if(mp.find(index)!=mp.end()){
            return true;
        }
        //相邻桶，并且差值要<=t
        if (mp.find(index-1)!=mp.end() && abs(nums[i]-mp[index-1])<=t)
        {
            return true;
        }
        if (mp.find(index+1)!=mp.end() && abs(nums[i]-mp[index+1])<=t){
            return true;
        }
        mp[index]=nums[i];
        //维护大小为k的窗口，清除过期的
        if (i>=k)
        {
            int pos = nums[i-k]/(t+1);
            // -1/5=0, 3/5=0，为了区分不同桶，要将-1放在更小的桶中
            if (nums[i-k]<0)
            {
                pos--;
                mp.erase(pos);
            }
            
        }
    }
    return false;
}

int main(){
    return 0;
}