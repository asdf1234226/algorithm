//
// Created by SP on 2023/11/12.
//

// 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标

// 输入：nums = [2,3,1,1,4]
// 输出：true
// 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int cover = 0;//当前覆盖的最大范围,初始化0
    for (int i = 0; i <= cover; i++)
    {
        if(cover>=n-1) return true;
        cover = max(cover, i+nums[i]);
    }
    return false;
}

int main(){
    vector<int> a = {2,3,1,1,4};
    if (canJump(a))
    {
        cout << "y";
    }else
    {
        cout << "no";
    }
    return 0;

}