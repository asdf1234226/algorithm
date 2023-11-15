//
// Created by SP on 2023/11/12.
//

//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的

// 输入：nums = [2,3,2]
// 输出：3
// 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


//在198基础上加了首尾（start和end相邻）相连的限制条件
//选了start，end不能选, 返回dp[end-1]
//不选start，end选不选都行，返回dp[end]
int rob(vector<int>& nums) {
    if (nums.size()==1)
    {
        return nums[0];
    }
    if (nums.size()==2)
    {
        return max(nums[0], nums[1]);
    }
    
    int n = nums.size();
    int dp[n+1];
    memset(dp,0,sizeof dp);
    //1.选start
    dp[0]=nums[0];
    dp[1]=max(dp[0], nums[1]);
    for (int i = 2; i < n-1; i++)
    {
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    //结果是dp[n-2]
    int res_1 = dp[n-2];

    //2.不选start
    memset(dp,0,sizeof dp);
    dp[0]=0;
    dp[1]=nums[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    int res_2 = dp[n-1];
    return max(res_1, res_2);
}

int main(){
    vector<int> a = {2,3,2};
    cout << rob(a);
    return 0;
}