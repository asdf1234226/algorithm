// 给你一个整数数组 nums 和一个整数 k。
// 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
// 请返回这个数组中「优美子数组」的数目


// 输入：nums = [1,1,2,1,1], k = 3
// 输出：2
// 解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。

#include <iostream>
#include<vector>
#include<map>
using namespace std;



//类似lc560
int numberOfSubarrays(vector<int>& nums, int k){
    int n = nums.size();
    map<int,int> mp;
    mp[0]=1;
    int preSum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i]%2==1)
        {
            preSum++;
        }
        if (mp.find(preSum-k)!=mp.end())
        {
            count+=mp[preSum-k];
        }
        mp[preSum]++;
    }
    return count;
}

//为什么不能用滑窗
//满足某性质的滑窗，end每次+1，如果不满足性质,start++直到满足性质

//可以试试
int numberOfSubarrays1(vector<int>& nums, int k){
    int n = nums.size();
    int count = 0;
    int odd_in_window = 0;//滑动窗口中奇数个数
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (nums[end]%2==1)
        {
            odd_in_window++;
        } 
        while (odd_in_window>k)//直到满足条件
        {
            if (nums[start]%2==1)
            {
                odd_in_window--;
            }
            start++;
        }
        if (odd_in_window==k)
        {
            count++;
        } 
    }
    return count;
    
}

int main(){
    vector<int> a = {1,1,2,1,1};
    cout << numberOfSubarrays1(a,3);
    return 0;
}