//
// Created by SP on 2023/11/12.
//

// 返回到达 nums[n - 1] 的最小跳跃次数。
// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
// 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    //每次跳，选和下一跳加一起最远的， 比如当前nums[0]=2可以选nums[1]和nums[2]，
    //选nums[1]能到达的最远距离是1+3=4,选nums[2]能到达的最远距离是2+1=3,所以选nums[1]
    int i = 0;
    int step = 0;
    while (i<n)
    {
        int next = 0;//下一跳的下标
        int maxDis = 0;//当前所能到的最远距离
        for(int j = 1; j <= nums[i] && j+i < n; j++){
            if (maxDis<i+j+nums[i+j])
            {
                maxDis = i+j+nums[i+j];
                next = i+j;
            }
            if (next>=n-1)
            {
                return step;
            }
        }
        i = next;
        step++;
    }
    return -1;  
}

int main(){
    vector<int> a = {3,2,1};
    cout << jump(a);
    return 0;
}