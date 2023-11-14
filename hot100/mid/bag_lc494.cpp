// 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
// 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

// 输入：nums: [1, 1, 1, 1, 1], S: 3
// 输出：5
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3



//a+b=sum; a-b=target;  a = (sum+target)/2
//变成0,1背包求方案数


#include<iostream> 
#include<vector> 
#include<cstring> 
using namespace std;

int findTargetSumWays(vector<int>& nums, int S)
{
    int n = nums.size();
    int sum = 0;
    for(auto it: nums){
        sum+=it;
    }
    // sum = 5, target = 4是无解的, 因为 a =(5+4)/2=4, a-b=target得b=0, 那么a+b=4(sum是5)
    if ((S+sum)%2==1)
    {
        return 0;
    }
    int target = (S+sum)/2;
    int dp[target+1];
    memset(dp,0,sizeof dp);
    //变成0,1背包求刚好装满的组合数
    dp[0]=1;
    for (int i = 0; i < n; i++)
    {
        for(int j = target; j>=nums[i]; j--){
            dp[j]=dp[j] + dp[j-nums[i]];//dp[j-nums[i]]是选nums[i]的方案数，dp[j]是不选的方案数
        }
    }
    return dp[target];
}

int main(){
    vector<int> a = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(a,3);
    return 0;
}