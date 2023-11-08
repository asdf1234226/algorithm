//
// Created by SP on 2023/11/7.
//

//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int f[n];  //f[i]为以i为结尾的LIS长度
    memset(f,-1,sizeof f);
    for (int i = 0; i < n; i++)
    {
        f[i]=1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i]>nums[j])
            {
                f[i]=max(f[i],f[j]+1);//集合是找到i左边的j，使得nums[j]<nums[i]，这样长度就为f[j]+1
                //找到集合中最大的f[j]+1
            }
        }
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans=max(ans,f[i]);//最长LIS不一定以nums[n-1]结尾，所以要遍历i求所有f[i]最大值
    }
    return ans;
}

int main(){
    vector<int> a ={10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(a);
    return 0;
}