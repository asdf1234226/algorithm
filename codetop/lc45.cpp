// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 示例 2:
// 输入: nums = [2,3,0,1,4]
// 输出: 2

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//dp[i]是跳到下标i的最小步数， dp[i]=min(dp[j])+1, j的范围从0到i-1并且要满足,j+nums[j]>=i即能跳到
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j]!=INT_MAX && j+nums[j]>=i)
            {
                dp[i]=min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){
    vector<int> a = {2,3,1,1,4};
    cout << jump(a);
    return 0;
}