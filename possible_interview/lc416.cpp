
// 示例 1：
// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 

#include<iostream>
#include<vector>
using namespace std;

//01背包的最大容量是否是nums总和的一半
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    for(auto it: nums){
        total+=it;
    }
    if(total%2==1) return false;
    int target = total>>1;
    vector<int> dp(target+1,0);
    for(int i=0;i<n;i++){
        for(int j= target;j>=nums[i];j--){//选不选
            dp[j]=max(dp[j-nums[i]]+nums[i], dp[j]);
        }
    }
    return dp[target]==target;
}

int main(){
    vector<int> a = {1,5,11,5};
    if (canPartition(a)){
        cout << "y";
    } else{
        cout << "no";
    }
    return 0;
}