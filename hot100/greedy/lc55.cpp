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
    //每次跳，选和下一跳加一起最远的， 比如当前nums[0]=2可以选nums[1]和nums[2]，
    //选nums[1]能到达的最远距离是1+3=4,选nums[2]能到达的最远距离是2+1=3,所以选nums[1]
    int i = 0;
    while (i<n)
    {
        int next = 0;//下一跳的下标
        int maxDis = 0;//当前所能到的最远距离
        for(int j = 1; j <= nums[i] && j+i < n; j++){//找下一跳的下标
            if (maxDis<i+j+nums[i+j])
            {
                maxDis = i+j+nums[i+j];
                next = i+j;
            }
            if (next>=n-1)
            {
                return true;
            }
        }
        i = next;
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