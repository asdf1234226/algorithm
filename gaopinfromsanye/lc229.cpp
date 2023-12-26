//
// Created by SP on 2023/12/26.
//

//给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    //根据容次原理，最多两个超过n/3的元素
    int n = nums.size();
    int target1 = 0, count1 = 0;
    int target2 = 0, count2 = 0;
    //为什么不能target1=nums[0],count1=1; target2=nums[1];count2=1?
    //因为nums[0]和nums[1]可能相同，所以初始化都为0比较好
    for (int i = 0; i < n; ++i) {
        if (nums[i]==target1){//如果是第一个候选者
            count1++;
        }else if (nums[i]==target2){//如果是第二个候选者
            count2++;
        } else if (count1==0){//如果还没候选者 or 之前次数归0
            target1=nums[i];
            count1=1;
        } else if (count2==0){
            target2=nums[i];
            count2=1;
        } else{ //当前数和候选者都不同
            count1--;
            count2--;
        }
    }

    //验证阶段
    count1=0;count2=0;
    for(auto it: nums){
        if (it==target1){
            count1++;
        } else if (it==target2){
            count2++;
        }
    }
    vector<int> ans;
    if (count1>n/3) ans.push_back(target1);
    if (count2>n/3) ans.push_back(target2);
    return ans;
}

int main(){

}