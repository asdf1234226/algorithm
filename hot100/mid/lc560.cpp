// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
// 子数组是数组中元素的连续非空序列。


//TODO 前缀和应该怎么写才优雅
#include<iostream>
#include<vector>
using namespace std;

//TODO 这种写法时间复杂度太高，和不用前缀和区别不大
//前缀和
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    vector<int> preSum(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        preSum[i]=preSum[i-1]+nums[i-1];//nums[i-1]是第i个数
    }
    for (int len = 1; len<=n; len++)//区间中点的个数
    {
        //从1开始是因为遍历的是前缀和数组
        for (int i = 1; i+len-1 <= n; i++)//满足(i+len-1)-i +1 = len
        {
            if (preSum[i+len-1]-preSum[i-1]==k)//左端点i，右端i+len-1，套用公式preSum[r]-preSum[l-1]
            {
                ans++;
            } 
        } 
    }
    return ans;
    
}

int main(){
    vector<int> a = {1,1,1};
    cout << subarraySum(a,2);
    return 0;
}