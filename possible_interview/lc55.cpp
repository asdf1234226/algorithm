// 示例 1：
// 输入：nums = [2,3,1,1,4]
// 输出：true
// 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
// 示例 2：
// 输入：nums = [3,2,1,0,4]
// 输出：false
// 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。


#include<iostream>
#include<vector>
using namespace std;
//贪心 
//动规
bool canJump(vector<int>& nums) {
    int cover = nums[0];//能覆盖的最大范围
    for(int i=1;i<=cover;i++){
        if (cover>=nums.size()-1) 
        {
            return true;
        }
        cover=max(cover,nums[i]+i);//cover是在每轮中不断更新的
    }
    return false;
}

bool canJump_1(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    //dp[i]表示i下标可以到达，由j转移而来，要满足dp[j]&&j+nums[j]>=i
    // j在0,...,i-1，并且只要有一个j满足就可
    for (int i = 1; i < n; i++)
    {
        for(int j=0;j<i;j++){
            if(dp[j] && j+nums[j]>=i){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n-1];
}
int main(){
    vector<int> a = {3,2,1,0,4};
    if (canJump(a))
    {
        cout << "y";
    }else
    {
        cout << "no";
    }
    return 0;
}