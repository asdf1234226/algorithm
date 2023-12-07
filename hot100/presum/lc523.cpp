// 给定一个包含 非负数 的数组和一个目标 整数 k，编写一个函数来判断该数组是否含有
// 连续的子数组，其大小至少为 2，且总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

// 输入：[23,2,4,6,7], k = 6
// 输出：True
// 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6


#include<iostream>
#include<map>
#include<vector>
using namespace std;

//lc974的变形
//判断有没有，所以不需要计算数量；长度至少是2，所以存下标来计算长度
//如果之前有key=1的，现在又来了个key=1的，不需要更新下标，因为要尽可能保存较小的下标
int checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> mp;
    int preSum = 0;
    mp[0]=-1;//保存的是索引
    for (int i = 0; i < n; i++)
    {
        preSum+=nums[i];
        int key = preSum%k;
        if (mp.find(key)!=mp.end())
        {
            if (i-mp[key]>=2)
            {
                return true;
            }
            //不需要更新key的下标，因为要保存小的那个
        }else
        {
            mp[key]=i;//只有新加入的key才存下标
        }
    }
    return false;
}