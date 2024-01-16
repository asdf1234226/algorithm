// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 示例 2:
// 输入: nums = [2,3,0,1,4]
// 输出: 2

#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1,0x3f3f3f3f);
    //dp[i]是到达i的最小步数，可以由j转移而来（0,...i-1），取最小的
    //j必须满足j可到达，并且能从j转移到i
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(dp[j]!=0x3f3f3f3f && j+nums[j]>=i){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){
    vector<int> a = {3,2,1};
    cout << jump(a);
    return 0;
}