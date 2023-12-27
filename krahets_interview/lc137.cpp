//
// Created by SP on 2023/12/14.
//

// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
// nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
// 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。

// 示例 1：
// 输入：nums = [2,2,3,2]
// 输出：3
// 示例 2：
// 输入：nums = [0,1,0,1,0,1,99]
// 输出：99

#include<iostream>
#include<vector>
using namespace std;

// 如下图所示，考虑数字的二进制形式，对于出现三次的数字，
// 各 **二进制位** 出现的次数都是 3 的倍数。 因此，统计所有数字的各二进制位
// 中 1 的出现次数，并对 3 求余，结果则为只出现一次的数字

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(32,0);
    for (int i = 0; i < 32; i++)
    {
        for(auto& num: nums){
            count[i]+=num&1;
            num >>= 1;
        }
    }
    int ans = 0;
    int t = 1;
    for (int i = 0; i < 32; i++)
    {
        //cout << count[i]<< " ";
        count[i]%=3;
        ans+=count[i]*t;
        t<<=1;
    }   
    return ans;
}

int main(){
    vector<int> a ={0,1,0,1,0,1,99};
    cout << singleNumber(a);
    return 0;
}