// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。 
//  子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变
//  其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列

//  输入：nums = [10,9,2,5,3,7,101,18] 输出：4 
//  解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

#include<iostream>
#include<vector>
using namespace std;

// 子序列，不连续
// dp[i]以下标i结尾的最长递增子序列长度
// dp[i]由dp[j]转移而来   j的取值范围0,1...i-1 并且nums[j]<nums[i]
int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    int ans =1;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;

}

int main(){
    vector<int> a ={10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(a);
    return 0;
}